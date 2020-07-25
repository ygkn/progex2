/*********************************************
  prog13-1.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list-common.h"

struct data *search_list(struct list *list, int key);
int insert_list(struct list *list, struct data data);
int delete_list(struct list *list, int key);

struct data *search_list(struct list *list, int key) {
  return NULL;
}

int insert_list(struct list *list, struct data data) { return 0; }

int delete_list(struct list *list, int key) { return 0; }

/*=============================================*/

void test1() {
  struct data data[] = {{21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'},
                        {1, 'f'},  {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
  int num = sizeof(data) / sizeof(data[0]);

  struct list *list = create_list();

  assert(search_list(list, 1) == NULL);

  int i;
  for (i = 0; i < num; i++) {
    insert_list(list, data[i]);
  }

  assert(search_list(list, 1)->value == 'f');

  assert(insert_list(list, data[0]) == 0);

  assert(delete_list(list, 1) == 1);

  assert(search_list(list, 1) == NULL);

  assert(delete_list(list, 1) == 0);

  print(list);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
