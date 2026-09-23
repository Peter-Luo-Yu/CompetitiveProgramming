/*
 * Homework 11
 * Peter Yu
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw11.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>

/*
 * newly allocates a region with a given starting address
 */

region_t *create_region(intptr_t start_address) {
    assert((start_address > 0) && (start_address % 8 == 0));

    region_t *region = malloc(sizeof(region_t));
    assert(region != NULL);

    region -> start_address = start_address;
    region -> free_list = NULL;
    region -> left = NULL;
    region -> right = NULL;

    return region;

} /* create_region() */

/*
 * newly allocates a block with size block size and 
 * inserts it to the end of the region
 */

void add_free_block(region_t *region, size_t block_size) {
    assert(region != NULL);
    assert(block_size > 0);

    block_t *block = malloc(sizeof(block_t));
    assert(block != NULL);

    block->size = block_size;
    block->state = BLOCK_FREE;

    if (region->free_list == NULL) {
        block->offset = 0;
        block->next = block;   
        block->prev = block;
        block->next_free_block = block;  
        region->free_list = block;
        return;
    }

    block_t *start = region -> free_list;
    block_t *cur = start -> next;
    block_t *head_double = start;

    while (cur != start) {
        if (cur->offset < head_double->offset) {
            head_double = cur;
        }
        cur = cur -> next;
    } 
    
    block_t *tail_double = head_double -> prev;

    block->offset = tail_double->offset + tail_double->size;

    tail_double->next = block;
    block->prev = tail_double;
    block->next = head_double;
    head_double->prev = block;


    block_t *single_head = start;
    cur = start->next_free_block;
    while (cur != start) {
        if (cur->size < single_head->size) {
            single_head = cur;
        }
        cur = cur->next_free_block;
    }

    block_t *single_tail = single_head;
    while (single_tail -> next_free_block != single_head) {
        single_tail = single_tail->next_free_block;
    }

    if (block->size < single_head->size) {
        single_tail->next_free_block = block;
        block->next_free_block = single_head;
        region->free_list = block;
        return;
    }

    block_t *single_prev = single_head;
    block_t *single_cur = single_head->next_free_block;
    while ((single_cur != single_head) && (single_cur->size <= block->size)) {
        single_prev = single_cur;
        single_cur = single_cur->next_free_block;
    }

    single_prev->next_free_block = block;
    block->next_free_block = single_cur;

    return;

} /* add_free_block */

/* 
 * inserts a new region to the BST, ordered by address
 */

void insert_region(region_t **root, region_t *new_region) {
    assert(root != NULL);
    assert(new_region != NULL);

    if (*root == NULL) {
        *root = new_region;
        return;
    }

    if (new_region->start_address <= (*root)->start_address) {
        insert_region(&((*root) -> left), new_region);
    } else {
        insert_region(&((*root) -> right), new_region);
    }

    return;

} /* insert_region() */

/* 
 * removes all free blocks with size smaller than min_size
 */

