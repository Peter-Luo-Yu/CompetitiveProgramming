#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hw10.h"

isle_node_t *create_isle_node(char *name, char *leadership, biome_t biome, int pop) {
  assert(name != NULL);
  assert(leadership != NULL);
  assert(pop >= 0);
  assert(biome >= JAGGED_PEAKS && biome <= CRIMSON_FOREST);

  isle_node_t *node = malloc(sizeof(isle_node_t));
  assert(node != NULL);

  node->isle_name = malloc(strlen(name) + 1);
  assert(node->isle_name != NULL);
  strcpy(node->isle_name, name);

  node->leadership = malloc(strlen(leadership) + 1);
  assert(node->leadership != NULL);
  strcpy(node->leadership, leadership);

  node->isle_biome      = biome;
  node->population      = pop;
  node->parent_isle     = NULL;
  node->reachable_isles = NULL;
  node->sibling_isles   = NULL;
  node->dragon_list     = NULL;

  return node;
}

dragon_t *tame_dragon(char *name, char *species, char *rider, int shot_lim, int energy, int speed, isle_node_t *isle) {
  assert(name != NULL);
  assert(species != NULL);
  assert(rider != NULL);
  assert(shot_lim >= 0);
  assert(energy >= 0);
  assert(speed >= 0);
  assert(isle != NULL);

  dragon_t *dragon = malloc(sizeof(dragon_t));
  assert(dragon != NULL);

  dragon->name = malloc(strlen(name) + 1);
  assert(dragon->name != NULL);
  strcpy(dragon->name, name);

  dragon->species = malloc(strlen(species) + 1);
  assert(dragon->species != NULL);
  strcpy(dragon->species, species);

  dragon->rider_name = malloc(strlen(rider) + 1);
  assert(dragon->rider_name != NULL);
  strcpy(dragon->rider_name, rider);

  dragon->shot_lim    = shot_lim;
  dragon->energy      = energy;
  dragon->speed       = speed;
  dragon->next_dragon = NULL;

  // Insert sorted: energy descending, then name ascending on ties
  dragon_t **curr = &isle->dragon_list;
  while (*curr != NULL) {
    if ((*curr)->energy < dragon->energy) {
      break;
    }
    if ((*curr)->energy == dragon->energy &&
        strcmp((*curr)->name, dragon->name) > 0) {
      break;
    }
    curr = &(*curr)->next_dragon;
  }
  dragon->next_dragon = *curr;
  *curr = dragon;

  return dragon;
}

int insert_isle_node(isle_node_t *isle, isle_node_t *root, char *reachable_from) {
  assert(isle != NULL);
  assert(root != NULL);
  assert(reachable_from != NULL);

  if (strcmp(root->isle_name, reachable_from) == 0) {
    // Insert into children list sorted: leadership ascending, population descending on ties
    isle_node_t **curr = &root->reachable_isles;
    while (*curr != NULL) {
      int cmp = strcmp((*curr)->leadership, isle->leadership);
      if (cmp > 0) {
        break;
      }
      if (cmp == 0 && (*curr)->population < isle->population) {
        break;
      }
      curr = &(*curr)->sibling_isles;
    }
    isle->sibling_isles = *curr;
    isle->parent_isle   = root;
    *curr = isle;
    return OK;
  }

  // Recurse into children
  isle_node_t *child = root->reachable_isles;
  while (child != NULL) {
    int result = insert_isle_node(isle, child, reachable_from);
    if (result == OK) {
      return OK;
    }
    child = child->sibling_isles;
  }

  return NOT_FOUND;
}

// Recursive search helper for travel().
// Visits 'current' at depth 'steps_so_far'.
// Siblings of current are at the SAME depth (peer nodes, not one deeper).
// Children of current are at depth steps_so_far + 1.
static void travel_search(isle_node_t  *current,
                           isle_node_t  *start,
                           const char   *start_leadership,
                           biome_t       start_biome,
                           char          priority,
                           int           steps_so_far,
                           int           max_steps,
                           isle_node_t **best_isle,
                           int          *best_steps) {
  if (current == NULL || steps_so_far > max_steps) {
    return;
  }

  // Valid destination: same leadership and biome (including start isle's own population as baseline)
  if (strcmp(current->leadership, start_leadership) == 0 &&
      current->isle_biome == start_biome &&
      current != start) {

    int replace = 0;
    // Only replace if STRICTLY better (ties go to first found = starting isle)
    if (priority == 'H' && current->population > (*best_isle)->population) {
      replace = 1;
    } else if (priority == 'L' && current->population < (*best_isle)->population) {
      replace = 1;
    }

    if (replace) {
      *best_isle  = current;
      *best_steps = steps_so_far;
    }
  }

  // Traverse sibling_isles first (same step cost), then reachable_isles (one deeper)
  travel_search(current->sibling_isles, start, start_leadership, start_biome,
                priority, steps_so_far + 1, max_steps, best_isle, best_steps);

  travel_search(current->reachable_isles, start, start_leadership, start_biome,
                priority, steps_so_far + 1, max_steps, best_isle, best_steps);
}

