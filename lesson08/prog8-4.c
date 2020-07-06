/*********************************************
  prog8-4.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>

#include "sort-common.h"

void insertion_sort(struct data data[], int num);

void insertion_sort(struct data data[], int num) {
  for (int i = 1; i < num; i++) {
    int cur = i;
    while ((cur > 0) && (data[cur - 1].key > data[cur].key)) {
      struct data temp = data[cur - 1];
      data[cur - 1] = data[cur];
      data[cur] = temp;
      cur--;
    }
  }
}

/*=============================================*/

void test1() {}

int main() {
  test1();

  return 0;
}
