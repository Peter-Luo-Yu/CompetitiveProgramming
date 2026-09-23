#ifndef HW10_H
#define HW10_H

/* Constant Definitions */

/* Error Codes */

#define OK (0)
#define NOT_FOUND (-1)
#define NOT_POSSIBLE (-2)

#define MAX_LEADERSHIPS (1000)

/* Enum Declarations */

typedef enum biome {
  JAGGED_PEAKS,
  BIOLUMINESCENT_FOREST,
  VOLCANIC_WASTELAND,
  LIMESTONE_LAKES,
  CHERRY_GROVE,
  SNOWY_TAIGA,
  CRIMSON_FOREST,
} biome_t;

/* Structure Declarations */

typedef struct isle {
  char *isle_name;
  char *leadership;
  enum biome isle_biome;
  int population;
  struct isle *parent_isle;
  struct isle *reachable_isles;
  struct isle *sibling_isles;
  struct dragon *dragon_list;
} isle_node_t;

typedef struct dragon {
  char *name;
  char *species;
  char *rider_name;
  int shot_lim;
  int energy;
  int speed;
  struct dragon *next_dragon;
} dragon_t;

/* Function Prototypes */

isle_node_t *create_isle_node(char *, char *, biome_t, int);
dragon_t *tame_dragon(char *, char *, char *, int, int, int, isle_node_t *);
int insert_isle_node(isle_node_t *, isle_node_t *, char *);
int travel(dragon_t *, isle_node_t *, char);
int habitat_assessment(biome_t, isle_node_t *);
dragon_t *dragonic_ecosystem(isle_node_t *, biome_t);
int raid(isle_node_t *, char **, int);
char *find_double_agent(isle_node_t *);
void free_dragons(char *, isle_node_t *);
void torch(isle_node_t **);

#endif // HW10_H