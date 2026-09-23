/*
 * Homework 7
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw7.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int g_criminal_count = 0;
criminal_t g_criminal_array[MAX_CRIMINALS] = {};


void printcrim(criminal_t crim) {
    printf("Name: %s | Fam: %s | Ven: %s | POWER: %d\n", crim.name, crim.family, crim.silent_vendetta, crim.power);
    printf("Friends: ");
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
        if (crim.allies[i][0] == '\0') break;
        printf("%s - ", crim.allies[i]);
    } 
    printf("\nEnemies: ");
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
        if (crim.enemies[i][0] == '\0') break;
        printf("%s - ", crim.enemies[i]);
    }
    printf("\n");
}



/*
 * helper function that reads in a criminal's allies
 */

int read_allies(FILE *fp, char allies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE]) {
  
  int num_allies = 0;
  int count2 = 0;
  while (1) {
    char ally[MAX_NAME_SIZE] = {};
    char c = '\0';
    if (num_allies >= MAX_ARRAY_LENGTH) {
      printf("bad record 1a \n");
      return BAD_RECORD;
    }

    count2 = fscanf(fp, "%24[^,}]%c", ally, &c); 

    if (strlen(ally) >= MAX_NAME_SIZE) {
      printf("bad record 1a \n");
      return BAD_RECORD;
    }

    if (count2 == 2) {
      strcpy(allies[num_allies], ally);
      num_allies++;
      if (c == ',') {
        continue;
      }
      else if (c == '}') {
        break;
      } 
      else {
        printf("bad record 1b \n");
        return BAD_RECORD;
      }
    } 
    else {
      //printf("count2: %d\n ally: %s\n c: %c\n", count2, ally, c);
      //printf("bad record 1c \n");
      //return BAD_RECORD;
      fscanf(fp, "}");
      break;
    }
  }

  fscanf(fp, "$");

  return 0;

} /* read_allies() */

/*
 * helper function that reads a criminal's enemies
 */

int read_enemies(FILE *fp, char enemies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE]) {
  int num_enemies = 0;
  int count3 = 0; 
  while (1) {
    char enemy[MAX_NAME_SIZE] = {};
    char c = '\0';
    if (num_enemies >= MAX_ARRAY_LENGTH) {
      printf("bad record 2a \n");
      return BAD_RECORD;
    }

    count3 = fscanf(fp, "%24[^|\n]%c", enemy, &c);

    if (strlen(enemy) >= MAX_NAME_SIZE) {
      printf("bad record 2b \n");
      return BAD_RECORD;
    }

    if (count3 == 2) {
      strcpy(enemies[num_enemies], enemy);
      num_enemies++;
      if (c == '|') {
        continue;
      }
      else if (c == '\n') {
        break;
      } 
      else {
        printf("bad record 2c \n");
        return BAD_RECORD;
      }
    }
    else if (count3 == 1) {
      strcpy(enemies[num_enemies], enemy);
      num_enemies++;
      break;
    } 
    else {
      break;
    }

  }
  return 0;

} /* read_enemies() */


/*
 * helper function that checks for duplicate allies and 
 * if the criminal appears in his own alies and enemies list
 */

int check_bad() {
  int bad = 0;

  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t cur = g_criminal_array[i];

    //printcrim(cur);
    
    for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
      if (cur.allies[j][0] != '\0') {
        if (strcmp(cur.name, cur.allies[j]) == 0) {
          bad = 1;
        }
        for (int k = j + 1; k < MAX_ARRAY_LENGTH; k++) {
          if (cur.allies[k][0] != '\0') {
            if (strcmp(cur.allies[j], cur.allies[k]) == 0) {
              bad = 1;
            }
          }
        }
      }

      if (cur.enemies[j][0] != '\0') {
        if (strcmp(cur.name, cur.enemies[j]) == 0) {
          bad = 1;
        }
        for (int k = j + 1; k < MAX_ARRAY_LENGTH; k++) {
          if (cur.enemies[k][0] != '\0') {
            if (strcmp(cur.enemies[j], cur.enemies[k]) == 0) {
              bad = 1;
            }
          }
        }
      }
    }
  }
  
  if (bad == 1) {
    return BAD_RECORD;
  }
  return 0;

} /* check_bad() */


