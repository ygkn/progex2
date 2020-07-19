/*********************************************
  prog12-2.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "arraytable-common.h"

#define DATA_SIZE (20)

struct data *search_binary(struct table *table, int key);
int insert_binary(struct table *table, struct data data);
int delete_binary(struct table *table, int key);

struct data *search_binary(struct table *table, int key) {
  int left = 0;
  int right = table->num - 1;

  while (right >= left) {
    int center = left + (right - left) / 2;

    if (table->data[center]->key == key) {
      return table->data[center];
    } else if (table->data[center]->key < key) {
      left = center + 1;
      continue;
    } else {
      right = center - 1;
      continue;
    }
  }

  return NULL;
}

int insert_binary(struct table *table, struct data data) {
  if (search_binary(table, data.key) != NULL) {
    return 0;
  }

  struct data *newData = (struct data *)malloc(sizeof(struct data));

  *(newData) = data;

  int target;

  for (target = table->num; target > 0; target--) {
    if (table->data[target - 1]->key < newData->key) {
      break;
    } else {
      table->data[target] = table->data[target - 1];
    }
  }

  table->data[target] = newData;
  table->num++;

  return 1;
}

int delete_binary(struct table *table, int key) {
  if (search_binary(table, key) == NULL) {
    return 0;
  }

  for (int index = 0; index < table->num; index++) {
    if (table->data[index]->key > key) {
      table->data[index - 1] = table->data[index];
    }
  }

  table->num--;

  return 1;
}

/*=============================================*/
void test1() {
  struct data data[] = {{21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'},
                        {1, 'f'},  {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
  int num = sizeof(data) / sizeof(data[0]);

  sort(data, num);

  struct table *table = create_table(DATA_SIZE);

  print(table);

  assert(search_binary(table, 1) == NULL);

  int i;
  for (i = 0; i < num; i++) {
    assert(insert_binary(table, data[i]) == 1);
    print(table);
  }

  assert(insert_binary(table, data[0]) == 0);

  assert(search_binary(table, 1)->value == 'f');
  print(table);

  assert(delete_binary(table, 1) == 1);
  print(table);

  assert(delete_binary(table, 1) == 0);
  print(table);

  assert(search_binary(table, 1) == NULL);

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
