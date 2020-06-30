/*********************************************
  prog6-2.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 30

struct stack {
  int data[STACK_SIZE];
  int top;
};

struct stack *create_stack();
int size_of_stack(struct stack *stack);
void print_stack(struct stack *stack);

int push(struct stack *stack, int value);
int pop(struct stack *stack);
int peek(struct stack *stack);
int is_empty(struct stack *stack);

struct stack *create_stack() {
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  if (stack == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    stack->top = 0;
  }
  return stack;
}

int size_of_stack(struct stack *stack) { return stack->top; }

void print_stack(struct stack *stack) {
  if (stack->top == 0) {
    printf("No element\n");
    return;
  }

  int i;
  for (i = 0; i < stack->top; i++) {
    printf(" %d", stack->data[i]);
  }
  printf("\n");
}

int push(struct stack *stack, int value) {
  if (size_of_stack(stack) >= STACK_SIZE) {
    return 0;
  }

  stack->data[stack->top] = value;
  stack->top += 1;
  return 1;
}

int pop(struct stack *stack) {
  if (is_empty(stack)) {
    return -1;
  }

  stack->top -= 1;
  return stack->data[stack->top + 1];
}

int peek(struct stack *stack) {
  if (is_empty(stack)) {
    return -1;
  }

  return stack->data[stack->top - 1];
}

int is_empty(struct stack *stack) { return size_of_stack(stack) == 0; }

/*=============================================*/

void test1() {
  struct stack *stack = create_stack();

  assert(size_of_stack(stack) == 0);
  assert(pop(stack) == -1);
  assert(peek(stack) == -1);
  assert(is_empty(stack));
  print_stack(stack);

  push(stack, 10);
  assert(stack->data[0] == 10);
  assert(size_of_stack(stack) == 1);
  assert(!is_empty(stack));
  print_stack(stack);

  push(stack, 20);
  assert(stack->data[0] == 10);
  assert(stack->data[1] == 20);
  assert(size_of_stack(stack) == 2);
  print_stack(stack);

  assert(peek(stack) == 20);
  assert(pop(stack) == 20);

  assert(stack->data[0] == 10);
  assert(size_of_stack(stack) == 1);
  print_stack(stack);

  printf("Success: %s\n", __func__);
}

void test2() {
  struct stack *stack = create_stack();

  push(stack, 10);
  assert(stack->data[0] == 10);
  assert(size_of_stack(stack) == 1);

  push(stack, 20);
  assert(stack->data[0] == 10);
  assert(stack->data[1] == 20);
  assert(size_of_stack(stack) == 2);

  push(stack, 30);
  assert(stack->data[0] == 10);
  assert(stack->data[1] == 20);
  assert(stack->data[2] == 30);
  assert(size_of_stack(stack) == 3);

  print_stack(stack);
  printf("Success: %s\n", __func__);
}

void test3() {
  struct stack *stack = create_stack();

  push(stack, 10);
  assert(stack->data[0] == 10);
  assert(size_of_stack(stack) == 1);

  push(stack, 20);
  assert(stack->data[0] == 10);
  assert(stack->data[1] == 20);
  assert(size_of_stack(stack) == 2);

  assert(pop(stack) == 20);

  assert(size_of_stack(stack) == 1);

  print_stack(stack);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}
