/*********************************************
  prog7-1.c
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

struct stack {
  struct element *top;
  int size;
};

struct stack *create_stack();
struct element *create_element(int value);
int size_of_stack(struct stack *stack);

void push(struct stack *stack, int value);
int pop(struct stack *stack);
int peek(struct stack *stack);
int is_empty(struct stack *stack);

void print_stack(struct stack *stack);

struct stack *create_stack() {
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  if (stack == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    stack->top = NULL;
    stack->size = 0;
  }
  return stack;
}

struct element *create_element(int value) {
  struct element *elem = (struct element *)malloc(sizeof(struct element));
  if (elem == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    elem->value = value;
    elem->next = NULL;
  }
  return elem;
}

int size_of_stack(struct stack *stack) { return stack->size; }

void push(struct stack *stack, int value) {
  struct element *newElement = create_element(value);
  newElement->next = stack->top;
  stack->top = newElement;
  stack->size += 1;
}

int pop(struct stack *stack) {
  int value;
  struct element *top;

  if (is_empty(stack)) return -1;

  value = stack->top->value;
  top = stack->top;

  stack->top = stack->top->next;
  free(top);

  stack->size -= 1;

  return value;
}

int peek(struct stack *stack) {
  if (is_empty(stack)) return -1;

  return stack->top->value;
}

int is_empty(struct stack *stack) { return size_of_stack(stack) == 0; }

void print_stack(struct stack *stack) {
  if (stack->size == 0) {
    printf("No element\n");
    return;
  }

  int *data = (int *)calloc(stack->size, sizeof(int));
  int *p = data + stack->size - 1;
  struct element *cur = stack->top;
  while (cur != NULL) {
    *p = cur->value;
    p--;
    cur = cur->next;
  }
  int i;
  for (i = 0; i < stack->size; i++) {
    printf(" %d", data[i]);
  }
  printf("\n");
}

/*=============================================*/

void test1() {
  struct stack *stack = create_stack();
  assert(stack->size == 0);
  assert(stack->top == NULL);
  print_stack(stack);

  free(stack);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct element *element = create_element(10);
  assert(element->value == 10);
  assert(element->next == NULL);

  free(element);
  printf("Success: %s\n", __func__);
}

void test3() {
  struct stack *stack = create_stack();

  push(stack, 10);
  assert(stack->top->value == 10);

  push(stack, 20);
  assert(stack->top->value == 20);
  assert(stack->top->next->value == 10);

  print_stack(stack);

  free(stack->top->next);
  free(stack->top);
  free(stack);

  printf("Success: %s\n", __func__);
}

void test4() {
  struct stack *stack = create_stack();

  push(stack, 10);
  push(stack, 20);

  assert(size_of_stack(stack) == 2);

  print_stack(stack);

  free(stack->top->next);
  free(stack->top);
  free(stack);

  printf("Success: %s\n", __func__);
}

void test5() {
  struct stack *stack = create_stack();

  assert(pop(stack) == -1);

  push(stack, 10);
  push(stack, 20);

  assert(pop(stack) == 20);
  assert(stack->size == 1);

  assert(pop(stack) == 10);
  assert(stack->size == 0);

  assert(pop(stack) == -1);

  print_stack(stack);

  free(stack);

  printf("Success: %s\n", __func__);
}

void test6() {
  struct stack *stack = create_stack();

  assert(pop(stack) == -1);

  push(stack, 10);

  assert(peek(stack) == 10);
  assert(stack->size == 1);

  pop(stack);

  print_stack(stack);

  free(stack);

  printf("Success: %s\n", __func__);
}

void test7() {
  struct stack *stack = create_stack();

  assert(is_empty(stack));

  push(stack, 10);

  assert(!is_empty(stack));

  print_stack(stack);

  pop(stack);

  free(stack);

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

  return 0;
}