int travel(dragon_t *dragon, isle_node_t *isle, char population_priority) {
  assert(dragon != NULL);
  assert(isle != NULL);
  assert(population_priority == 'H' || population_priority == 'L');

  int max_steps = dragon->energy * dragon->speed;

  // The starting isle is always "found first" — initialize best to start isle
  isle_node_t *best_isle  = isle;
  int          best_steps = 0;

  // Search siblings first, then children (traversal order per spec)
  travel_search(isle->sibling_isles, isle, isle->leadership, isle->isle_biome,
                population_priority, 1, max_steps, &best_isle, &best_steps);
  travel_search(isle->reachable_isles, isle, isle->leadership, isle->isle_biome,
                population_priority, 1, max_steps, &best_isle, &best_steps);

  // If best is still the starting isle (no strictly better destination found), NOT_POSSIBLE
  if (best_isle == isle) {
    return NOT_POSSIBLE;
  }

  // Deduct energy: -1 energy per 'speed' isles traveled (integer division)
  int energy_cost = best_steps / dragon->speed;
  dragon->energy -= energy_cost;

  // Remove dragon from current isle's list
  dragon_t **curr = &isle->dragon_list;
  while (*curr != NULL && *curr != dragon) {
    curr = &(*curr)->next_dragon;
  }
  if (*curr == dragon) {
    *curr = dragon->next_dragon;
  }

  // Insert into destination isle's list maintaining sort order
  dragon->next_dragon = NULL;
  dragon_t **ins = &best_isle->dragon_list;
  while (*ins != NULL) {
    if ((*ins)->energy < dragon->energy) {
      break;
    }
    if ((*ins)->energy == dragon->energy &&
        strcmp((*ins)->name, dragon->name) > 0) {
      break;
    }
    ins = &(*ins)->next_dragon;
  }
  dragon->next_dragon = *ins;
  *ins = dragon;

  return best_steps;
}

int habitat_assessment(biome_t biome, isle_node_t *isle) {
  assert(isle != NULL);
  assert(biome >= JAGGED_PEAKS && biome <= CRIMSON_FOREST);

  int count = 0;

  // Count dragons on this isle if biome matches
  if (isle->isle_biome == biome) {
    dragon_t *d = isle->dragon_list;
    while (d != NULL) {
      count++;
      d = d->next_dragon;
    }
  }

  // Recurse into children, then traverse siblings via the while loop
  isle_node_t *child = isle->reachable_isles;
  while (child != NULL) {
    count += habitat_assessment(biome, child);
    child = child->sibling_isles;
  }

  return count;
}

// Helper: check if species already exists in the ecosystem list
static int species_exists(dragon_t *list, const char *species) {
  while (list != NULL) {
    if (strcmp(list->species, species) == 0) {
      return 1;
    }
    list = list->next_dragon;
  }
  return 0;
}

// Helper: deep-copy a single dragon node (next_dragon set to NULL)
static dragon_t *copy_dragon(dragon_t *src) {
  dragon_t *d = malloc(sizeof(dragon_t));
  assert(d != NULL);

  d->name = malloc(strlen(src->name) + 1);
  assert(d->name != NULL);
  strcpy(d->name, src->name);

  d->species = malloc(strlen(src->species) + 1);
  assert(d->species != NULL);
  strcpy(d->species, src->species);

  d->rider_name = malloc(strlen(src->rider_name) + 1);
  assert(d->rider_name != NULL);
  strcpy(d->rider_name, src->rider_name);

  d->shot_lim    = src->shot_lim;
  d->energy      = src->energy;
  d->speed       = src->speed;
  d->next_dragon = NULL;

  return d;
}

// DFS traversal: current node, then sibling_isles, then reachable_isles.
// Per spec: check current, recurse siblings, recurse children.
static void ecosystem_dfs(isle_node_t *isle, biome_t biome,
                           dragon_t **head, dragon_t **tail) {
  if (isle == NULL) {
    return;
  }

  // Process this isle if biome matches
  if (isle->isle_biome == biome) {
    dragon_t *d = isle->dragon_list;
    while (d != NULL) {
      if (!species_exists(*head, d->species)) {
        dragon_t *copy = copy_dragon(d);
        if (*tail == NULL) {
          *head = copy;
          *tail = copy;
        } else {
          (*tail)->next_dragon = copy;
          *tail = copy;
        }
      }
      d = d->next_dragon;
    }
  }

  // Current -> sibling_isles -> reachable_isles
  ecosystem_dfs(isle->sibling_isles,   biome, head, tail);
  ecosystem_dfs(isle->reachable_isles, biome, head, tail);
}

