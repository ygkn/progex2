/*********************************************
  prog3-3.c
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
  int size;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rearm(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

int size_of_list(struct list *list);
struct element *get_from_list(struct list *list, int index);
void insert_at(struct list *list, int index, struct element *elem);
void delete_at(struct list *list, int index);

struct list *create_list() {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  if (list == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    list->top = NULL;
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

int size_of_list(struct list *list) {
  int length = 0;

  for (struct element *current = list->top; current != NULL;
       current = current->next) {
    length += 1;
  }

  return length;
}

struct element *get_from_list(struct list *list, int index) {
  if (index < 0 || size_of_list(list) <= index) {
    return NULL;
  }

  struct element *current = list->top;

  for (int currentIndex = 0; currentIndex < index; currentIndex++) {
    current = current->next;
  }

  return current;
}

void insert_at(struct list *list, int index, struct element *elem) {
  if (index < 0 || size_of_list(list) < index) return;

  if (index == 0) {
    insert_front(list, elem);
    return;
  }

  struct element *prev = get_from_list(list, index - 1);
  elem->next = prev->next->next;
  prev->next = elem;
}

void delete_at(struct list *list, int index) {
  if (index < 0 || size_of_list(list) <= index) return;

  if (index == 0) {
    delete_front(list);
    return;
  }

  struct element *prev = get_from_list(list, index - 1);
  prev->next = prev->next->next;
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

void test5() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));
  insert_front(list, create_element(30));

  assert(size_of_list(list) == 3);

  assert(size_of_list(create_list()) == 0);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test6() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));
  insert_front(list, create_element(30));

  assert(get_from_list(list, 2)->value == 10);

  assert(get_from_list(list, 3) == NULL);
  assert(get_from_list(list, -1) == NULL);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test7() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));

  insert_at(list, 1, create_element(30));

  assert(get_from_list(list, 1)->value == 30);

  insert_at(list, 0, create_element(40));

  assert(get_from_list(list, 0)->value == 40);

  insert_at(list, 4, create_element(30));
  insert_at(list, -1, create_element(30));

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test8() {
  struct list *list = create_list();

  insert_front(list, create_element(10));
  insert_front(list, create_element(20));
  insert_front(list, create_element(30));

  delete_at(list, 1);

  assert(get_from_list(list, 1)->value == 10);

  delete_at(list, 0);
  assert(get_from_list(list, 0)->value == 10);

  delete_at(list, 2);
  delete_at(list, -1);

  print_list(list);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();

  return 0;
}
