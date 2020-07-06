/*********************************************
  prog8-2.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>

#include "sort-common.h"

void bubble_sort(struct data data[], int num);

void bubble_sort(struct data data[], int num) {}

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