dragon_t *dragonic_ecosystem(isle_node_t *isle, biome_t biome) {
  assert(isle != NULL);
  assert(biome >= JAGGED_PEAKS && biome <= CRIMSON_FOREST);

  dragon_t *head = NULL;
  dragon_t *tail = NULL;

  // Start DFS from isle itself (not its siblings — those are peers, not subtree)
  // Process isle, then its reachable_isles only (sibling handling is caller's job)
  if (isle->isle_biome == biome) {
    dragon_t *d = isle->dragon_list;
    while (d != NULL) {
      if (!species_exists(head, d->species)) {
        dragon_t *copy = copy_dragon(d);
        if (tail == NULL) {
          head = copy;
          tail = copy;
        } else {
          tail->next_dragon = copy;
          tail = copy;
        }
      }
      d = d->next_dragon;
    }
  }
  ecosystem_dfs(isle->reachable_isles, biome, &head, &tail);

  return head;
}

// Compute raid power for an isle: sum of (energy * speed * shot_lim) for dragons WITH riders
static int compute_power(isle_node_t *isle) {
  int power = 0;
  dragon_t *d = isle->dragon_list;
  while (d != NULL) {
    if (d->rider_name != NULL && strlen(d->rider_name) > 0) {
      power += d->energy * d->speed * d->shot_lim;
    }
    d = d->next_dragon;
  }
  return power;
}

// DFS raid helper.
// 'stopped' flag: set to 1 if battle lost (stop all traversal), 2 if NOT_POSSIBLE.
// Returns number of isles raided so far.
static int raid_dfs(isle_node_t *source, isle_node_t *current,
                    char **name_list, int max_names, int *name_idx, int *stopped) {
  if (current == NULL || *stopped) {
    return 0;
  }

  int total_raided = 0;

  // Only target isles with different leadership
  if (strcmp(current->leadership, source->leadership) != 0) {
    int attacker_power = compute_power(source);
    int defender_power = compute_power(current);

    if (attacker_power <= defender_power) {
      // Lost — stop entire raid
      *stopped = 1;
      return 0;
    }

    // Change leadership to match source
    free(current->leadership);
    current->leadership = malloc(strlen(source->leadership) + 1);
    assert(current->leadership != NULL);
    strcpy(current->leadership, source->leadership);

    // Reset human population
    current->population = 0;

    // Free all ridden dragons; collect unridden ones
    dragon_t *d = current->dragon_list;
    dragon_t *unridden_head = NULL;
    dragon_t *unridden_tail = NULL;

    while (d != NULL) {
      dragon_t *next = d->next_dragon;
      if (d->rider_name != NULL && strlen(d->rider_name) > 0) {
        free(d->name);
        free(d->species);
        free(d->rider_name);
        free(d);
      } else {
        d->next_dragon = NULL;
        if (unridden_tail == NULL) {
          unridden_head = d;
          unridden_tail = d;
        } else {
          unridden_tail->next_dragon = d;
          unridden_tail = d;
        }
      }
      d = next;
    }
    current->dragon_list = unridden_head;

    // Find highest-energy unridden dragon
    dragon_t *best = NULL;
    dragon_t *walker = current->dragon_list;
    while (walker != NULL) {
      if (best == NULL || walker->energy > best->energy) {
        best = walker;
      }
      walker = walker->next_dragon;
    }

    if (best != NULL) {
      // Need a name — check availability
      if (*name_idx >= max_names) {
        *stopped = 2;
        return 0;
      }

      free(best->rider_name);
      best->rider_name = malloc(strlen(name_list[*name_idx]) + 1);
      assert(best->rider_name != NULL);
      strcpy(best->rider_name, name_list[*name_idx]);
      (*name_idx)++;

      // Remove best from current's list
      dragon_t **rem = &current->dragon_list;
      while (*rem != NULL && *rem != best) {
        rem = &(*rem)->next_dragon;
      }
      if (*rem == best) {
        *rem = best->next_dragon;
      }
      best->next_dragon = NULL;

      // Insert best into source's dragon_list (sorted: energy desc, name asc on ties)
      dragon_t **ins = &source->dragon_list;
      while (*ins != NULL) {
        if ((*ins)->energy < best->energy) break;
        if ((*ins)->energy == best->energy &&
            strcmp((*ins)->name, best->name) > 0) break;
        ins = &(*ins)->next_dragon;
      }
      best->next_dragon = *ins;
      *ins = best;
    }

    total_raided++;
  }

  // Current -> sibling_isles -> reachable_isles
  total_raided += raid_dfs(source, current->sibling_isles,   name_list, max_names, name_idx, stopped);
  total_raided += raid_dfs(source, current->reachable_isles, name_list, max_names, name_idx, stopped);

  return total_raided;
}

