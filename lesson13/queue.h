/*
  queue.h
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "tree-common.h"

#define MAX_NODE_NUM 30

struct queue {
    struct node *data[MAX_NODE_NUM];
    int size;
    int top;
    int rear;
};

extern struct queue *create_queue(int size);
extern int enqueue(struct queue *queue, struct node *node);
extern struct node *dequeue(struct queue *queue);
extern int is_empty_queue(struct queue *queue);
extern int size_of_queue(struct queue *queue);
extern struct node *get_in_queue(struct queue *queue, int index);

#endif /* QUEUE_H */
