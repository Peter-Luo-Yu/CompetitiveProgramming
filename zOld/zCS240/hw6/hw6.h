#ifndef HW6_H

#define HW6_H

/*
 * hw6.h - Homework 6 header file
 * CS 240, Spring 2026
 * Purdue University
 */

/* Constant definitions */

#define MAX_CRIMINALS (100)
#define MAX_NAME_SIZE (25)
#define MAX_SECRET_SIZE (30)
#define MAX_ARRAY_LENGTH (20)
#define MAX_BUF_SIZE (50)

/* Structure definitions */

typedef struct criminal {
  char name[MAX_NAME_SIZE];
  char family[MAX_NAME_SIZE];
  char silent_vendetta[MAX_SECRET_SIZE];
  int power;
  char allies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE];
  char enemies[MAX_ARRAY_LENGTH][MAX_NAME_SIZE];
} criminal_t;

/* Function prototypes */

int read_criminals(char *);
int can_pay_back(char *);
int in_great_danger(char *);

/* Global variables */

extern int g_criminal_count;
extern criminal_t g_criminal_array[MAX_CRIMINALS];

/* Error codes */

#define FILE_READ_ERR (-1)
#define BAD_RECORD (-2)
#define TOO_MUCH_DATA (-3)
#define NO_DATA (-4)
#define NOT_FOUND (-5)
#define DUPLICATE_NAMES (-6)

#endif // HW6_H