int raid(isle_node_t *source_isle, char **name_list, int max_names) {
  assert(source_isle != NULL);
  assert(name_list != NULL);
  assert(max_names > 0);

  int name_idx = 0;
  int stopped  = 0;

  // Start DFS from source itself: current -> siblings -> children
  // Source itself is never a target (same leadership by definition at start)
  // so we go directly into its siblings then children
  int result = 0;
  result += raid_dfs(source_isle, source_isle->sibling_isles,   name_list, max_names, &name_idx, &stopped);
  if (stopped == 2) return NOT_POSSIBLE;
  result += raid_dfs(source_isle, source_isle->reachable_isles, name_list, max_names, &name_idx, &stopped);
  if (stopped == 2) return NOT_POSSIBLE;

  return result;
}

// Search the entire tree rooted at 'search_root' for any dragon with
// the given rider_name on an isle whose leadership differs from ref_leadership.
// DFS: reachable_isles first, then sibling_isles.
static int rider_on_different_isle(isle_node_t *search_root,
                                    const char  *rider_name,
                                    const char  *ref_leadership) {
  if (search_root == NULL) {
    return 0;
  }

  // Check this isle if leadership differs
  if (strcmp(search_root->leadership, ref_leadership) != 0) {
    dragon_t *d = search_root->dragon_list;
    while (d != NULL) {
      if (d->rider_name != NULL && strcmp(d->rider_name, rider_name) == 0) {
        return 1;
      }
      d = d->next_dragon;
    }
  }

  // Traverse sibling_isles first, then reachable_isles
  if (rider_on_different_isle(search_root->sibling_isles, rider_name, ref_leadership)) {
    return 1;
  }
  return rider_on_different_isle(search_root->reachable_isles, rider_name, ref_leadership);
}

// DFS over the whole tree; for each rider found, check if that rider also
// appears on another isle with different leadership. Stop at first match.
static char *dfs_find_agent(isle_node_t *current, isle_node_t *tree_root) {
  if (current == NULL) {
    return NULL;
  }

  // Check each rider on this isle
  dragon_t *d = current->dragon_list;
  while (d != NULL) {
    if (d->rider_name != NULL && strlen(d->rider_name) > 0) {
      if (rider_on_different_isle(tree_root, d->rider_name, current->leadership)) {
        return d->rider_name;
      }
    }
    d = d->next_dragon;
  }

  // Traverse sibling_isles first, then reachable_isles
  char *found = dfs_find_agent(current->sibling_isles, tree_root);
  if (found != NULL) {
    return found;
  }
  return dfs_find_agent(current->reachable_isles, tree_root);
}

char *find_double_agent(isle_node_t *root) {
  assert(root != NULL);
  return dfs_find_agent(root, root);
}

void free_dragons(char *species, isle_node_t *root) {
  assert(species != NULL);
  assert(root != NULL);

  // Remove all dragons of matching species from this isle's dragon_list
  dragon_t **curr = &root->dragon_list;
  while (*curr != NULL) {
    if (strcmp((*curr)->species, species) == 0) {
      dragon_t *to_free = *curr;
      *curr = to_free->next_dragon;   // relink before freeing
      free(to_free->name);
      free(to_free->species);
      free(to_free->rider_name);
      free(to_free);
    } else {
      curr = &(*curr)->next_dragon;
    }
  }

  // Recurse: children first, then siblings
  isle_node_t *child = root->reachable_isles;
  while (child != NULL) {
    free_dragons(species, child);
    child = child->sibling_isles;
  }
}

void torch(isle_node_t **isle) {
  assert(isle != NULL);
  assert(*isle != NULL);

  isle_node_t *node = *isle;

  // Recursively torch all children first
  isle_node_t *child = node->reachable_isles;
  while (child != NULL) {
    isle_node_t *next_sib = child->sibling_isles;
    // Temporarily isolate child so torch doesn't follow its sibling_isles
    child->sibling_isles = NULL;
    torch(&child);
    child = next_sib;
  }

  // Free all dragons on this isle
  dragon_t *d = node->dragon_list;
  while (d != NULL) {
    dragon_t *next = d->next_dragon;
    free(d->name);
    free(d->species);
    free(d->rider_name);
    free(d);
    d = next;
  }

  // Free the isle's own allocated fields
  free(node->isle_name);
  free(node->leadership);
  free(node);

  *isle = NULL;
}