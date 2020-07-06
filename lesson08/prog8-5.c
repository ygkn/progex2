/*********************************************
  prog8-5.c
    Student ID:
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "measurement.h"
#include "sort-common.h"

void bubble_sort(struct data data[], int num) {
  /* Code copied from prog8-2.c */
}

void selection_sort(struct data data[], int num) {
  /* Code copied from prog8-3.c */
}

void insertion_sort(struct data data[], int num) {
  /* Code copied from prog8-4.c */
}

int main() {
  measure("BUBBLE SORT", bubble_sort);
  measure("SELECTION SORT", selection_sort);
  measure("INSERION SORT", insertion_sort);

  return 0;
}
