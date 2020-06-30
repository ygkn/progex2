/*********************************************
  prog3-1.c
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

/*=============================================*/

void test1() {
  struct list *list = create_list();

  list->top = create_element(10);
  list->top->next = create_element(20);
  list->top->next->next = create_element(30);

  print_list(list);
}

int main() {
  test1();

  return 0;
}
