/*
 * Homework 12
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw12.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

/*
 * Have to keep these functions here to compile
 */

void print_tree(node_t *a) {

} /* print_tree() */

/*
 * Have to keep these functions here to compile
 */

void print_node(node_t *c) {

} /* print_node() */

/*
 * Have to keep these functions here to compile
 */

void print_country_data(void *a) {

} /* print_country_data() */

/*
 * Have to keep these functions here to compile
 */

void print_restaurant_data(void *) {

} /* print_restaurant_data() */

/*
 * deletes the entire BST given the root
 */

void delete_tree(node_t **root) {
  assert(root != NULL);

  if (*root == NULL) {
    return;
  }

  if ((*root)->left_child != NULL) {
    delete_tree(&((*root)->left_child));
  }
  if ((*root)->right_child != NULL) {
    delete_tree(&((*root)->right_child));
  }

  (*root)->delete(&((*root)->data));
  free(*root);
  (*root) = NULL;

} /* delete_tree() */


/*
 * allocates space for a new node of the tree
 */

void create_node(node_t **ptr, void *data, void (*print)(void *), void (*delete)(void **),
                 int (*compare)(void *, void *)) {
  assert(ptr != NULL);
  assert(*ptr == NULL);
  assert(data != NULL);
  assert(print != NULL);
  assert(delete != NULL);
  assert(compare != NULL);

  *ptr = malloc(sizeof(node_t));
  assert(*ptr != NULL);

  (*ptr)->data = data;
  (*ptr)->left_child = NULL;
  (*ptr)->right_child = NULL;
  (*ptr)->print = print;
  (*ptr)->delete = delete;
  (*ptr)->compare = compare;

} /* create_node() */

/*
 * Deallocates the space and data of the specified node
 */

void delete_node(node_t **node) {
  assert(node != NULL);
  assert(*node != NULL);
  assert((*node)->left_child == NULL);
  assert((*node)->right_child == NULL);

  (*node)->delete(&((*node)->data));

  free(*node);
  *node = NULL;

}

/*
 * Insert the given node to the given BST
 */

void insert_node(node_t **root, node_t *node) {
  assert(root != NULL);
  assert(node != NULL);

  if (*root == NULL) {
    *root = node;
    return;
  }

  if ((*root)->compare(node->data, (*root)->data) <= 0) {
    insert_node(&((*root)->left_child), node);
  } else {
    insert_node(&((*root)->right_child), node);
  }

} /* insert_node() */

/*
 * helper function that determines the number of nodes
 * that contain the same data as the specified data
 */

int amount_nodes(node_t *root, void *data) {
  int count = 0;

  if (root == NULL) {
    return 0;
  }

  if (root->compare(root->data, data) == 0) {
    count++;
  }

  if (root->left_child != NULL) {
    count += amount_nodes(root->left_child, data);
  }
  if (root->right_child != NULL) {
    count += amount_nodes(root->right_child, data);
  }

  return count;

} /* amount_nodes() */

/*
 * helper function that populates the array of pointers with the addresses
 * of nodes which contain the same data as the specified data
 */

void append_nodes(node_t *root, void *data, node_t **array, int *index) {
  if (root == NULL) {
    return;
  }

  if (root->compare(root->data, data) == 0) {
    array[*index] = root;
    (*index)++;
  }

  if (root->left_child != NULL) {
    append_nodes(root->left_child, data, array, index);
  }
  if (root->right_child != NULL) {
    append_nodes(root->right_child, data, array, index);
  }

} /* append_nodes() */

/*
 * this function returns an array of pointers to all the nodes 
 * that contain the same data as the given data
 */

node_t **find_nodes(node_t *root, void *data, int *count) {
  assert(root != NULL);
  assert(data != NULL);
  assert(count != NULL);

  int num_nodes = amount_nodes(root, data);
  *count = num_nodes;
  
  if (num_nodes == 0) {
    return NULL;
  }

  node_t **array = malloc(num_nodes * sizeof(node_t *));
  assert(array != NULL);

  int index = 0;
  append_nodes(root, data, array, &index);

  return array;

} /* find_nodes() */

/*
 * removes the specified node from the BST
 */

