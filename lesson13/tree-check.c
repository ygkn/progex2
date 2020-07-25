/*
  tree-check.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "tree-common.h"

struct tree *create_tree() {
  struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
  if (tree == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    tree->root = NULL;
  }
  return tree;
}

struct node *create_node(int key, char value) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  if (node == NULL) {
    fprintf(stderr, "Not enough memory\n");
    return NULL;
  }

  node->data = (struct data *)malloc(sizeof(struct data));
  if (node->data == NULL) {
    fprintf(stderr, "Not enough memory\n");
    return NULL;
  }

  node->data->key = key;
  node->data->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void print_node(struct node *node, int indent) {
  printf("\n");
  if (node->left != NULL) {
    int s;
    for (s = 0; s < indent; s++) {
      printf(" ");
    }
    printf("%d:%c(L)", node->left->data->key, node->left->data->value);
    print_node(node->left, indent + 2);
  }

  if (node->right != NULL) {
    int s;
    for (s = 0; s < indent; s++) {
      printf(" ");
    }
    printf("%d:%c(R)", node->right->data->key, node->right->data->value);
    print_node(node->right, indent + 2);
  }
}

void print(struct tree *tree) {
  if (tree->root == NULL) {
    printf("No node\n");
    return;
  }

  printf("%d:%c", tree->root->data->key, tree->root->data->value);
  print_node(tree->root, 2);
}

void print_queue(struct queue *queue) {
  int num = size_of_queue(queue);
  int i;
  for (i = 0; i < num; i++) {
    struct node *node = get_in_queue(queue, i);
    printf(" %d", node->data->key);
  }
  printf("\n");
}
