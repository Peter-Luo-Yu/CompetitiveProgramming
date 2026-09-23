/*
 * Homework 6
 * Your Name
 * CS 240, Spring 2026
 * Purdue University
 */

/* Write your code here */

#include "hw6.h"

#include<assert.h>
#include<stdio.h>
#include<string.h>

int g_criminal_count = 0;
criminal_t g_criminal_array[MAX_CRIMINALS] = {};

void printcrim(criminal_t crim) {
    printf("Name: %s | Fam: %s | Ven: %s | POWER: %d\n", crim.name, crim.family, crim.silent_vendetta, crim.power);
    printf("Friends: ");
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
        if (crim.allies[i][0] == '\0') break;
        printf("%s - ", crim.allies[i]);
    } 
    printf("\nEnemis: ");
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
        if (crim.enemies[i][0] == '\0') break;
        printf("%s - ", crim.enemies[i]);
    }
    printf("\n");
}

int check_found() {
  int failed = 0;
  for (int i = 0; i < MAX_CRIMINALS; i++) {
    criminal_t criminal = g_criminal_array[i];
    if (criminal.name[0] == '\0') {
      continue;
    }

    for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
      if (criminal.allies[j][0] == '\0') {
        break;
      } 
      int found = 0;

      for (int k = 0; k < MAX_CRIMINALS; k++) {
        criminal_t cur = g_criminal_array[k];
        if (cur.name[0] == '\0') {
          continue;
        }

        if (strcmp(criminal.allies[j], cur.name) == 0) {
          found = 1;
        }
      }
      
      if (found == 0) {
        failed = 1;
      }
    } 

    for (int j = 0; j < MAX_ARRAY_LENGTH; j++) {
      if (criminal.enemies[j][0] == '\0') {
        break;
      } 
      int found = 0;

      for (int k = 0; k < MAX_CRIMINALS; k++) {
        criminal_t cur = g_criminal_array[k];
        if (cur.name[0] == '\0') {
          continue;
        }

        if (strcmp(criminal.enemies[j], cur.name) == 0) {
          found = 1;
        }
      }

      if (found == 0) {
        failed = 1;
      }
    } 
  }

  if (failed) {
    return NOT_FOUND;
  } else {
    return 0;
  }
}

int check_duplicates() {
  int failed = 0;
  for (int i = 0; i < MAX_CRIMINALS; i++) {
    criminal_t criminal = g_criminal_array[i];
    if (criminal.name[0] == '\0') {
      continue;
    }

    for (int j = i + 1; j < MAX_CRIMINALS; j++) {
      criminal_t other = g_criminal_array[j];
      if (other.name[0] == '\0') {
        continue;
      }
      
      if ((strcmp(criminal.name, other.name) == 0)) {
        failed = 1;
      }
    }
  }
  if (failed == 1) {
    return DUPLICATE_NAMES;
  } else {
    return 0;
  }
}


