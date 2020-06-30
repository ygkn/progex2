/*********************************************
  prog6-4.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 30

struct queue {
  int data[QUEUE_MAX_SIZE];
  int top;
  int rear;
};

struct queue *create_queue();
int size_of_queue(struct queue *queue);
void print_queue(struct queue *queue);

int enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
int peek(struct queue *queue);
int is_empty(struct queue *queue);

struct queue *create_queue() {
  struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
  if (queue == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    queue->top = 0;
    queue->rear = 0;
  }
  return queue;
}

int size_of_queue(struct queue *queue) { return queue->rear - queue->top; }

void print_queue(struct queue *queue) {
  if (queue->rear - queue->top == 0) {
    printf("No element\n");
    return;
  }

  int i;
  for (i = queue->top; i < queue->rear; i++) {
    printf(" %d", queue->data[i]);
  }
  printf("\n");
}

int enqueue(struct queue *queue, int value) {
  if (queue->rear >= QUEUE_MAX_SIZE) {
    return 0;
  }

  queue->data[queue->rear] = value;
  queue->rear += 1;
  return 1;
}

int dequeue(struct queue *queue) {
  if (is_empty(queue)) {
    return -1;
  }

  queue->top += 1;

  return queue->data[queue->top - 1];
}

int peek(struct queue *queue) {
  if (is_empty(queue)) {
    return -1;
  }

  return queue->data[queue->top];
}

int is_empty(struct queue *queue) { return size_of_queue(queue) == 0; }

/*=============================================*/

void test1() {
  struct queue *queue = create_queue();

  assert(size_of_queue(queue) == 0);
  assert(dequeue(queue) == -1);
  assert(peek(queue) == -1);
  assert(is_empty(queue));
  print_queue(queue);

  enqueue(queue, 10);
  assert(queue->data[0] == 10);
  assert(size_of_queue(queue) == 1);
  print_queue(queue);

  enqueue(queue, 20);
  assert(queue->data[0] == 10);
  assert(queue->data[1] == 20);
  assert(size_of_queue(queue) == 2);
  print_queue(queue);

  assert(peek(queue) == 10);
  assert(dequeue(queue) == 10);
  assert(queue->data[1] == 20);
  assert(size_of_queue(queue) == 1);
  print_queue(queue);

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