/*
 * helper function that checks all allies and enemies actually
 * have a row dedicated to them.
 */

int check_found() {

  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t cur = g_criminal_array[i];

    //printcrim(cur);
    
    for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
      if (cur.allies[j][0] != '\0') {
        int found_ally = 0;
        for (int k = 0; k < g_criminal_count; k++) {

          criminal_t crim = g_criminal_array[k];

          if (strcmp(crim.name, cur.allies[j]) == 0) {
            found_ally = 1;
          }
        }
        if (found_ally == 0) {
          return NOT_FOUND;
        }
      }

      if (cur.enemies[j][0] != '\0') {
        int found_enemy = 0;
        for (int k = 0; k < g_criminal_count; k++) {

          criminal_t crim = g_criminal_array[k];

          if (strcmp(crim.name, cur.enemies[j]) == 0) {
            found_enemy = 1;
          }
        }
        if (found_enemy == 0) {
          return NOT_FOUND;
        }
      }
    }
  }
  
  return 0;

} /* check_found() */


int find_criminal(criminal_t *criminal) {
  int found = 0;

  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t cur = g_criminal_array[i];

    if (strcmp(cur.name, criminal -> name) == 0) {
      found = 1;
      break;
    }
  }

  if (found == 1) {
    return 1;
  } 

  return 0;
}



/*
 * helper function that checks if there are duplicate criminals
 */

int check_duplicate() {
  int found_duplicate = 0;

  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t crim1 = g_criminal_array[i];
    for (int j = 0; j < g_criminal_count; j++) {
      if (i == j) {
        continue;
      }

      criminal_t crim2 = g_criminal_array[j];

      if (strcmp(crim1.name, crim2.name) == 0) {
        found_duplicate = 1;
      }
    }
  }

  if (found_duplicate == 1) {
    return DUPLICATE_NAMES;
  }
  return 0;

} /* check_duplicate() */


/*
 * the main read function that populates global vars from file data
 */

int read_criminals(char *file) {
  assert(file != NULL);
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    return FILE_READ_ERR;
  }   
  
  printf("file: %s ******************************************************\n", file);
  
  int count1 = 0;
  int rows = 0;
  while (1) {
    printf("ROW: %d\n", rows);

    char name[MAX_NAME_SIZE] = {};
    char family[MAX_NAME_SIZE] = {};
    char buf[MAX_BUF_SIZE] = {};
    char vendetta[MAX_SECRET_SIZE] = {};
    int power = 0;
    char allies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE] = {};
    char enemies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE] = {};
    criminal_t cur = {};

    count1 = fscanf(fp, " %24[^$]$%24[^$]$%49[^$]$%d{", name, family, buf, &power);
    if (count1 == EOF) {
      break;
    }
    if (count1 != 4) {
      //printf("bad record 1 \n");
      fclose(fp);
      fp = NULL;
      return BAD_RECORD;
    } 

    //printf("%s | %s | %s | %d |\n", name, family, buf, power);

    int count2 = read_allies(fp, allies);
    int count3 = read_enemies(fp, enemies);

    if ((strlen(name) >= MAX_NAME_SIZE) || (strlen(family) >= MAX_NAME_SIZE) ||
        (strlen(buf) >= MAX_BUF_SIZE) || (power < 0) || 
        (count2 == BAD_RECORD) || (count3 == BAD_RECORD)) {
      fclose(fp);
      fp = NULL;
      printf("BAD RECORD 6\n");
      return BAD_RECORD;
    }

    strncpy(vendetta, buf, sizeof(vendetta));
    vendetta[sizeof(vendetta) - 1] = '\0';
    strcpy(cur.name, name);
    strcpy(cur.family, family);
    strcpy(cur.silent_vendetta, vendetta);
    cur.power = power;
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
      if (allies[i][0] != '\0') {
        strcpy(cur.allies[i], allies[i]);
      }
      if (enemies[i][0] != '\0') {
        strcpy(cur.enemies[i], enemies[i]);
      }
    }
    g_criminal_array[rows] = cur;
    rows++;

    //printcrim(cur);

    if (rows >= MAX_CRIMINALS) {
      //printf("TOO MUCH DATA\n");
      fclose(fp);
      return TOO_MUCH_DATA;
    }
  }

  g_criminal_count = rows;
  fclose(fp);
  fp = NULL;
  if (rows == 0) {
    return NO_DATA;
  }
  if (check_bad() == BAD_RECORD) {
    //printf("Bad record\n");
    return BAD_RECORD;
  }
  if (check_duplicate() == DUPLICATE_NAMES) {
    //printf("Duplicate name\n");
    return DUPLICATE_NAMES;
  }
  if (check_found() == NOT_FOUND) {
    //printf("Not found\n");
    return NOT_FOUND;
  }
  
  //printf("RETURN ROWS: %d\n", rows);
  return rows;

} /* read_criminals() */


