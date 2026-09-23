#include "hw10.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Allocates and initializes a new isle node.
 */

isle_node_t *create_isle_node(char *name, char *leadership, biome_t biome,
                              int pop) {
  assert(name != NULL);
  assert(leadership != NULL);
  assert(pop >= 0);
  assert((biome >= JAGGED_PEAKS) && (biome <= CRIMSON_FOREST));

  isle_node_t *node = malloc(sizeof(isle_node_t));
  assert(node != NULL);

  node->isle_name = malloc(strlen(name) + 1);
  assert(node->isle_name != NULL);
  strcpy(node->isle_name, name);

  node->leadership = malloc(strlen(leadership) + 1);
  assert(node->leadership != NULL);
  strcpy(node->leadership, leadership);

  node->isle_biome = biome;
  node->population = pop;
  node->parent_isle = NULL;
  node->reachable_isles = NULL;
  node->sibling_isles = NULL;
  node->dragon_list = NULL;

  return node;
} /* create_isle_node() */

/*
 * Creates and inserts a dragon into an isle's list in sorted order.
 */

dragon_t *tame_dragon(char *name, char *species, char *rider, int shot_lim,
                      int energy, int speed, isle_node_t *isle) {
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

  dragon->shot_lim = shot_lim;
  dragon->energy = energy;
  dragon->speed = speed;
  dragon->next_dragon = NULL;

  dragon_t **curr = &isle->dragon_list;
  while (*curr != NULL) {
    if ((*curr)->energy < dragon->energy) {
      break;
    }
    if (((*curr)->energy == dragon->energy) &&
        (strcmp((*curr)->name, dragon->name) > 0)) {
      break;
    }
    curr = &(*curr)->next_dragon;
  }
  dragon->next_dragon = *curr;
  *curr = dragon;

  return dragon;
} /* tame_dragon() */

/*
 * Inserts an isle into the tree under a specified parent.
 */

int insert_isle_node(isle_node_t *isle, isle_node_t *root,
                     char *reachable_from) {
  assert(isle != NULL);
  assert(root != NULL);
  assert(reachable_from != NULL);

  if (strcmp(root->isle_name, reachable_from) == 0) {
    isle_node_t **curr = &root->reachable_isles;
    while (*curr != NULL) {
      int cmp = strcmp((*curr)->leadership, isle->leadership);
      if (cmp > 0) {
        break;
      }
      if ((cmp == 0) && ((*curr)->population < isle->population)) {
        break;
      }
      curr = &(*curr)->sibling_isles;
    }
    isle->sibling_isles = *curr;
    isle->parent_isle = root;
    *curr = isle;
    return OK;
  }

  isle_node_t *child = root->reachable_isles;
  while (child != NULL) {
    int result = insert_isle_node(isle, child, reachable_from);
    if (result == OK) {
      return OK;
    }
    child = child->sibling_isles;
  }

  return NOT_FOUND;
} /* insert_isle_node() */

/*
 * DFS helper to search for optimal travel destination.
 */

static void travel_search(isle_node_t *current, isle_node_t *start,
                          const char *start_leadership, biome_t start_biome,
                          char priority, int steps_so_far, int max_steps,
                          isle_node_t **best_isle, int *best_steps) {
  if ((current == NULL) || (steps_so_far > max_steps)) {
    return;
  }

  if ((strcmp(current->leadership, start_leadership) == 0) &&
      (current->isle_biome == start_biome) && (current != start)) {
    int replace = 0;
    if ((priority == 'H') && (current->population > (*best_isle)->population)) {
      replace = 1;
    } else if ((priority == 'L') &&
               (current->population < (*best_isle)->population)) {
      replace = 1;
    }

    if (replace) {
      *best_isle = current;
      *best_steps = steps_so_far;
    }
  }

  travel_search(current->sibling_isles, start, start_leadership, start_biome,
                priority, steps_so_far + 1, max_steps, best_isle, best_steps);
  travel_search(current->reachable_isles, start, start_leadership, start_biome,
                priority, steps_so_far + 1, max_steps, best_isle, best_steps);
} /* travel_search() */

/*
 * Moves a dragon to the best reachable isle based on population priority.
 */

int travel(dragon_t *dragon, isle_node_t *isle, char population_priority) {
  assert(dragon != NULL);
  assert(isle != NULL);
  assert((population_priority == 'H') || (population_priority == 'L'));

  int max_steps = dragon->energy * dragon->speed;
  isle_node_t *best_isle = isle;
  int best_steps = 0;

  travel_search(isle->sibling_isles, isle, isle->leadership, isle->isle_biome,
                population_priority, 1, max_steps, &best_isle, &best_steps);
  travel_search(isle->reachable_isles, isle, isle->leadership, isle->isle_biome,
                population_priority, 1, max_steps, &best_isle, &best_steps);

  if (best_isle == isle) {
    return NOT_POSSIBLE;
  }

  int energy_cost = best_steps / dragon->speed;
  dragon->energy -= energy_cost;

  dragon_t **curr = &isle->dragon_list;
  while ((*curr != NULL) && (*curr != dragon)) {
    curr = &(*curr)->next_dragon;
  }
  if (*curr == dragon) {
    *curr = dragon->next_dragon;
  }

  dragon->next_dragon = NULL;
  dragon_t **ins = &best_isle->dragon_list;
  while (*ins != NULL) {
    if ((*ins)->energy < dragon->energy) {
      break;
    }
    if (((*ins)->energy == dragon->energy) &&
        (strcmp((*ins)->name, dragon->name) > 0)) {
      break;
    }
    ins = &(*ins)->next_dragon;
  }
  dragon->next_dragon = *ins;
  *ins = dragon;

  return best_steps;
} /* travel() */

