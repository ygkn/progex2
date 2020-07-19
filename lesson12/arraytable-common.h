/*
  arraytable-common.h
*/

#ifndef ARRAY_TABLE_COMMON_H
#define ARRAY_TABLE_COMMON_H

#include <stdio.h>

struct data {
    int key;
    char value;
};

struct table {
    struct data **data;
    int size;
    int num;
};

extern struct table *create_table(int size);
extern void print(struct table *table);

extern void sort(struct data data[], int num);
extern int is_sorted(struct data *data[], int num);

#endif /* ARRAY_TABLE_COMMON_H */
