/*
  list-common.h
*/

#ifndef CHAIN_TABLE_COMMON_H
#define CHAIN_TABLE_COMMON_H

#include <stdio.h>

struct data {
  int key;
  char value;
};

struct element {
  struct data *data;
  struct element *next;
};

struct list {
  struct element *top;
};

extern struct list *create_list();
extern void print(struct list *list);

#endif /* LIST_TABLE_COMMON_H */