/*
 * Counts dragons in all isles matching a given biome.
 */

int habitat_assessment(biome_t biome, isle_node_t *isle) {
  assert(isle != NULL);
  assert((biome >= JAGGED_PEAKS) && (biome <= CRIMSON_FOREST));

  int count = 0;

  if (isle->isle_biome == biome) {
    dragon_t *d = isle->dragon_list;
    while (d != NULL) {
      count++;
      d = d->next_dragon;
    }
  }

  isle_node_t *child = isle->reachable_isles;
  while (child != NULL) {
    count += habitat_assessment(biome, child);
    child = child->sibling_isles;
  }

  return count;
} /* habitat_assessment() */

/*
 * Checks if a species already exists in a list.
 */

static int species_exists(dragon_t *list, const char *species) {
  while (list != NULL) {
    if (strcmp(list->species, species) == 0) {
      return 1;
    }
    list = list->next_dragon;
  }
  return 0;
} /* species_exists() */

/*
 * Creates a deep copy of a dragon node.
 */

static dragon_t *copy_dragon(dragon_t *src) {
  dragon_t *d = malloc(sizeof(dragon_t));
  assert(d != NULL);

  d->name = malloc(strlen(src->name) + 1);
  d->species = malloc(strlen(src->species) + 1);
  d->rider_name = malloc(strlen(src->rider_name) + 1);

  strcpy(d->name, src->name);
  strcpy(d->species, src->species);
  strcpy(d->rider_name, src->rider_name);

  d->shot_lim = src->shot_lim;
  d->energy = src->energy;
  d->speed = src->speed;
  d->next_dragon = NULL;

  return d;
} /* copy_dragon() */

/*
 * DFS to build a list of unique dragon species in a biome.
 */

static void ecosystem_dfs(isle_node_t *isle, biome_t biome, dragon_t **head,
                          dragon_t **tail) {
  if (isle == NULL) {
    return;
  }

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

  ecosystem_dfs(isle->reachable_isles, biome, head, tail);
  ecosystem_dfs(isle->sibling_isles, biome, head, tail);
} /* ecosystem_dfs() */

/*
 * Returns a list of unique dragon species for a biome.
 */

dragon_t *dragonic_ecosystem(isle_node_t *isle, biome_t biome) {
  assert(isle != NULL);
  assert((biome >= JAGGED_PEAKS) && (biome <= CRIMSON_FOREST));

  dragon_t *head = NULL;
  dragon_t *tail = NULL;

  ecosystem_dfs(isle, biome, &head, &tail);
  return head;
} /* dragonic_ecosystem() */

/*
 * Computes total combat power of dragons with riders on an isle.
 */

static int compute_power(isle_node_t *isle) {
  int power = 0;
  dragon_t *d = isle->dragon_list;
  while (d != NULL) {
    if ((d->rider_name != NULL) && (strlen(d->rider_name) > 0)) {
      power += d->energy * d->speed * d->shot_lim;
    }
    d = d->next_dragon;
  }
  return power;
} /* compute_power() */

/*
 * DFS helper to perform raids and count conquered isles.
 */

