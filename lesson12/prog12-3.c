/*********************************************
  prog12-3.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "chaintable-common.h"

struct chain_data *search_chain(struct chain_table *table, int key);
int insert_chain(struct chain_table *table, struct chain_data data);
int delete_chain(struct chain_table *table, int key);

int hash(int key, int size) { return key % size; }

struct chain_data *search_chain(struct chain_table *table, int key) {
  return NULL;
}

int insert_chain(struct chain_table *table, struct chain_data data) {
  return 0;
}

int delete_chain(struct chain_table *table, int key) { return 0; }

/*=============================================*/

void test1() {}

int main() {
  test1();

  return 0;
}
