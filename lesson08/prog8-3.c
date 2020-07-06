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

void test1() {
  struct data data[] = {{3, 'c'}, {1, 'a'}, {3, 'd'}, {2, 'b'}};
  int num = sizeof(data) / sizeof(data[0]);

  print(data, num);
  selection_sort(data, num);
  print(data, num);

  assert(is_sorted(data, num));

  printf("Success: %s\n", __func__);
}

void test2() {
  struct data data[] = {{3, 'c'}, {2, 'b'}, {3, 'd'}, {1, 'a'}};
  int num = sizeof(data) / sizeof(data[0]);

  print(data, num);
  selection_sort(data, num);
  print(data, num);

  assert(is_sorted(data, num));

  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();

  return 0;
}
