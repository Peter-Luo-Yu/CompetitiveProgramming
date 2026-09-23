#ifndef HW8_H
#define HW8_H

/* Error codes */

#define SUCCESS (0)
#define NOT_FOUND (-1)
#define INVALID_MOVE (-2)

/* Struct definitions */

typedef struct coin_struct {
  char *metal_type;
  double weight;
  double value;
  struct coin_struct *next;
} coin_t;

typedef struct pot_struct {
  char *customer_name;
  double total_weight;
  double declared_value;
  struct coin_struct *coin_list;
  struct pot_struct *next;
} pot_t;

/* Function prototypes */

coin_t *create_coin(char *, double, double);
pot_t *create_pot(char *);
int add_coin(pot_t *, char *, coin_t *);
coin_t *remove_coin(pot_t *, coin_t *);
int transfer_coin(pot_t *, char *, char *, coin_t *);
coin_t *find_counterfeits(pot_t *, char *);
pot_t *heaviest_pot(pot_t *);
int melt_worthless_coins(pot_t *, double, double);
int audit_customers(pot_t **);
int quarantine_infected_pots(pot_t **, char *);

#endif