int remove_fragmented_blocks(region_t *root, size_t min_size) {
    assert(root != NULL);
    assert(min_size >= 0);

    int count = 0;

    while (1) {
        int found = 0;

        block_t *start = root->free_list;

        if (start == NULL || start->state != BLOCK_FREE) {
            break;
        }

        block_t *double_cur = start;
        block_t *double_prev = start->prev;

        do {
            if (double_cur->state == BLOCK_FREE &&
                double_cur->size < min_size) {
                found = 1;
                break;
            }
            double_prev = double_cur;
            double_cur = double_cur->next;
        } while (double_cur != start);

        if (!found) break;



        if (double_cur->next == double_cur) {
            root->free_list = NULL;
        }
        else if (double_cur->next_free_block == double_cur) {
      
            double_prev->next = double_cur->next;
            double_cur->next->prev = double_prev;

            
            block_t *head = double_cur->next;
            block_t *temp = head->next;

            while (temp != head) {
                if (temp->offset < head->offset) {
                    head = temp;
                }
                temp = temp->next;
            }

            root->free_list = head; 
        }

   
        else {
            
            block_t *single_prev = root->free_list;
            while (single_prev->next_free_block != double_cur) {
                single_prev = single_prev->next_free_block;
            }

            
            if (root->free_list == double_cur) {
                root->free_list = double_cur->next_free_block;
            } 

            single_prev->next_free_block = double_cur->next_free_block;
            double_prev->next = double_cur->next;
            double_cur->next->prev = double_prev;


            block_t *head = root->free_list;
            block_t *temp = head->next_free_block;

            do {
                if (temp->size < head->size) {
                    head = temp;
                }
                temp = temp->next_free_block;
            } while (temp != root->free_list);

            root->free_list = head;
            
        }

        
        double_cur->next = NULL;
        double_cur->prev = NULL;
        double_cur->next_free_block = NULL;
        free(double_cur);

        count++;
    }


    if (root->left != NULL) {
        count += remove_fragmented_blocks(root->left, min_size);
    }
    if (root->right != NULL) {
        count += remove_fragmented_blocks(root->right, min_size);
    }

    return count;

} /* remove_fragmented_blocks() */

/* 
 * removes all regions that don't have free blocks from BST
 */

int purge_empty_regions(region_t **root) {
    assert(root != NULL);
    int count = 0;

    if ((*root)->left != NULL) {
        count += purge_empty_regions(&((*root)->left));
    }
    if ((*root)->right != NULL) {
        count += purge_empty_regions(&((*root)->right));
    }

    if ((*root)->free_list == NULL) {
        region_t *region = *(root);

        if (region->left == NULL && region->right == NULL) {
            (*root) = NULL;
            free(region);
            count++;
        }
        else if (region->left == NULL && region->right != NULL) {
            (*root) = region->right;
            free(region);
            count++;
        }
        else if (region->left != NULL && region->right == NULL) {
            (*root) = region->left;
            free(region);
            count++;
        }
        else {
            region_t **replace = &(region -> left);

            while ((*replace)->right != NULL) {
                replace = &((*replace)->right);
            }

            (*root)->start_address = (*replace)->start_address;
            (*root)->free_list = (*replace)->free_list;

            region_t *temp = *replace;
            *replace = (*replace) -> left;
            free(temp);
            count++;
        }
    }

    return count;

} /* purge_empty_regions() */

/* 
 * helper function that returns the number of
 * free blocks in a given region
 */

int count_free_blocks(region_t *region) {
    if (region->free_list == NULL) return 0;

    block_t *start = region->free_list;
    
    if (start->state != BLOCK_FREE) return 0;

    int count = 0;
    block_t *cur = start;
    do {
        count++;
        cur = cur->next_free_block;
    } while (cur != start);

    return count;

} /* count_free_blocks() */

/* 
 * helper function that removes the smallest free block from a region
 */

block_t *remove_smallest_free(region_t *root) {

    block_t *start = root->free_list;

    block_t *double_cur = start;
    block_t *double_prev = start->prev;

    if (double_cur->next == double_cur) {
        root->free_list = NULL;

    }
    else if (double_cur->next_free_block == double_cur) {

        double_prev->next = double_cur->next;
        double_cur->next->prev = double_prev;

        block_t *head = double_cur->next;
        block_t *temp = head->next;

        while (temp != head) {
            if (temp->offset < head->offset) {
                head = temp;
            }
            temp = temp->next;
        }

        root->free_list = head; 

    } else {

        block_t *single_prev = root->free_list;
        while (single_prev->next_free_block != double_cur) {
            single_prev = single_prev->next_free_block;
        }

        if (root->free_list == double_cur) {
            root->free_list = double_cur->next_free_block;
        }

        single_prev->next_free_block = double_cur->next_free_block;
        double_prev->next = double_cur->next;
        double_cur->next->prev = double_prev;
    }

    double_cur->offset = (int) root->start_address + (int) double_cur->offset;

    return double_cur;

} /* remove_smallest_free() */