int connect_criminals() {
  if (g_criminal_count == 0) {
    return NO_DATA;
  }
  if (check_found() == NOT_FOUND) {
    return NOT_FOUND;
  }
  
  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t cur = g_criminal_array[i];
    criminal_t ally = {};
    criminal_t enemy = {};

    for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
      if (cur.allies[j][0] == '\0') {
        cur.ally_ptrs[i] = NULL;
      } else {
        for (int k = 0; k < g_criminal_count; k++) {
          if (i == k) {
            continue;
          }
          ally = g_criminal_array[k];
          if (strcmp(cur.allies[j], ally.name) == 0) {
            break;
          }
        }

        cur.ally_ptrs[i] = &ally;
      }

      if (cur.enemies[j][0] == '\0') {
        cur.enemy_ptrs[i] = NULL;
      } else {
        for (int k = 0; k < g_criminal_count; k++) {
          if (i == k) {
            continue;
          }
          enemy = g_criminal_array[k];
          if (strcmp(cur.enemies[j], enemy.name) == 0) {
            break;
          }
        }

        cur.enemy_ptrs[i] = &enemy;
      }
    }
  }

  return SUCCESS;
}

int identify_mole(criminal_t *criminal) {
  assert(criminal != NULL);
  if (g_criminal_count == 0) {
    return NO_DATA;
  }
  if (find_criminal(criminal) == 0) {
    return NOT_FOUND;
  }
  
  printf("LOOKING FOR: %s\n", criminal->name);

  int moles = 0;

  for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    if (criminal->ally_ptrs[i] == NULL) {
      continue;
    }

    criminal_t ally = *criminal->ally_ptrs[i];
    
    printf("%s(%lu)|%s(%lu)|\n", criminal->name, strlen(criminal->name), ally.silent_vendetta, strlen(ally.silent_vendetta));

    if (strncmp(ally.silent_vendetta, criminal->name, strlen(criminal->name)) == 0) {
      moles++;
    }
  }

  printf("moles %d\n", moles);

  return moles;
}

int find_common_enemies(criminal_t *criminal1, criminal_t *criminal2) {
  assert(criminal1 != NULL && criminal2 != NULL);
  if (g_criminal_count == 0) {
    return NO_DATA;
  }
  if (((find_criminal(criminal1) == 0) || (find_criminal(criminal2) == 0))) {
    return NOT_FOUND;
  }

  int vis1[MAX_CRIMINALS] = {0};
  int vis2[MAX_CRIMINALS] = {0};

  for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    if (criminal1->enemies[i] == NULL) {
      continue;
    }

    for (int j = 0; j < g_criminal_count; j++) {
      criminal_t enemy = g_criminal_array[j];

      if (strcmp(enemy.name, criminal1->enemies[i]) == 0) {
        vis1[j] = 1;
      }
    }
  }
  for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    if (criminal2->enemies[i] == NULL) {
      continue;
    }

    for (int j = 0; j < g_criminal_count; j++) {
      criminal_t enemy = g_criminal_array[j];

      if (strcmp(enemy.name, criminal2->enemies[i]) == 0) {
        vis2[j] = 1;
      }
    }
  }

  int num_common_enemies = 0;
  for (int i = 0; i < MAX_CRIMINALS; i++) {
    if (vis1[i] == 1 && vis2[i] == 1) {
      num_common_enemies++;
    }
  }

  return num_common_enemies;
}