static int raid_dfs(isle_node_t *source, isle_node_t *current, char **name_list,
                    int max_names, int *name_idx, int *stopped) {
  if ((current == NULL) || (*stopped)) {
    return 0;
  }

  int total_raided = 0;
  if (strcmp(current->leadership, source->leadership) != 0) {
    int attacker_power = compute_power(source);
    int defender_power = compute_power(current);

    if (attacker_power <= defender_power) {
      *stopped = 1;
      return 0;
    }

    free(current->leadership);
    current->leadership = malloc(strlen(source->leadership) + 1);
    strcpy(current->leadership, source->leadership);
    current->population = 0;

    dragon_t *d = current->dragon_list;
    dragon_t *unridden_head = NULL;
    dragon_t *unridden_tail = NULL;

    while (d != NULL) {
      dragon_t *next = d->next_dragon;
      if ((d->rider_name != NULL) && (strlen(d->rider_name) > 0)) {
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

    dragon_t *best = NULL;
    for (dragon_t *w = current->dragon_list; w != NULL; w = w->next_dragon) {
      if ((best == NULL) || (w->energy > best->energy)) {
        best = w;
      }
    }

    if (best != NULL) {
      if (*name_idx >= max_names) {
        *stopped = 2;
        return 0;
      }

      free(best->rider_name);
      best->rider_name = malloc(strlen(name_list[*name_idx]) + 1);
      strcpy(best->rider_name, name_list[*name_idx]);
      (*name_idx)++;

      dragon_t **rem = &current->dragon_list;
      while (*rem && (*rem != best)) {
        rem = &(*rem)->next_dragon;
      }
      if (*rem) {
        *rem = best->next_dragon;
      }

      best->next_dragon = NULL;
      dragon_t **ins = &source->dragon_list;
      while (*ins) {
        if ((*ins)->energy < best->energy) {
          break;
        }
        if (((*ins)->energy == best->energy) &&
            (strcmp((*ins)->name, best->name) > 0)) {
          break;
        }
        ins = &(*ins)->next_dragon;
      }
      best->next_dragon = *ins;
      *ins = best;
    }
    total_raided++;
  }

  total_raided += raid_dfs(source, current->reachable_isles, name_list,
                           max_names, name_idx, stopped);
  if (*stopped) {
    return total_raided;
  }

  total_raided += raid_dfs(source, current->sibling_isles, name_list,
                           max_names, name_idx, stopped);

  return total_raided;
} /* raid_dfs() */

/*
 * Performs a raid starting from a source isle using DFS.
 */

int raid(isle_node_t *source_isle, char **name_list, int max_names) {
  assert(source_isle != NULL);
  assert(name_list != NULL);
  assert(max_names > 0);

  int name_idx = 0;
  int stopped = 0;
  int result = 0;

  result += raid_dfs(source_isle, source_isle->reachable_isles, name_list,
                     max_names, &name_idx, &stopped);
  if (stopped == 2) {
    return NOT_POSSIBLE;
  }
  if (stopped) {
    return result;
  }

  result += raid_dfs(source_isle, source_isle->sibling_isles, name_list,
                     max_names, &name_idx, &stopped);
  if (stopped == 2) {
    return NOT_POSSIBLE;
  }

  return result;
} /* raid() */

/*
 * Checks if a rider appears under different leadership elsewhere.
 */

static int rider_on_different_isle(isle_node_t *search_root,
                                   const char *rider_name,
                                   const char *ref_leadership) {
  if (search_root == NULL) {
    return 0;
  }

  if (strcmp(search_root->leadership, ref_leadership) != 0) {
    for (dragon_t *d = search_root->dragon_list; d; d = d->next_dragon) {
      if (d->rider_name && (strcmp(d->rider_name, rider_name) == 0)) {
        return 1;
      }
    }
  }

  if (rider_on_different_isle(search_root->reachable_isles, rider_name,
                              ref_leadership)) {
    return 1;
  }
  return rider_on_different_isle(search_root->sibling_isles, rider_name,
                                 ref_leadership);
} /* rider_on_different_isle() */

/*
 * DFS to find first rider acting as a double agent.
 */

static char *dfs_find_agent(isle_node_t *current, isle_node_t *tree_root) {
  if (current == NULL) {
    return NULL;
  }

  for (dragon_t *d = current->dragon_list; d; d = d->next_dragon) {
    if (d->rider_name && (strlen(d->rider_name) > 0)) {
      if (rider_on_different_isle(tree_root, d->rider_name,
                                  current->leadership)) {
        return d->rider_name;
      }
    }
  }

  char *found = dfs_find_agent(current->reachable_isles, tree_root);
  if (found) {
    return found;
  }

  return dfs_find_agent(current->sibling_isles, tree_root);
} /* dfs_find_agent() */

/*
 * Returns name of a rider found under conflicting leadership.
 */

char *find_double_agent(isle_node_t *root) {
  assert(root != NULL);
  return dfs_find_agent(root, root);
} /* find_double_agent() */

/*
 * Frees all dragons of a given species from the isle tree.
 */

void free_dragons(char *species, isle_node_t *root) {
  assert(species != NULL);
  assert(root != NULL);

  dragon_t **curr = &root->dragon_list;
  while (*curr != NULL) {
    if (strcmp((*curr)->species, species) == 0) {
      dragon_t *to_free = *curr;
      *curr = to_free->next_dragon;
      free(to_free->name);
      free(to_free->species);
      free(to_free->rider_name);
      free(to_free);
    } else {
      curr = &(*curr)->next_dragon;
    }
  }

  isle_node_t *child = root->reachable_isles;
  while (child != NULL) {
    free_dragons(species, child);
    child = child->sibling_isles;
  }
} /* free_dragons() */

/*
 * Recursively frees an entire isle tree and its dragons.
 */

void torch(isle_node_t **isle) {
  assert(isle != NULL);
  assert(*isle != NULL);

  isle_node_t *node = *isle;

  isle_node_t *child = node->reachable_isles;
  while (child != NULL) {
    isle_node_t *next_sib = child->sibling_isles;
    child->sibling_isles = NULL;
    torch(&child);
    child = next_sib;
  }

  dragon_t *d = node->dragon_list;
  while (d != NULL) {
    dragon_t *next = d->next_dragon;
    free(d->name);
    free(d->species);
    free(d->rider_name);
    free(d);
    d = next;
  }

  free(node->isle_name);
  free(node->leadership);
  free(node);

  *isle = NULL;
} /* torch() */