/* 
 * helper function that adds the smallest free block to a region
 */

void add_smallest_free(region_t *root, block_t *move) {
    move->offset = (int) move->offset - (int) root->start_address;

    if (root->free_list == NULL) {
        move->next = move;   
        move->prev = move;
        move->next_free_block = move;  
        root->free_list = move;
        return;
    }

    block_t *start = root->free_list;


    block_t *cur = start;
    block_t *double_head = start;
    do {
        if (cur->offset < double_head->offset) {
            double_head = cur;
        }
        cur = cur->next;
    } while (cur != start);

    block_t *double_cur = double_head;
    block_t *double_prev = double_head->prev; 

    if (move->offset <= double_head->offset) {
        double_prev->next = move;
        move->prev = double_prev;
        move->next = double_head;
        double_head->prev = move;

    } else {
        do {
            double_prev = double_cur;
            double_cur = double_cur->next;
        } while ((double_cur != double_head) && (double_cur->offset <= move->offset));

        double_prev->next = move;
        move->prev = double_prev;
        move->next = double_cur;
        double_cur->prev = move;
    }


    cur = start;
    block_t *single_head = start;
    do {
        if (cur->size < single_head->size) {
            single_head = cur;
        }
        cur = cur->next_free_block;
    } while (cur != start);


    block_t *single_tail = single_head;
    while (single_tail -> next_free_block != single_head) {
        single_tail = single_tail->next_free_block;
    }


    if (move->size < single_head->size) {
        single_tail->next_free_block = move;
        move->next_free_block = single_head;
        root->free_list = move;
        return;
    }


    block_t *single_prev = single_head;
    block_t *single_cur = single_head->next_free_block;
    while ((single_cur != single_head) && (single_cur->size <= move->size)) {
        single_prev = single_cur;
        single_cur = single_cur->next_free_block;
    }

    single_prev->next_free_block = move;
    move->next_free_block = single_cur;

    return;

} /* add_smallest_free() */



void print(region_t *root) {
    printf("REGION: %ld\n", root->start_address);
    block_t *cur = root->free_list;
    do {
        if (cur == NULL) break;
        printf("(%ld, %ld) ", cur->size, cur->offset);
        cur = cur->next;
    } while (cur != root->free_list);

    printf("\n--------\n");

    if (root->left != NULL) {
        printf("Left Child: %ld\n", root->left->start_address);
        cur = root->left->free_list;
        do {
            if (cur == NULL) break;
            printf("(%ld, %ld) ", cur->size, cur->offset);
            cur = cur->next;
        } while (cur != root->left->free_list);

    }
    printf("\n--------\n");

    if (root->right != NULL) {
        printf("Right Child: %ld\n", root->right->start_address);
        cur = root->right->free_list;
        do {
            if (cur == NULL) break;
            printf("(%ld, %ld) ", cur->size, cur->offset);
            cur = cur->next;
        } while (cur != root->right->free_list);
    }
    printf("\n--------\n");
}


int rebalance_free_blocks(region_t *root, size_t min_blocks) {
    assert(root != NULL);
    assert(min_blocks >= 0);

    int count = 0;

    if (root->left != NULL) {
        count += rebalance_free_blocks(root->left, min_blocks);
    }
    if (root->right != NULL) {
        count += rebalance_free_blocks(root->right, min_blocks);
    }

    int cur_blocks = count_free_blocks(root);

    if (cur_blocks < (int) min_blocks) {
        int needed = (int) min_blocks - cur_blocks;

        int left_free = (root->left != NULL) ? count_free_blocks(root->left)  : -1;
        int right_free = (root->right != NULL) ? count_free_blocks(root->right) : -1;

        region_t *child = NULL;
        int child_free = -1;

        if (root->left != NULL && root->right != NULL) {
            if (left_free >= right_free) {
                child = root->left;
                child_free = left_free;
            } else {
                child = root->right;
                child_free = right_free;
            }
        } else if (root->left != NULL) {
            child = root->left;
            child_free = left_free;
        } else if (root->right != NULL) {
            child = root->right;
            child_free = right_free;
        }

        if (child != NULL && (child_free - needed) >= (int)min_blocks) {

            printf("Min Size: %ld\n", min_blocks);

            for (int i = 0; i < needed; i++) {
                printf("BEFORE: ---------------------- \n");
                print(root);

                block_t *move = remove_smallest_free(child);
                add_smallest_free(root, move);
                count++;

                printf("AFTER: ----------------------- \n");
                print(root);

                printf("\n==================================\n");
            }
        }
    }

    return count;
}


