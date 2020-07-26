/*
  queue.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree-common.h"
#include "queue.h"

struct queue *create_queue(int size)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    if (queue == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        queue->size = size;
        queue->top = 0;
        queue->rear = 0;
    }
    return queue;
}

int enqueue(struct queue *queue, struct node *node)
{
    if (queue->rear >= queue->size) {
        return -1;
    } else {
        queue->data[queue->rear] = node;
        queue->rear++;
        return 0;
    }
}

struct node *dequeue(struct queue *queue)
{
    if (queue->rear - queue->top == 0) {
        return NULL;
    } else {
        queue->top++;
        struct node *node = queue->data[queue->top - 1];
        return node;
    }
}

int is_empty_queue(struct queue *queue)
{
    if (queue->rear - queue->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

int size_of_queue(struct queue *queue)
{
    return queue->rear - queue->top;
}

struct node *get_in_queue(struct queue *queue, int index)
{
    return queue->data[queue->top + index];
}
