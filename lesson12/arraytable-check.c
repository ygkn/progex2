/*
  arraytable-check.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "arraytable-common.h"

struct table *create_table(int size) {
  struct table *table = (struct table *)malloc(sizeof(struct table));
  if (table == NULL) {
    fprintf(stderr, "Not enough memory\n");
    return NULL;
  }

  table->data = (struct data **)calloc(size, sizeof(struct data *));
  if (table->data == NULL) {
    fprintf(stderr, "Not enough memory\n");
    return NULL;
  }

  int i;
  for (i = 0; i < size; i++) {
    table->data[i] = NULL;
  }
  table->num = 0;
  table->size = size;
  return table;
}

void print(struct table *table) {
  if (table->num == 0) {
    printf("No element\n");
    return;
  }

  int i;
  for (i = 0; i < table->size; i++) {
    if (table->data[i] != NULL) {
      printf(" %d:%c", table->data[i]->key, table->data[i]->value);
    } else {
      printf(" []");
    }
  }
  printf("\n");
}

int cmp(const void *x, const void *y) {
  struct data *sx = (struct data *)x;
  struct data *sy = (struct data *)y;

  return (*sx).key - (*sy).key;
}

void sort(struct data data[], int num) {
  qsort(data, num, sizeof(struct data), cmp);
}

int is_sorted(struct data *data[], int num) {
  int i;
  for (i = 0; i < num - 1; i++) {
    if (data[i]->key > data[i + 1]->key) {
      return 0;
    }
  }
  return 1;
}
