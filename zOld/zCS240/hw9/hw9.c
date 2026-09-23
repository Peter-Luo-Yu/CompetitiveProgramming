/*
 * Homework 9
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw9.h"

#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void build_property(char *name, int price, int rent, char *color, property_t **property) {
    assert(name != NULL);
    assert(property != NULL);
    assert(*property == NULL);

    assert(price > rent);
    assert(rent > 0);
    assert((strcmp(color, "brown") == 0) || (strcmp(color, "teal") == 0) ||
           (strcmp(color, "magenta") == 0) || (strcmp(color, "orange") == 0) || 
           (strcmp(color, "red") == 0) || (strcmp(color, "yellow") == 0) ||
           (strcmp(color, "green") == 0) || (strcmp(color, "blue") == 0) ||
           (strcmp(color, "black") == 0));

    property_t *ptr = (property_t *) malloc(sizeof(property_t));
    assert(ptr != NULL);

    ptr -> name = malloc(strlen(name) + 1);
    assert(ptr -> name != NULL);
    strcpy(ptr -> name, name);

    ptr -> color = malloc(strlen(color) + 1);
    assert(ptr -> color != NULL);
    strcpy(ptr -> color, color);

    ptr -> price = price;
    ptr -> rent = rent;

    ptr -> owner_id = -1;
    ptr -> next = NULL;
    ptr -> prev = NULL;
    
    ptr -> houses = 0;
    ptr -> monopolized = false;

    if (strcmp(color, "black") == 0) {
        ptr -> is_railroad = true;
    } else {
        ptr -> is_railroad = false;
    }

    *property = ptr;
}

int urban_planning(property_t **property_list, property_t *property) {
    assert(property_list != NULL);
    assert(property != NULL);

    property_t *prev = NULL;
    property_t *cur = *property_list;

    while (cur != NULL) {
        if (strcmp(property -> name, cur -> name) == 0) {
            return INVALID_PROPERTY;
        }
        cur = cur -> next;
    }

    cur = *property_list;

    while ((cur != NULL) && (cur -> price < property -> price)) {
        prev = cur;
        cur = cur -> next;
    }
    while ((cur != NULL) && (strcmp(cur -> name, property -> name) < 0) &&
           (cur -> price == property -> price)) {
        prev = cur;
        cur = cur -> next;
    }

    if (prev != NULL) printf("PREV: %d - %s\n", prev->price, prev->name);
    if (cur != NULL) printf("CUR: %d - %s\n", cur->price, cur->name);
    if (property != NULL) printf("PROP: %d - %s\n", property->price, property->name);
    printf("-----------------\n"); 


    if (prev == NULL && cur == NULL) {
        *property_list = property;

        property -> prev = NULL;
        property -> next = NULL;
    }
    else if (prev == NULL) {
        *property_list = property;

        property -> next = cur;
        property -> prev = NULL;

        cur -> prev = property;
    }
    else if (cur == NULL) {
        prev -> next = property;
        property -> prev = prev;

        property -> next = NULL;
    } else {
        property -> next = cur;

        prev -> next = property;
        property -> prev = prev;

        cur -> prev = property;
    }

    return OK;
}

int buy_property(player_t *player, property_t *property) {
    assert(player != NULL);
    assert(property != NULL);

    if (property -> owner_id != -1) {
        return ALREADY_OWNED;
    }
    if (property -> price > player -> cash) {
        return INSUFFICIENT_FUNDS;
    }

    property -> owner_id = player -> id;
    player -> cash -= property -> price;

    return OK;
}

void bankruptcy(player_t **players, int id) {
    assert(players != NULL);

    player_t *prev = NULL;
    player_t *cur = *players;

    while (cur != NULL && cur -> id != id) {
        prev = cur;
        cur = cur -> next;
    }

    printf("goal id: %d\n", id);
    if (prev != NULL) printf("PREV: %d - %s\n", prev->id, prev->name);
    if (cur != NULL) printf("CUR: %d - %s\n", cur->id, cur->name);

    
    if (prev == NULL) {
        *players = cur -> next;

        if (cur -> next != NULL) {
            cur -> next -> prev = NULL;
        }

        cur -> next = NULL;
    }
    else {
        prev -> next = cur -> next;

        if (cur -> next != NULL) {
            cur -> next -> prev = prev;
        }

        cur -> prev = NULL;
        cur -> next = NULL;
    }

    board_space_t *head = cur -> current_space;
    board_space_t *pos = head;

    do {
        if ((pos -> property != NULL) && (pos -> property -> owner_id == cur -> id)) {
            pos -> property -> owner_id = -1;
        }

        pos = pos -> next;

    } while (pos != head);

    free(cur -> name);
    free(cur);
    cur = NULL;
    
}


int auction_property(board_space_t *board, player_t *player_list) {
    assert(board != NULL);
    assert(player_list != NULL);
    assert(board->type == PROPERTY);

    property_t *property = board -> property;
    player_t *cur = player_list;

    player_t *prev_bidder = NULL;
    
    int highest_bid = 0;

    int price = (int) fmax(1, floor(0.1 * property -> price));

    printf("start price: %d\n", price);

    do {
        int score = 0;

        int same_color = 0;

        board_space_t *head = cur -> current_space;
        board_space_t *pos = head;
        do {
            if ((pos -> property != NULL) && (pos -> property -> owner_id == cur -> id) &&
                (strcmp(pos -> property -> color, property -> color) == 0)) {
                same_color = 1;
            }
            pos = pos -> next;
        } while (pos != head);
        
        int monopoly = 1;
        pos = head;
        do {
            if ((pos -> property != NULL) && (pos -> property != property) &&
                (strcmp(pos -> property -> color, property -> color) == 0) &&
                (pos -> property -> owner_id != cur -> id)) {
                monopoly = 0;
            }
            pos = pos -> next;
        } while (pos != head);

        if (same_color == 1) {
            score++;
        }
        if (monopoly == 1) {
            score++;
        }

        int will = (int) floor((0.25 + 0.25 * score) * cur -> cash);

        if (will >= price) {
            printf("%s bid %d\n", cur -> name, price);

            prev_bidder = cur;
            highest_bid = price;

            int delta = (int) fmax(1, floor(0.05 * property -> price));
            price += delta;
            
        }

        if (cur -> next == NULL) {
            cur = player_list;
        } else {
            cur = cur -> next;
        }
        
    } while (prev_bidder == NULL ? cur != player_list : prev_bidder != cur);

    

    if (highest_bid == 0) {
        printf("NO VALID BIDS\n");
        return NO_VALID_BIDS;
    }

    printf("final price: %d\n", price);
    printf("%s | %d | %d\n", prev_bidder -> name, highest_bid, prev_bidder -> cash);

    property -> owner_id = prev_bidder -> id;
    prev_bidder -> cash -= highest_bid;

    if (property -> is_railroad == true) {
        board_space_t *head = prev_bidder -> current_space;
        board_space_t *pos = head;
        int count = 0;

        do {
            if ((pos -> property != NULL) && (pos -> property != property) &&
                (pos -> property -> is_railroad == true) &&
                (pos -> property -> owner_id == prev_bidder -> id)) {
                count++;
                pos -> property -> rent *= 2;
            }
            pos = pos -> next;
        } while (pos != head);

        property -> rent = property -> rent << count;
    }

    printf("------------------\n");
    return OK;
}







void monopolize_color(player_t *player, char *color) {
    assert(player != NULL);
    assert(color != NULL);
    assert((strcmp(color, "brown") == 0) || (strcmp(color, "teal") == 0) ||
           (strcmp(color, "magenta") == 0) || (strcmp(color, "orange") == 0) || 
           (strcmp(color, "red") == 0) || (strcmp(color, "yellow") == 0) ||
           (strcmp(color, "green") == 0) || (strcmp(color, "blue") == 0) ||
           (strcmp(color, "black") == 0));

    
    if (strcmp(color, "black") == 0) {
        return;
    }

    board_space_t *head = player -> current_space;
    board_space_t *cur = head;

    if (head == NULL) {
       printf("head null\n");
    }

    
    int monopoly = 1;
    do {
        if ((cur -> property != NULL) && 
            (strcmp(cur -> property -> color, color) == 0)) {
            if (cur -> property -> owner_id != player -> id) {
                monopoly = 0;
            }
        }

        cur = cur -> next;
    } while (cur != head);

    if (monopoly == 1) {
        head = player -> current_space;
        cur = head;

        do {
            if ((cur -> property != NULL) && 
                (strcmp(cur -> property -> color, color) == 0) &&
                (cur -> property -> owner_id == player -> id)) {
                
                cur -> property -> monopolized = true;
                cur -> property -> rent *= 2;
            }

            cur = cur -> next;
        } while (cur != head);
    }
}

int move_player(player_t *player, int n, board_space_t **board) {
    assert(player != NULL);
    assert(board != NULL);

    assert(n > 0);

    board_space_t *head = *board;
    board_space_t *cur = head;

    while (player -> current_space != cur) {
        cur = cur -> next;
    }

    while (n--) {
        cur = cur -> next;
        if (cur->type == GO) {
            player->cash += 200;
        }
    }

    player -> current_space = cur;
    *board = cur;


    if (cur -> type == GO_TO_JAIL) {
        return SENT_TO_JAIL;
    }
    if ((cur -> type == PROPERTY) && (cur -> property != NULL)) {
        if (cur -> property -> owner_id != -1) {
            return ALREADY_OWNED;
        }
        if (player -> cash < cur -> property -> price) {
            return INSUFFICIENT_FUNDS;
        }
        
        
        cur -> property -> owner_id = player -> id;
        player -> cash -= cur -> property -> price;

        if (cur -> property -> is_railroad == true) {
            board_space_t *pos = head;
            int count = 0;

            do {
                if ((pos -> property != NULL) && 
                    (pos -> property -> is_railroad == true) &&
                    (pos -> property -> owner_id != -1)) {
                    
                    count++;
                    
                }

                pos = pos -> next;
            } while (pos != head);

            if (count > 1) {
                pos = head;
                do {
                    if ((pos -> property != NULL) && 
                        (pos -> property -> is_railroad == true) &&
                        (pos -> property -> owner_id != -1)) {
                        
                        pos -> property -> rent *= 2;
                    }

                    pos = pos -> next;
                } while (pos != head);
            }
        }
    }

    return OK;
}


int play_monopoly(board_space_t *a, player_t **b, int c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(*b != NULL);
    assert(c > 0);

    return 0;
}



