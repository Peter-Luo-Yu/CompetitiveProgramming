#ifndef HW11_H
#define HW11_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
  BLOCK_FREE = 0,
  BLOCK_ALLOCATED = 1,
} block_state_t;

typedef struct block_struct {
  size_t size;
  intptr_t offset;
  block_state_t state;
  struct block_struct *next; // double ll, head is smallest offset
  struct block_struct *prev;
  struct block_struct *next_free_block; // single ll, head is smallest block by size
} block_t;

typedef struct region_struct {
  intptr_t start_address;
  block_t *free_list; // points to head of CSLL, unless double.
  struct region_struct *left;
  struct region_struct *right;
} region_t;

region_t *create_region(intptr_t);
void add_free_block(region_t *, size_t);
void insert_region(region_t **, region_t *);
int remove_fragmented_blocks(region_t *, size_t);
int purge_empty_regions(region_t **);
int rebalance_free_blocks(region_t *, size_t);
size_t total_allocated_memory(region_t *);
intptr_t allocator_malloc(region_t *, size_t);
void delete_allocator(region_t **);

#endif // HW11_H
