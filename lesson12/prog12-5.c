/*********************************************
  prog12-5.c
    Student ID:
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arraytable-common.h"
#include "chaintable-common.h"
#include "measurement.h"

struct data *search_array(struct table *table, int key) {
  /* Copied from prog12-1.c */
  return NULL;
}

int insert_array(struct table *table, struct data data) {
  /* Copied from prog12-1.c */
  return 0;
}

struct data *search_binary(struct table *table, int key) {
  /* Copied from prog12-2.c */
  return NULL;
}

int insert_binary(struct table *table, struct data data) {
  /* Copied from prog12-2.c */
  return 0;
}

struct chain_data *search_chain(struct chain_table *table, int key) {
  /* Copied from prog12-3.c */
  return NULL;
}

int insert_chain(struct chain_table *table, struct chain_data data) {
  /* Copied from prog12-3.c */
  return 0;
}

int main() {
  measure("LINEAR SEARCH", insert_array, search_array, -1);
  measure("BINARY SEARCH", insert_binary, search_binary, -1);
  measure_chain("HASH-CHAIN", insert_chain, search_chain, 1000);

  return 0;
}
