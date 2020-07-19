/*
  chaintable-common.h
*/

#ifndef CHAIN_TABLE_COMMON_H
#define CHAIN_TABLE_COMMON_H

#include <stdio.h>

struct chain_data {
    int key;
    char value;
    struct chain_data *next;
};

struct chain_table {
    struct chain_data **data;
    int size;
    int num;
};

extern struct chain_table *create_chain_table(int size);
extern void print_chain(struct chain_table *table);

#endif /* CHAIN_TABLE_COMMON_H */