size_t total_allocated_memory(region_t *root) {
    assert(root != NULL);

    int amount = 0;

    if (root->left != NULL) {
        amount += total_allocated_memory(root->left);
    }
    if (root->right != NULL) {
        amount += total_allocated_memory(root->right);
    }

    block_t *cur = root->free_list;

    do {
        if (cur == NULL) {
            break;
        }
        if (cur->state == BLOCK_ALLOCATED) {
            amount += cur->size;
        }
        cur = cur->next;
    } while (cur != root->free_list);

    return amount;
}



int find_best_region_size(region_t *root, size_t size) {
    if (root == NULL) return 0;

    int val = find_best_region_size(root->left, size);
    if (val != 0) {
        return val;
    }

    block_t *cur = root->free_list;
    do {
        if (cur == NULL) {
            break;
        }
        if (cur->size >= size) {
            if (val == 0 || cur->size < val) {
                val = cur->size;
            }
        }
        cur = cur->next_free_block;
    } while (cur != root->free_list);
    
    if (val != 0) return val;

    return find_best_region_size(root->right, size);
}


region_t *find_best_region(region_t *root, int size) {
    if (root == NULL) return NULL; 

    region_t *best = find_best_region(root->left, size);
    if (best != NULL) {
        return best;
    }

    block_t *cur = root->free_list;
    do {
        if (cur == NULL) {
            break;
        }
        if (cur->size == size) {
            return root;
        }
        cur = cur->next_free_block;
    } while (cur != root->free_list);
    

    return find_best_region(root->right, size);
}
    

void insert_free(region_t *root, block_t *move) {

    if (root->free_list == NULL) {
        move->next = move;   
        move->prev = move;
        move->next_free_block = move;  
        root->free_list = move;
        return;
    }

    block_t *start = root->free_list;

    // step 1: find head of double LL

    block_t *cur = start;
    block_t *double_head = start;
    do {
        if (cur->offset < double_head->offset) {
            double_head = cur;
        }
        cur = cur->next;
    } while (cur != start);
    
    // step 2: find where to insert it

    block_t *double_cur = double_head;
    block_t *double_prev = double_head->prev; // start from tail

    // if move belongs before the current head
    if (move->offset <= double_head->offset) {
        // insert before double_head (i.e. between tail and head)
        double_prev->next = move;
        move->prev = double_prev;
        move->next = double_head;
        double_head->prev = move;

    } else {
        // walk forward to find insertion point
        do {
            double_prev = double_cur;
            double_cur = double_cur->next;
        } while ((double_cur != double_head) && (double_cur->offset <= move->offset));

        double_prev->next = move;
        move->prev = double_prev;
        move->next = double_cur;
        double_cur->prev = move;
    }

    // step 3: find head of single LL

    cur = start;
    block_t *single_head = start;
    do {
        if (cur->size < single_head->size) {
            single_head = cur;
        }
        cur = cur->next_free_block;
    } while (cur != start);

    // step 4: find where to insert
    block_t *single_tail = single_head;
    while (single_tail -> next_free_block != single_head) {
        single_tail = single_tail->next_free_block;
    }

    // 4.1 edge case: inserting to the head position

    if (move->size < single_head->size) {
        single_tail->next_free_block = move;
        move->next_free_block = single_head;
        root->free_list = move;
        return;
    }

    // 4.2 insert normally

    block_t *single_prev = single_head;
    block_t *single_cur = single_head->next_free_block;
    while ((single_cur != single_head) && (single_cur->size <= move->size)) {
        single_prev = single_cur;
        single_cur = single_cur->next_free_block;
    }

    single_prev->next_free_block = move;
    move->next_free_block = single_cur;

    return;
}


