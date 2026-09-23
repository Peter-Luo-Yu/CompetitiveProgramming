/*
 * Homework 8
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw8.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*
 * This function checks if two coins are equal.
 */

int compare_coin(coin_t *coin1, coin_t *coin2) {
  if ((strcmp(coin1->metal_type, coin2->metal_type) == 0) && 
      (coin1->weight == coin2->weight) && (coin1->value == coin2->value)) {
    return 1;
  }
  return 0;

} /* compare_coin() */

/*
 * This function creates a coin struct by allocating memory and 
 * assiging the given values respectively.
 */

coin_t *create_coin(char *metal_type, double weight, double value) {
  assert(metal_type != NULL);
  assert(weight > 0);
  assert(value > 0);

  coin_t *coin = (coin_t *) malloc(sizeof(coin_t));
  assert(coin != NULL);

  coin -> metal_type = malloc(strlen(metal_type) + 1);
  assert(coin -> metal_type != NULL);

  strcpy(coin->metal_type, metal_type);

  coin -> weight = weight;
  coin -> value = value;
  coin -> next = NULL;

  return coin;

} /* create_coin() */

/*
 * This function creates a pot struct by allocating memory
 * and assigining the given customer name.
 */

pot_t *create_pot(char *customer_name) {
  assert(customer_name != NULL);

  pot_t *pot = (pot_t *) malloc(sizeof(pot_t));
  assert(pot != NULL);

  pot -> customer_name = malloc(strlen(customer_name) + 1);
  assert(pot -> customer_name != NULL);

  strcpy(pot -> customer_name, customer_name);

  pot -> total_weight = 0.0;
  pot -> declared_value = 0.0;
  pot -> coin_list = NULL;
  pot -> next = NULL;

  return pot;

} /* create_pot() */

/*
 * This function adds a coin to the correct position 
 * in the correct pot given a customer name.
 */

int add_coin(pot_t *pots, char *customer_name, coin_t *coin) {
  assert(pots != NULL);
  assert(customer_name != NULL);
  assert(coin != NULL);

  int found = 0;

  pot_t *cur_pot = pots;
  while (cur_pot != NULL) {
    if (strcmp(customer_name, cur_pot -> customer_name) == 0) {
      found = 1;
      break;
    }
    cur_pot = cur_pot -> next;
  }

  if (found == 0) {
    return NOT_FOUND;
  }

  coin_t *prev_coin = NULL;
  coin_t *cur_coin = cur_pot -> coin_list;

  while (cur_coin != NULL) {
    if (cur_coin -> weight < coin -> weight) {
      break;
    }
    prev_coin = cur_coin;
    cur_coin = cur_coin -> next;
  }

  
  if (prev_coin != NULL && compare_coin(prev_coin, coin) == 1) {
    return INVALID_MOVE;
  }

  if (prev_coin == NULL) {
    coin -> next = cur_pot -> coin_list;
    cur_pot -> coin_list = coin;
  } else {
    prev_coin -> next = coin;
    coin -> next = cur_coin;
  }
  
  cur_pot -> total_weight += coin -> weight;

  return SUCCESS;

} /* add_coin() */

/*
 * This function removes a given coin from a given pot.
 */

coin_t *remove_coin(pot_t *pot, coin_t *coin) {
  assert(pot != NULL);
  assert(coin != NULL);

  coin_t *prev_coin = NULL;
  coin_t *cur_coin = pot -> coin_list;

  while (cur_coin != NULL) {
    if (compare_coin(cur_coin, coin) == 1) {
      break;
    }
    prev_coin = cur_coin;
    cur_coin = cur_coin -> next;
  }

  if (cur_coin == NULL) {
    return NULL;
  }

  if (prev_coin == NULL) {
    pot -> coin_list = cur_coin -> next;
  } else {
    prev_coin -> next = cur_coin -> next;
  }

  cur_coin -> next = NULL;

  pot -> total_weight -= coin -> weight;
  
  return coin;

} /* remove_coin() */

