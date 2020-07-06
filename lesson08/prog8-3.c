/*********************************************
  prog8-3.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>

#include "sort-common.h"

void selection_sort(struct data data[], int num);

void selection_sort(struct data data[], int num) {
  for (int i = 0; i < num; i++) {
    int min = i;
    for (int cur = i + 1; cur < num; cur++) {
      if (data[min].key > data[cur].key) {
        min = cur;
      }
    }

    struct data temp = data[i];
    data[i] = data[min];
    data[min] = temp;
  }
}

/*=============================================*/

void test1() {}

int main() {
  test1();

  return 0;
}
