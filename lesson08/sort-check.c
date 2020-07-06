/*
  sort-check.c
*/

#include <stdio.h>

#include "sort-common.h"

void print(struct data data[], int num) {
  if (num == 0) {
    printf("No element\n");
    return;
  }

  int i;
  for (i = 0; i < num; i++) {
    printf(" %d:%c", data[i].key, data[i].value);
  }
  printf("\n");
}

int is_sorted(struct data data[], int num) {
  int i;
  for (i = 0; i < num - 1; i++) {
    if (data[i].key > data[i + 1].key) {
      return 0;
    }
  }
  return 1;
}
