/*********************************************
  prog12-4.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "arraytable-common.h"

struct data *search_opem(struct table *table, int key);
int insert_open(struct table *table, struct data data);
int delete_open(struct table *table, int key);

int hash(int key, int size) { return key % size; }

int rehash(int hkey, int size) { return (hkey + 1) % size; }

struct data *search__open(struct table *table, int key) {
  return NULL;
}

int insert_open(struct table *table, struct data data) { return 0; }

int delete_open(struct table *table, int key) { return 0; }

/*=============================================*/

void test1() {}

int main() {
  test1();

  return 0;
}
