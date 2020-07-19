/*********************************************
  prog12-1.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "arraytable-common.h"

#define DATA_SIZE (20)

struct data *search_array(struct table *table, int key);
int insert_array(struct table *table, struct data data);
int delete_array(struct table *table, int key);

struct data *search_array(struct table *table, int key) {
  for (int index = 0; index < table->num; index++) {
    if (table->data[index]->key == key) {
      return table->data[index];
    }
  }

  return NULL;
}

int insert_array(struct table *table, struct data data) {
  if (search_array(table, data.key) != NULL) {
    return 0;
  }

  struct data *newData = (struct data *)malloc(sizeof(struct data));

  *(newData) = data;

  table->data[table->num] = newData;
  table->num++;

  return 1;
}

int delete_array(struct table *table, int key) {
  if (table->num == 0) return 0;

  int found = 0;

  for (int index = 0; index < table->num; index++) {
    if (found) {
      table->data[index - 1] = table->data[index];
    } else if (table->data[index]->key == key) {
      found = 1;
    }
  }

  if (found) {
    table->num--;
    table->data[table->num] = NULL;
    return 1;
  }

  return 0;
}

/*=============================================*/

void test1() {
  struct data data[] = {{21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'},
                        {1, 'f'},  {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
  int num = sizeof(data) / sizeof(data[0]);

  struct table *table = create_table(DATA_SIZE);

  print(table);

  assert(search_array(table, 1) == NULL);

  int i;
  for (i = 0; i < num; i++) {
    assert(insert_array(table, data[i]) == 1);
    print(table);
  }

  assert(insert_array(table, data[0]) == 0);

  assert(search_array(table, 1)->value == 'f');
  print(table);

  assert(delete_array(table, 1) == 1);
  print(table);

  assert(delete_array(table, 1) == 0);
  print(table);

  assert(search_array(table, 1) == NULL);

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
