#ifndef HW12_H
#define HW12_H

#define CURRENT_YEAR (2026)

/* Structure definitions */

typedef struct node {
  struct node *left_child;
  struct node *right_child;
  void *data;

  void (*print)(void *);
  void (*delete)(void **);
  int (*compare)(void *, void *);
} node_t;

/* Data structure 1: country structure
 *
 * population    : approximate population (whole persons)
 * founding_year : commonly accepted year of establishment / independence
 * gdp           : GDP in trillion USD (float)
 * produce_output: agricultural / total produce output in billion USD (float)
 */

typedef struct country_s {
  char *name;
  char *continent;
  long population;
  int founding_year;
  float gdp;
  float produce_output;
} country_t;

/* Data structure 2: restaurant structure
 *
 * city_id mapping:
 *   1  = New York City, USA        11 = Mexico City, Mexico
 *   2  = Los Angeles, USA          12 = Sydney, Australia
 *   3  = Chicago, USA              13 = Toronto, Canada
 *   4  = San Francisco, USA        14 = Dubai, UAE
 *   5  = Miami, USA                15 = Bangkok, Thailand
 *   6  = London, UK                16 = Singapore
 *   7  = Paris, France             17 = Istanbul, Turkey
 *   8  = Tokyo, Japan              18 = Seoul, South Korea
 *   9  = Rome, Italy               19 = Berlin, Germany
 *  10  = Barcelona, Spain          20 = Amsterdam, Netherlands
 *
 * price  : approximate average price per person in USD
 * rating : out of 5.0
 */

typedef struct restaurant_s {
  char *name;
  int city_id;
  int est_year;
  float price;
  float rating;
} restaurant_t;

/* Function declarations */

void print_tree(node_t *);
void delete_tree(node_t **);

void print_node(node_t *);
void create_node(node_t **, void *, void (*)(void *), void (*)(void **),
                 int (*)(void *, void *));
void delete_node(node_t **);
void insert_node(node_t **, node_t *);
node_t **find_nodes(node_t *, void *, int *);
void remove_node(node_t **, node_t *);

void print_country_data(void *);
void create_country_data(void **, const char *, const char *, long, int, float,
                         float);
void delete_country_data(void **);
int compare_country_data(void *, void *);

void print_restaurant_data(void *);
void create_restaurant_data(void **, const char *, int, int, float, float);
void delete_restaurant_data(void **);
int compare_restaurant_data(void *, void *);

#endif // HW12_H
