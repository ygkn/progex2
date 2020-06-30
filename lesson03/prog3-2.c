/*********************************************
  prog3-2.c
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
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

struct list *create_list() {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  if (list == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    list->top = NULL;
  }
  return list;
  return NULL;
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

void print_list(struct list *list) {
  for (struct element *current = list->top; current != NULL;
       current = current->next) {
    printf(" %d", current->value);
  }
  puts("");
}

void insert_front(struct list *list, struct element *elem) {
  elem->next = list->top;
  list->top = elem;
}

void insert_rear(struct list *list, struct element *elem) {
  struct element *current = list->top;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = elem;
}

void delete_front(struct list *list) {
  if (list->top == NULL) return;

  list->top = list->top->next;
}

void delete_rear(struct list *list) {
  if (list->top == NULL) return;

  if (list->top->next == NULL) {
    list->top = NULL;
    return;
  }

  struct element *current = list->top;

  while (current->next->next != NULL) {
    current = current->next;
  }

  current->next = NULL;
}

/*=============================================*/

void test1() {
  struct list *list = create_list();

  struct element *new1 = create_element(10);
  insert_front(list, new1);
  assert(list->top->value == 10);

  struct element *new2 = create_element(20);
  insert_front(list, new2);
  assert(list->top->value == 20);
  assert(list->top->next->value == 10);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));

  insert_rear(list, create_element(30));

  assert(list->top->next->next->value == 30);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test3() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));

  delete_front(list);

  assert(list->top->value == 10);

  delete_front(list);

  assert(list->top == NULL);

  delete_front(list);

  assert(list->top == NULL);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test4() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));

  delete_rear(list);

  assert(list->top->value == 20);

  delete_rear(list);

  assert(list->top == NULL);

  delete_rear(list);

  assert(list->top == NULL);

  print_list(list);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();
  test3();
  test4();

  return 0;
}
