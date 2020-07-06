/*********************************************
  prog8-1.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>

#include "sort-common.h"

/*=============================================*/

void test1() {
  struct data data[] = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};

  int num = sizeof(data) / sizeof(data[0]);

  print(data, num);
  assert(is_sorted(data, num));

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
