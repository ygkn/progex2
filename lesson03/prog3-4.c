/*********************************************
  prog3-4.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct element {
  int value;
  struct element *next;
};

struct list {
  struct element *top;
  struct element *rear;
  int size;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

int size_of_list(struct list *list);
struct element *get_from_list(struct list *list, int index);
void insert_at(struct list *list, int index, struct element *elem);
void delete_at(struct list *list, int index);
struct list *append(struct list *first, struct list *second);

struct list *create_list() {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  if (list == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    list->top = NULL;
    list->rear = NULL;
    list->size = 0;
  }
  return list;
}

struct element *create_element(int value) {
  struct element *elem = (struct element *)malloc(sizeof(struct element));
  if (elem == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    elem->value = value;
  }
  return elem;
}

void print_list(struct list *list) {}

void insert_front(struct list *list, struct element *elem) {}

void insert_rear(struct list *list, struct element *elem) {}

void delete_front(struct list *list) {}

void delete_rear(struct list *list) {}

int size_of_list(struct list *list) { return 0; }

struct element *get_from_list(struct list *list, int index) {
  return NULL;
}

void insert_at(struct list *list, int index, struct element *elem) {}

void delete_at(struct list *list, int index) {}

struct list *append(struct list *first, struct list *second) {
  return NULL;
}

/*=============================================*/

void test1() {}

int main() {
  test1();

  return 0;
}
