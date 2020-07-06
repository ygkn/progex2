/*********************************************
  prog8-2.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>

#include "sort-common.h"

void bubble_sort(struct data data[], int num);

void bubble_sort(struct data data[], int num) {
  for (int i = 0; i < num - 1; i++) {
    for (int cur = num - 1; cur >= i + 1; cur--) {
      if ((data + cur)->key < (data + cur - 1)->key) {
        struct data temp = data[cur];
        data[cur] = data[cur - 1];
        data[cur - 1] = temp;
      }
    }
  }
}

/*=============================================*/

void test1() {
  struct data data[] = {{21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'},
                        {1, 'f'},  {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
  int num = sizeof(data) / sizeof(data[0]);

  print(data, num);
  bubble_sort(data, num);
  print(data, num);

  assert(is_sorted(data, num));

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
