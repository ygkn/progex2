/*********************************************
  prog7-2.c
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

struct queue {
  struct element *top;
  int size;
};

struct queue *create_queue();
struct element *create_element(int value);
int size_of_queue(struct queue *queue);

void enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
int peek(struct queue *queue);
int is_empty(struct queue *queue);

void print_queue(struct queue *queue);

struct queue *create_queue() {
  struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
  if (queue == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    queue->top = NULL;
    queue->size = 0;
  }
  return queue;
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

int size_of_queue(struct queue *queue) { return queue->size; }

void enqueue(struct queue *queue, int value) {
  struct element *newElement = create_element(value);
  struct element *current = queue->top;

  queue->size += 1;

  if (current == NULL) {
    queue->top = newElement;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newElement;
}

int dequeue(struct queue *queue) {
  int value;
  struct element *top;

  if (is_empty(queue)) return -1;

  value = queue->top->value;
  top = queue->top;

  queue->top = queue->top->next;
  free(top);

  queue->size -= 1;

  return value;
}

int peek(struct queue *queue) {
  if (is_empty(queue)) return -1;

  return queue->top->value;
}

int is_empty(struct queue *queue) { return size_of_queue(queue) == 0; }

void print_queue(struct queue *queue) {
  if (queue->size == 0) {
    printf("No element\n");
    return;
  }

  struct element *cur = queue->top;
  while (cur != NULL) {
    printf(" %d", cur->value);
    cur = cur->next;
  }
  printf("\n");
}

/*=============================================*/

void test1() {
  struct queue *queue = create_queue();
  assert(queue->size == 0);
  assert(queue->top == NULL);
  print_queue(queue);

  free(queue);
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
  struct queue *queue = create_queue();

  enqueue(queue, 10);
  assert(queue->top->value == 10);

  enqueue(queue, 20);
  assert(queue->top->value == 10);
  assert(queue->top->next->value == 20);

  print_queue(queue);

  free(queue->top->next);
  free(queue->top);
  free(queue);

  printf("Success: %s\n", __func__);
}

void test4() {
  struct queue *queue = create_queue();

  enqueue(queue, 10);
  enqueue(queue, 20);

  assert(size_of_queue(queue) == 2);

  print_queue(queue);

  free(queue->top->next);
  free(queue->top);
  free(queue);

  printf("Success: %s\n", __func__);
}

void test5() {
  struct queue *queue = create_queue();

  assert(dequeue(queue) == -1);

  enqueue(queue, 10);
  enqueue(queue, 20);

  assert(dequeue(queue) == 10);
  assert(queue->size == 1);

  assert(dequeue(queue) == 20);
  assert(queue->size == 0);

  assert(dequeue(queue) == -1);

  print_queue(queue);

  free(queue);

  printf("Success: %s\n", __func__);
}

void test6() {
  struct queue *queue = create_queue();

  assert(dequeue(queue) == -1);

  enqueue(queue, 10);

  assert(peek(queue) == 10);
  assert(queue->size == 1);

  dequeue(queue);

  print_queue(queue);

  free(queue);

  printf("Success: %s\n", __func__);
}

void test7() {
  struct queue *queue = create_queue();

  assert(is_empty(queue));

  enqueue(queue, 10);

  assert(!is_empty(queue));

  print_queue(queue);

  dequeue(queue);
  free(queue);

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
