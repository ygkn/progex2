/*********************************************
  prog6-3.c
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
void print_quque(struct queue *queue);

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

/*=============================================*/

void test1() {
  struct queue *queue = create_queue();

  assert(size_of_queue(queue) == 0);
  print_queue(queue);

  queue->data[0] = 10;
  queue->rear = 1;
  assert(queue->data[0] == 10);
  assert(size_of_queue(queue) == 1);
  print_queue(queue);

  queue->data[1] = 20;
  queue->rear = 2;
  assert(queue->data[0] == 10);
  assert(queue->data[1] == 20);
  assert(size_of_queue(queue) == 2);
  print_queue(queue);

  queue->top = 1;
  assert(queue->data[1] == 20);
  assert(size_of_queue(queue) == 1);
  print_queue(queue);

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