int read_criminals(char *file) {
  assert(file != NULL);
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
      return FILE_READ_ERR;
  }    
  printf("file: %s---------------------------------------------\n", file);
  int count = 0;
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
    char temp1[MAX_ARRAY_LENGTH * MAX_NAME_SIZE] = {};
    char temp2[MAX_ARRAY_LENGTH * MAX_NAME_SIZE] = {};
    criminal_t cur = {};
    count = fscanf(fp, "%24[^$]$%24[^$]$%49[^$]$%d{%499[^}]}$%499s", name, family, buf, &power, temp1, temp2);
    printf("%s | %s | %s | %d | %s | %s\n", name, family, buf, power, temp1, temp2);
    if (count == EOF) {
      break;
    }
    if (count != 6) {
      fclose(fp);
      printf("BAD_RECORD 1 | count: %d\n", count);
      return BAD_RECORD;
    }
    rows++;
    if (rows >= MAX_CRIMINALS) {
      printf("TOO MUCH DATA\n");
      fclose(fp);
      return TOO_MUCH_DATA;
    }
    int num_allies = 0;
    int num_enemies = 0;
    int prev = 0;
    printf("temp1: %s \ntemp2: %s \n\n", temp1, temp2);
    for (int i = 0; i < sizeof(temp1); i++) {
      if (temp1[i] == ',' || temp1[i] == '\0') {
        if (i - prev >= MAX_NAME_SIZE || i - prev == 0 || 
            num_allies >= MAX_ARRAY_LENGTH) {
          fclose(fp);
          printf("BAD_RECORD 2\n");
          return BAD_RECORD;
        }
        char ally[MAX_NAME_SIZE] = {};
        for (int j = 0; j < i - prev; j++) {
          ally[j] = temp1[prev + j];
        }
        prev = i + 1;
        strcpy(allies[num_allies], ally);
        num_allies++;
        if (temp1[i] == '\0') {
          break;
        }
      }
    }
    prev = 0;
    for (int i = 0; i < sizeof(temp2); i++) {
      if (temp2[i] == '|' || temp2[i] == '\0') {
        if (i - prev >= MAX_NAME_SIZE || i - prev == 0||
            num_enemies >= MAX_ARRAY_LENGTH) {
          fclose(fp);
          printf("BAD_RECORD 3, row: %d", rows);
          return BAD_RECORD;
        }
        char enemy[MAX_NAME_SIZE] = {};
        for (int j = 0; j < i - prev; j++) {
          enemy[j] = temp2[prev + j];
        }
        prev = i + 1;
        strcpy(enemies[num_enemies], enemy);
        num_enemies++;
        if (temp2[i] == '\0') {
          break;
        }
      }
    }
    if ((strlen(name) >= MAX_NAME_SIZE) || (strlen(family) >= MAX_NAME_SIZE) ||
        (strlen(buf) >= MAX_BUF_SIZE) || (power < 0)) {
      fclose(fp);
      printf("BAD_RECORD 4\n");
      return BAD_RECORD;
    }
    strncpy(vendetta, buf, sizeof(vendetta));
    vendetta[sizeof(vendetta) - 1] = '\0';
    strcpy(cur.name, name);
    strcpy(cur.family, family);
    strcpy(cur.silent_vendetta, vendetta);
    cur.power = power;
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
      int bad_record = 0; //self ref or duplicates
      if ((strcmp(name, allies[i]) == 0) || (strcmp(name, enemies[i]) == 0)) { 
        bad_record = 1;
      }
      strcpy(cur.allies[i], allies[i]);
      strcpy(cur.enemies[i], enemies[i]);
      for (int j = i + 1; j < MAX_ARRAY_LENGTH; j++) {
        if (((strcmp(allies[i], allies[j]) == 0) && (allies[i][0] != '\0') &&
            (allies[j][0] != '\0')) || ((strcmp(enemies[i], enemies[j]) == 0)
            && (enemies[i][0] != '\0') && (enemies[j][0] != '\0'))) {
          bad_record = 1;
        }
      }
      if (bad_record == 1) {
        fclose(fp);
        printf("BAD_RECORD 5\n");
        return BAD_RECORD;
      }
    }
    g_criminal_array[rows] = cur;
    printcrim(cur); printf("\n");
  }
  g_criminal_count = rows;
  fclose(fp);
  if (rows == 0) {
    printf("NO DATA\n");
    return NO_DATA;
  }
  if (check_found() == NOT_FOUND) {
    printf("NOT FOUND\n");
    return NOT_FOUND;
  }
  if (check_duplicates() == DUPLICATE_NAMES) {
    printf("DUPLICATE");
    return DUPLICATE_NAMES;
  }
  printf("SUCCESS: %d\n", rows);
  return rows;
}


int can_pay_back(char *file) {
  return 0;
}

int in_great_danger(char *file) {
  return 0;
}

int main () {
  int x = read_criminals("input_5597.txt");
  printf("fiunaal %d", x);
  return 0;
}

