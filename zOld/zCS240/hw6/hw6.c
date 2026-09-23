/*
 * Homework 6
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */


#include "hw6.h"

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
      printf("bad record 1aa \n");
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
      printf("bad record 1c \n");
      return BAD_RECORD;
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
    //printf("ROW: %d\n", rows);

    char name[MAX_NAME_SIZE] = {};
    char family[MAX_NAME_SIZE] = {};
    char buf[MAX_BUF_SIZE] = {};
    char vendetta[MAX_SECRET_SIZE] = {};
    int power = 0;
    char allies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE] = {};
    char enemies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE] = {};
    criminal_t cur = {};

    count1 = fscanf(fp, "%24[^$]$%24[^$]$%49[^$]$%d{", name, family, buf, &power);
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

    printcrim(cur);

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


/*
 * this function checks if a criminal has more power than his vendetta
 */

int can_pay_back(char *criminal_name) {
  
  assert(criminal_name != NULL);

  if (g_criminal_count == 0) {
    return NO_DATA;
  }

  int found = 0;
  criminal_t cur = {};
  int found_vendetta = 0;
  criminal_t vendetta = {};
  for (int i = 0; i < g_criminal_count; i++) {
    cur = g_criminal_array[i];
    if (strcmp(cur.name, criminal_name) == 0) {
      found = 1;
      break;
    }
  }
  if (found == 0) {
    printf("crim notfound\n");
    return NOT_FOUND;
  }
  //printf("vendetta: %s, size: %lu\n", cur.silent_vendetta, strlen(cur.silent_vendetta));
  for (int i = 0; i < g_criminal_count; i++) {
    vendetta = g_criminal_array[i];
    //printf("vendetta name: %s, size: %lu\n", vendetta.name, strlen(vendetta.name));
    if (strncmp(cur.silent_vendetta, vendetta.name, strlen(vendetta.name)) == 0) {
      found_vendetta = 1;
      break;
    }
  }

  if (found_vendetta == 0) {
    printf("vendetta notfound\n");
    return NOT_FOUND;
  }

  int cur_power = cur.power;
  int vendetta_power = vendetta.power;

  for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    if (cur.allies[i][0] != '\0') {
      for (int j = 0; j < g_criminal_count; j++) {
        criminal_t crim = g_criminal_array[j];

        if (strcmp(crim.name, cur.allies[i]) == 0) {
          cur_power += crim.power;
        }
      }
    }
    if (vendetta.allies[i][0] != '\0') {
      for (int j = 0; j < g_criminal_count; j++) {
        criminal_t crim = g_criminal_array[j];

        if (strcmp(crim.name, vendetta.allies[i]) == 0) {
          vendetta_power += crim.power;
        }
      }
    }
  }
  
  if (cur_power > vendetta_power) {
    return 1;
  }

  return 0;

} /* can_pay_back() */



/*
 * this function checks if a family has more power than the power of their enemies
 */

int in_great_danger(char *family_name) {
  assert(family_name != NULL);

  if (g_criminal_count == 0) {
    return NO_DATA;
  }

  int found_family = 0;
  int family_power = 0;
  int enemy_power = 0;

  int visited_ally[MAX_CRIMINALS] = {0};
  int visited_enemy[MAX_CRIMINALS] = {0};

  for (int i = 0; i < g_criminal_count; i++) {
    criminal_t crim = g_criminal_array[i];

    if (strcmp(crim.family, family_name) == 0) {
      found_family = 1;
      
      if (visited_ally[i] == 0) {
        family_power += crim.power;
        visited_ally[i] = 1;
      }
      

      for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
        if (crim.allies[j][0] != '\0') {

          for (int k = 0; k < g_criminal_count; k++) {
            if (visited_ally[k] == 1) {
              continue;
            }

            criminal_t friend = g_criminal_array[k];

            if (strcmp(crim.allies[j], friend.name) != 0) {
              continue;
            }

            int mutual_ally = 0;
            // check if ally is mutually friends with crim
            for (int l = 0; l < MAX_ARRAY_LENGTH; l++) {
              if (friend.allies[l][0] != '\0') {
                if (strcmp(friend.allies[l], crim.name) == 0) {
                  mutual_ally = 1;
                  break;
                }
              }
            }

            if (mutual_ally == 1) {
              family_power += friend.power;
              visited_ally[k] = 1;
            }
          }
        }


        if (crim.enemies[j][0] != '\0') {
          for (int k = 0; k < g_criminal_count; k++) {
            criminal_t enemy = g_criminal_array[k];
            if (strcmp(crim.enemies[j], enemy.name) != 0) {
              continue;
            }
            if (visited_enemy[k] == 1) {
              continue;
            }

            enemy_power += enemy.power;
            visited_enemy[k] = 1;
          }
        }
      }
    }
  }

  if (found_family == 0) {
    return NOT_FOUND;
  }
  if (family_power < enemy_power) {
    return 1;
  }

  return 0;

} /* in_great_danger() */


int main () {
  int x = read_criminals("input_9152.txt");
  int y = can_pay_back("Matthew King");

  printf("final return: %d", x);

}
  