/*
 * Find the best region to allocate the smallest free block with 
 * size at least request size
 */

intptr_t allocator_malloc(region_t *root, size_t request_size) {
    assert(root != NULL);
    assert(request_size > 0);

    // 1. find the smallest size, greater than request size
    int size = find_best_region_size(root, request_size);
    if (size == 0) {
        return 0;
    }
    printf("request size: %ld\n", request_size);
    printf("best size: %d\n", size);
    
    // 2. find the region and block with the given size
    region_t *region = find_best_region(root, size);
    printf("region found: %ld\n", region->start_address);

    block_t *double_cur = region->free_list;
    do {
        if (double_cur == NULL) {
            break;
        }
        if (double_cur->size == size) {
            break;
        }
        double_cur = double_cur->next_free_block;
    } while (double_cur != region->free_list);

    printf("block size: %ld\n", double_cur->size);

    if (double_cur->size == request_size) {
        // 3.1. all you have to do is to remove it from the CSLL
        double_cur->state = BLOCK_ALLOCATED;

        if (double_cur->next_free_block == double_cur) {
            block_t *head = double_cur->next;
            block_t *temp = head->next;
            while (temp != head) {
                if (temp->offset < head->offset) {
                    head = temp;
                }
                temp = temp->next;
            }
            region->free_list = head; 
        }
        else {
            block_t *single_prev = double_cur;
            while (single_prev->next_free_block != double_cur) {
                single_prev = single_prev->next_free_block;
            }

            if (region->free_list == double_cur) {
                region->free_list = double_cur->next_free_block;
            }

            single_prev->next_free_block = double_cur->next_free_block;
        }

        double_cur->next_free_block = NULL;

        return region->start_address + double_cur->offset;
    } 
    else if (double_cur->size > request_size) {
        // 3.2. must create another free block and insert it
        block_t *free = malloc(sizeof(block_t));
        free->size = double_cur->size - request_size;
        free->offset = double_cur->offset + request_size;
        free->state = BLOCK_FREE;


        double_cur->size = request_size;
        double_cur->state = BLOCK_ALLOCATED;

        if (double_cur->next_free_block == double_cur) {
            block_t *head = double_cur->next;
            block_t *temp = head->next;
            while (temp != head) {
                if (temp->offset < head->offset) {
                    head = temp;
                }
                temp = temp->next;
            }
            region->free_list = head; 
        }
        else {
            block_t *single_prev = double_cur;
            while (single_prev->next_free_block != double_cur) {
                single_prev = single_prev->next_free_block;
            }
            if (region->free_list == double_cur) {
                region->free_list = double_cur->next_free_block;
            }
            single_prev->next_free_block = double_cur->next_free_block;
        }

        double_cur->next_free_block = NULL;

        insert_free(region, free);
        
        return region->start_address + double_cur->offset;
    }

    return 0;

}



void delete_allocator(region_t **root) {
    assert(root != NULL);

    if ((*root) == NULL) {
        printf("NULL tree\n");
        return;
    }

    if ((*root)->left != NULL) {
        delete_allocator(&((*root)->left));
    }
    if ((*root)->right != NULL) {
        delete_allocator(&((*root)->right));
    }

    block_t *start = (*root)->free_list;
    block_t *cur = start;

    int count = 0;
    do {
        if (cur == NULL) {
            break;
        }
        cur = cur->next;
        count++;
    } while (cur != start);

    
    do {
        if (cur == NULL) break;
        block_t *temp = cur;
        cur = cur->next;
        free(temp);
        count--;

    } while (count > 0);

    free(*root);
    (*root) = NULL;

    return;
}
