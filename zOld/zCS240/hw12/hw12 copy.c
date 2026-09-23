/*
 * Homework 12
 * Your Name
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw12.h"

#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>



/*
 * Function to print the internal data of a country_t struct passed as a void
 * pointer to standard out.
 */

void print_country_data(void *p) {
  country_t *ptr = (country_t *)p;
  assert(ptr && ptr->name);
  printf("Name: %s\nContinent: %s\nPopulation: %ld\nFounding Year: %d\nGDP: "
         "%.2f\nProduce Output: %.2f\n",
         ptr->name, ptr->continent, ptr->population, ptr->founding_year,
         ptr->gdp, ptr->produce_output);
} /* print_country() */

/*
 * Function to print the internal data of an restaurant_t struct passed as a
 * void pointer to standard out.
 */

void print_restaurant_data(void *p) {
  restaurant_t *ptr = (restaurant_t *)p;
  assert(ptr && ptr->name);
  printf("Name: %s\nCity ID: %d\nEstablished Year: %d\n"
         "Price: %.2f\nRating: %.2f\n",
         ptr->name, ptr->city_id, ptr->est_year, ptr->price, ptr->rating);
} /* print_restaurant() */

/*
 * Function to print a tree node by dynamically dispatching the print function
 * stored in the node on the data stored in the node.
 */

void print_node(node_t *n_ptr) {
  assert(n_ptr && n_ptr->data && n_ptr->print);
  (n_ptr->print)(n_ptr->data);
} /* print_node() */

/*
 * Function to recursively print the tree using an in-order traversal.
 */

void print_tree(node_t *root) {
  if (!root) {
    return;
  }
  print_tree(root->left_child);
  print_node(root);
  print_tree(root->right_child);
} /* print_tree() */



void create_node(node_t **ptr, void *data, void (*print)(void *), void (*delete)(void **),
                 int (*compare)(void *, void *)) {
  *ptr = malloc(sizeof(node_t));
  (*ptr)->data = data;
  (*ptr)->left_child = NULL;
  (*ptr)->right_child = NULL;
  (*ptr)->print = print;
  (*ptr)->delete = delete;
  (*ptr)->compare = compare;
}


void delete_node(node_t **a) {

}
void insert_node(node_t **a, node_t *b) {

}
node_t **find_nodes(node_t *a, void *b, int *c) {
  return NULL;
}
void remove_node(node_t **a, node_t *b) {

}

void print_country_data(void *a) {

}
void create_country_data(void **a, const char *b, const char *c, long d, int e, float f,
                         float gh) {
  
}
void delete_country_data(void **a) {

}
int compare_country_data(void *a, void *b) {
  return 0;
}

void print_restaurant_data(void *a) {

}
void create_restaurant_data(void **a, const char *b, int c, int d, float r, float f) {

}
void delete_restaurant_data(void **a) {

}
int compare_restaurant_data(void *a, void *b) {
  return 0;
}

