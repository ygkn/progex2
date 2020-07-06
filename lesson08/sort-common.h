/*
  sort-common.h
*/

#ifndef SORT_COMMON_H
#define SORT_COMMON_H

#include <stdio.h>

struct data {
  int key;
  char value;
};

extern void print(struct data data[], int num);
extern int is_sorted(struct data data[], int num);

#endif /* SORT_COMMON_H */