void remove_node(node_t **root, node_t *node) {
  assert(root != NULL);
  assert(node != NULL);

  if (*root == NULL) {
    return;
  }
  
  if ((*root)->compare((*root)->data, node->data) < 0) {
    remove_node(&((*root)->right_child), node);
  }
  else if ((*root)->compare((*root)->data, node->data) > 0) {
    remove_node(&((*root)->left_child), node);
  }

  else if ((*root)->compare((*root)->data, node->data) == 0) {

    if (((*root)->left_child == NULL) &&
        ((*root)->right_child == NULL)) {
          
      node_t *temp = (*root);

      (*root) = NULL;

      
      (temp)->delete(&(temp->data));
      free(temp);
      temp = NULL;
    }
    else if (((*root)->left_child == NULL) &&
             ((*root)->right_child != NULL)) {

      node_t *temp = (*root);

      (*root) = (*root)->right_child;

      
      (temp)->delete(&(temp->data));
      free(temp);
      temp = NULL;
    }
    else if (((*root)->right_child == NULL) &&
             ((*root)->left_child != NULL)) {

      node_t *temp = (*root);

      (*root) = (*root)->left_child;
      

      (temp)->delete(&(temp->data));
      free(temp);
      temp = NULL;
    
    }
    else {

      // replace is right most node of left subtree

      node_t **replace = &((*root)->left_child);

      while ((*replace)->right_child != NULL) {
        replace = &((*replace)->right_child);
      }

      node_t *temp = *replace;

      // first delete the root's data
      
      (*root)->delete(&(*root)->data);

      // copy replace's data to root

      (*root)->data = (*replace)->data;
      *replace = (*replace)->left_child;
      
      free(temp);
      temp = NULL;
    }
  }

} /* remove_node */


/*
 * Allocates space and populates a new country structure
 */

void create_country_data(void **ptr, const char *name, const char *continent,
                         long population, int year, float gdp, float output) {
  assert(ptr != NULL);
  assert(*ptr == NULL);
  assert(name != NULL);
  assert(continent != NULL);

  country_t *country = malloc(sizeof(country_t));
  assert(country != NULL);

  country->name = malloc(strlen(name) + 1);
  assert(country->name != NULL);
  strcpy(country->name, name);

  country->continent = malloc(strlen(continent) + 1);
  assert(country->name != NULL);
  strcpy(country->continent, continent);
  
  country->population = population;
  country->founding_year = year;
  country->gdp = gdp;
  country->produce_output = output;

  *ptr = (void *) country;

} /* create_country_data() */
      
/*
 * Deallocates space and frees a country struct
 */

void delete_country_data(void **ptr) {
  assert(ptr != NULL);
  assert(*ptr != NULL);

  country_t *country = (country_t *) (*ptr);

  free(country->name);
  free(country->continent);
  free(country);
  country = NULL;

  *ptr = NULL;

} /* delete_country_data() */

/*
 * Custom Comparator function that compares two countries
 */

int compare_country_data(void *ptr1, void *ptr2) {
  assert(ptr1 != NULL);
  assert(ptr2 != NULL);

  country_t *country1 = (country_t *) ptr1;
  country_t *country2 = (country_t *) ptr2;

  double score1 = (country1->gdp * country1->produce_output) /
                  (country1->population * (CURRENT_YEAR - country1->founding_year));

  double score2 = (country2->gdp * country2->produce_output) /
                  (country2->population * (CURRENT_YEAR - country2->founding_year));

  if (score1 == score2) {
    return 0;
  }
  else if (score1 > score2) {
    return 1;
  }
  else {
    return -1;
  }

} /* compare_country_data() */

/*
 * Allocates space and populates a new restaurant structure
 */

void create_restaurant_data(void **ptr, const char *name, int id, int year, float price, float rating) {
  assert(ptr != NULL);
  assert(*ptr == NULL);
  assert(name != NULL);

  restaurant_t *restaurant = malloc(sizeof(restaurant_t));
  assert(restaurant != NULL);

  restaurant->name = malloc(strlen(name) + 1);
  assert(restaurant->name);
  strcpy(restaurant->name, name);

  restaurant->city_id = id;
  restaurant->est_year = year;
  restaurant->price = price;
  restaurant->rating = rating;

  *ptr = (void *) restaurant;

} /* create_restaurant_data() */

/*
 * Deallocates space and frees a restaurant struct
 */

void delete_restaurant_data(void **ptr) {
  assert(ptr != NULL);
  assert(*ptr != NULL);

  restaurant_t *restaurant = *ptr;

  free(restaurant->name);
  free(restaurant);
  restaurant = NULL;

  *ptr = NULL;

} /* delete_restaurant_data() */

/*
 * Custom Comparator function that compares two restaurants
 */

int compare_restaurant_data(void *ptr1, void *ptr2) {
  assert(ptr1 != NULL);
  assert(ptr2 != NULL);

  restaurant_t *restaurant1 = (restaurant_t *) ptr1;
  restaurant_t *restaurant2 = (restaurant_t *) ptr2;

  double score1 = (restaurant1->rating) /
                  (restaurant1->price * (CURRENT_YEAR - restaurant1->est_year));

  double score2 = (restaurant2->rating) /
                  (restaurant2->price * (CURRENT_YEAR - restaurant2->est_year));

  if (score1 == score2) {
    return 0;
  }
  else if (score1 > score2) {
    return 1;
  }
  else {
    return -1;
  } 

} /* compare_restaurant_data() */