/*
 * This function removes a given coin from the pot of from_customer
 * and adds it to the pot of to_customer.
 */

int transfer_coin(pot_t *pots, char *from_customer, char *to_customer, coin_t *coin) {
  assert(pots != NULL);
  assert(from_customer != NULL);
  assert(to_customer != NULL);
  assert(coin != NULL);

  if (strcmp(from_customer, to_customer) == 0) {
    return INVALID_MOVE;
  }

  pot_t *from_pot = pots;
  pot_t *to_pot = pots;

  while (from_pot != NULL) {
    if (strcmp(from_customer, from_pot -> customer_name) == 0) {
      break;
    }
    from_pot = from_pot -> next;
  }
  while (to_pot != NULL) {
    if (strcmp(to_customer, to_pot -> customer_name) == 0) {
      break;
    }
    to_pot = to_pot -> next;
  }

  if ((from_pot == NULL) || (to_pot == NULL)) {
    return NOT_FOUND;
  }

  coin_t *found = from_pot -> coin_list;
  while (found != NULL) {
    if (compare_coin(found, coin) == 1) {
      break;
    }
    found = found -> next;
  }

  if (found == NULL) {
    return NOT_FOUND;
  }

  coin_t *removed = remove_coin(from_pot, coin);
  if (removed == NULL) {
    return INVALID_MOVE;
  }

  int result = add_coin(pots, to_customer, removed);
  if (result != SUCCESS) {
    add_coin(pots, from_customer, removed);  
    return result;
  }

  return SUCCESS;

} /* transfer_coin() */

/*
 * This function eliminates all coins of a metal type from all pots.
 */

coin_t *find_counterfeits(pot_t *pots, char *metal_type) {
  assert(pots != NULL);
  assert(metal_type != NULL);

  coin_t *removed_pot = NULL;

  pot_t *cur_pot = pots;
  while (cur_pot != NULL) {
    coin_t *cur_coin = cur_pot -> coin_list;

    while (cur_coin != NULL) {

      coin_t *next_coin = cur_coin -> next;

      if (strcmp(cur_coin -> metal_type, metal_type) == 0) {

        coin_t *removed_coin = remove_coin(cur_pot, cur_coin);

        coin_t *prev = NULL;
        coin_t *cur = removed_pot;

        while (cur != NULL) {
          if (cur -> weight < removed_coin -> weight) {
            break;
          }
          prev = cur;
          cur = cur -> next;
        }

        if (prev == NULL) {
          removed_coin -> next = removed_pot;
          removed_pot = removed_coin;
        } else {
          prev -> next = removed_coin;
          removed_coin -> next = cur;
        }

      }

      cur_coin = next_coin;
    }
    cur_pot = cur_pot -> next;
  }

  return removed_pot;

} /* find_counterfiets() */

/*
 * This function returns the pot with the most weight.
 */

pot_t *heaviest_pot(pot_t *pots) {
  assert(pots != NULL);

  int all_negative = 1;

  pot_t *heaviest_pot = NULL;
  pot_t *cur_pot = pots;
  double max_weight = 0.0;
  int max_coins = 0;

  while (cur_pot != NULL) {
    double cur_weight = cur_pot -> total_weight;
    if (cur_weight > 0) {
      all_negative = 0;
    }

    int cur_coins = 0;

    coin_t *cur_coin = cur_pot -> coin_list;

    while (cur_coin != NULL) {
      cur_coins++;
      cur_coin = cur_coin -> next;
    }

    if (cur_weight > max_weight) {
      heaviest_pot = cur_pot;
      max_weight = cur_weight;
      max_coins = cur_coins;
    }
    else if ((cur_weight == max_weight) && (cur_coins > max_coins)) {
      heaviest_pot = cur_pot;
      max_coins = cur_coins;
    }

    cur_pot = cur_pot -> next;
  }

  if (all_negative == 1) {
    return NULL;
  }

  return heaviest_pot;

} /* heaviest_pot() */

