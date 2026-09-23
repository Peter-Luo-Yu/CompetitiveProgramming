#ifndef HW7_H
#define HW7_H

/*
 * hw7.h - Homework 7 header file
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
  struct criminal *ally_ptrs[MAX_ARRAY_LENGTH];
  struct criminal *enemy_ptrs[MAX_ARRAY_LENGTH];
} criminal_t;

/* Global variables */

extern int g_criminal_count;
extern criminal_t g_criminal_array[MAX_CRIMINALS];

/* Function prototypes */

int read_criminals(char *);
int connect_criminals();
int identify_mole(criminal_t *);
int find_common_enemies(criminal_t *, criminal_t *);
int ally_path_length(criminal_t *);
int weak_links(criminal_t *);

/* Error codes */

#define FILE_READ_ERR (-1)
#define BAD_RECORD (-2)
#define TOO_MUCH_DATA (-3)
#define NO_DATA (-4)
#define NOT_FOUND (-5)
#define DUPLICATE_NAMES (-6)
#define SUCCESS (-7)
#define PATH_IS_CYCLE (-8)

#endif // HW7_H