int ally_path_length(criminal_t *criminal) {
  assert(criminal != NULL);
  if (g_criminal_count == 0) {
    printf("NO DATA\n");
    return NO_DATA;
  }
  if (find_criminal(criminal) == 0) {
    printf("NOT FOUND\n");
    return NOT_FOUND;
  }

  int vis[MAX_CRIMINALS] = {0};

  int length = 1;

  criminal_t *cur = criminal;

  while (cur != NULL) {
    printf("start: %s\n", cur->name);

    int idx = 0;
    for (int i = 0; i < g_criminal_count; i++) {
      criminal_t temp = g_criminal_array[i];
      if (strcmp(cur->name, temp.name) == 0) {
        idx = i;
        break;
      }
    }

    if (vis[idx] == 1) {
      printf("Cycle\n");
      return PATH_IS_CYCLE;
    } 

    vis[idx] = 1;
    

    int max_power = -1;
    criminal_t *next = NULL;

    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
      if (cur->ally_ptrs[i] == NULL) {
        continue;
      }
      if (cur->ally_ptrs[i]->power > max_power) {
        max_power = cur->ally_ptrs[i]->power;
        next = cur->ally_ptrs[i];
      }
    }

    if (next == NULL) {
      break;
    }

    printf("next: %s\n", next->name);


    printf("len: %d\n", length);
  
    cur = next;
    length++;
    
  }

  printf("return len: %d\n", length);

  return length;
}

int weak_links(criminal_t *criminal) {
  assert(criminal != NULL);
  if (g_criminal_count == 0) {
    return NO_DATA;
  }
  if (find_criminal(criminal) == 0) {
    return NOT_FOUND;
  }

  int vis[MAX_CRIMINALS] = {0};

  int num_weak = 0;
  criminal_t *cur = criminal;

  
  criminal_t vendetta = {};
  for (int i = 0; i < g_criminal_count; i++) {
    if (strncmp(g_criminal_array[i].name, criminal->silent_vendetta, 
        strlen(g_criminal_array[i].name)) == 0) {
      vendetta = g_criminal_array[i];
      break;
    }
  }

  int enemy_power = vendetta.power;
  for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    if (vendetta.ally_ptrs[i] == NULL) {
      continue;
    }
    enemy_power += vendetta.ally_ptrs[i]->power;
  }

  printf("%s | vendetta power: %d\n", vendetta.name, vendetta.power);

  while (cur != NULL) {
    printf("start: %s\n", cur->name);

    int idx = 0;
    for (int i = 0; i < g_criminal_count; i++) {
      criminal_t temp = g_criminal_array[i];
      if (strcmp(cur->name, temp.name) == 0) {
        idx = i;
        break;
      }
    }

    if (vis[idx] == 1) {
      printf("Cycle\n");
      return PATH_IS_CYCLE;
    } 

    vis[idx] = 1;
    

    int ally_power = cur->power;
    criminal_t *next = NULL;
    int min_power = 1e9;

    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
      if (cur->ally_ptrs[i] == NULL) {
        continue;
      }
      ally_power += cur->ally_ptrs[i]->power;

      if (cur->ally_ptrs[i]->power < min_power) {
        min_power = cur->ally_ptrs[i]->power;
        next = cur->ally_ptrs[i];
      }
    }

    if (ally_power < enemy_power) {
      num_weak++;
    }

    if (next == NULL) {
      break;
    }
    printf("next: %s\n", next->name);
    cur = next;
    
  }

  printf("final weak: %d\n", num_weak);

  return num_weak;
}


int main () {
  int x = read_criminals("input_6541.txt");

  printf("final return: %d", x);

}