/*
 * This function removes all coins under a certain weight and value.
 */

int melt_worthless_coins(pot_t *pots, double min_weight, double min_value) {
  assert(pots != NULL);
  assert(min_weight > 0);
  assert(min_value > 0);

  int coins_melted = 0;

  pot_t *cur_pot = pots;

  while (cur_pot != NULL) {

    coin_t *cur_coin = cur_pot -> coin_list;

    while (cur_coin != NULL) {

      coin_t *next_coin = cur_coin -> next;

      if ((cur_coin -> weight < min_weight) && (cur_coin -> value < min_value)) {
        
        coin_t *removed_coin = remove_coin(cur_pot, cur_coin);

        free(removed_coin -> metal_type);
        free(removed_coin);
        removed_coin = NULL;

        coins_melted++;

      }

      cur_coin = next_coin;

    }

    cur_pot = cur_pot -> next;
  }

  if (coins_melted == 0) {
    return NOT_FOUND;
  }

  return coins_melted;

} /* melt_worthless_coins() */

/*
 * This function checks if the declared value of a pot is more than
 * the actual value of the pot, if yes, then the pot is deleted.
 */

int audit_customers(pot_t **pots) {
  assert(pots != NULL);
  assert(*pots != NULL);

  int liars = 0;

  pot_t *prev = NULL;
  pot_t *cur_pot = *pots;

  while (cur_pot != NULL) {
    pot_t *next_pot = cur_pot -> next;

    double actual_value = 0.0;

    coin_t *cur_coin = cur_pot -> coin_list;

    while (cur_coin != NULL) {
      actual_value += cur_coin -> value;
      cur_coin = cur_coin -> next;
    }

    if (actual_value < cur_pot -> declared_value) {
      cur_coin = cur_pot -> coin_list;

      while (cur_coin != NULL) {
        coin_t *next_coin = cur_coin -> next;

        free(cur_coin -> metal_type);
        free(cur_coin);
        cur_coin = NULL;
        
        cur_coin = next_coin;
      }
      
      free(cur_pot -> customer_name);
      free(cur_pot);
      cur_pot = NULL;
      liars++;

      if (prev == NULL) {
        *pots = next_pot;
      } else {
        prev -> next = next_pot;
      }

    } else {
      prev = cur_pot;
    }

    cur_pot = next_pot;
  }

  if (liars == 0) {
    return NOT_FOUND;
  }

  return liars;

} /* audit_customers() */

/*
 * This function removes all pots that contain the infectious metal.
 */

int quarantine_infected_pots(pot_t **pots, char *infectious_metal) {
  assert(pots != NULL);
  assert(*pots != NULL);
  assert(infectious_metal != NULL);

  int num_infected = 0;
  pot_t *prev = NULL;
  pot_t *cur_pot = *pots;

  while (cur_pot != NULL) {
    pot_t *next_pot = cur_pot -> next;

    int infectious = 0;

    coin_t *cur_coin = cur_pot -> coin_list;

    while (cur_coin != NULL) {
      if (strcmp(cur_coin -> metal_type, infectious_metal) == 0) {
        infectious = 1;
      }
      cur_coin = cur_coin -> next;
    }

    if (infectious == 1) {
      num_infected++;

      cur_coin = cur_pot -> coin_list;
      
      while (cur_coin != NULL) {
        coin_t *next_coin = cur_coin -> next;
        
        free(cur_coin -> metal_type);
        free(cur_coin);
        cur_coin = NULL;

        cur_coin = next_coin;
      }

      free(cur_pot -> customer_name);
      free(cur_pot);
      cur_pot = NULL;

      if (prev == NULL) {
        *pots = next_pot;
      } 
      else {
        prev -> next = next_pot;
      }
    } 
    else {
      prev = cur_pot;
    }
    
    cur_pot = next_pot;
  }


  if (num_infected == 0) {
    return NOT_FOUND;
  }

  return num_infected;

} /* quarantine_infected_pots() */