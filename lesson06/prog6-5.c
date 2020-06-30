/*********************************************
  prog6-5.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_SIZE 30

struct queue {
    int data[QUEUE_SIZE];
    int top;
    int rear;
    int num;
};

struct queue *create_queue();
void print_queue(struct queue *queue);
int size_of_queue(struct queue *queue);

int enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
int peek(struct queue *queue);
int is_empty(struct queue *queue);

struct queue *create_queue()
{
    return NULL;
}

void print_queue(struct queue *queue)
{
}

int size_of_queue(struct queue *queue)
{
    return 0;
}

int enqueue(struct queue *queue, int value)
{
    return 0;
}

int dequeue(struct queue *queue)
{
    return -1;
}

int peek(struct queue *queue)
{
    return -1;
}

int is_empty(struct queue *queue)
{
    return 0;
}

/*=============================================*/

void test1()
{
}

int main()
{
    test1();
    
    return 0;
}
