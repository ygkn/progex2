/*
  tree-common.h
*/

#ifndef TREE_COMMON_H
#define TREE_COMMON_H

#include <stdio.h>
#include "queue.h"

struct data {
    int key;
    char value;
};

struct node {
    struct data *data;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

extern struct tree *create_tree();
extern struct node *create_node(int key, char value);
extern void print(struct tree *tree);

extern void print_queue(struct queue *queue);

#endif /* TREE_COMMON_H */
