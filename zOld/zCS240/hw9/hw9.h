#ifndef HW9_H
#define HW9_H

#include <stdbool.h>

/* Error Codes */

#define OK (-1)
#define INVALID_PROPERTY (-2)
#define INSUFFICIENT_FUNDS (-3)
#define ALREADY_OWNED (-4)
#define NO_VALID_BIDS (-5)
#define SENT_TO_JAIL (-6)

/* Structure Definitions */

typedef enum space_type_enum {
  PROPERTY,
  GO,
  FREE_PARKING,
  GO_TO_JAIL,
  JAIL,
} space_type_t;

typedef struct property_struct {
  char *name;
  int price;
  int rent;
  int owner_id;
  char *color;
  int houses;
  bool monopolized;
  bool is_railroad;
  struct property_struct *next;
  struct property_struct *prev;
} property_t;

typedef struct board_space_struct {
  space_type_t type;
  struct property_struct *property;
  struct board_space_struct *next;
  struct board_space_struct *prev;
} board_space_t;

typedef struct player_struct {
  char *name;
  int id;
  int cash;
  board_space_t *current_space;
  struct player_struct *next;
  struct player_struct *prev;
} player_t;

/* Function Prototypes */

void build_property(char *, int, int, char *, property_t **);
int urban_planning(property_t **, property_t *);
int buy_property(player_t *, property_t *);
void bankruptcy(player_t **, int);
int auction_property(board_space_t *, player_t *);
void monopolize_color(player_t *, char *);
int move_player(player_t *, int, board_space_t **);
int play_monopoly(board_space_t *, player_t **, int);

/* External helper function */

int roll_dice(void);

#endif // HW9_H
