/*********************************************
  prog13-2.c
    Student ID:
    Name:
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree-common.h"

void traverse_dfs_preorder(struct node *node, struct queue *queue);
void traverse_dfs_inorder(struct node *node, struct queue *queue);
void traverse_dfs_postorder(struct node *node, struct queue *queue);

void traverse_dfs_preorder(struct node *node, struct queue *queue) {
  if (node == NULL) {
    return;
  }
  enqueue(queue, node);
  traverse_dfs_preorder(node->left, queue);
  traverse_dfs_preorder(node->right, queue);
}

void traverse_dfs_inorder(struct node *node, struct queue *queue) {
  if (node == NULL) {
    return;
  }
  traverse_dfs_inorder(node->left, queue);
  enqueue(queue, node);
  traverse_dfs_inorder(node->right, queue);
}

void traverse_dfs_postorder(struct node *node, struct queue *queue) {
  if (node == NULL) {
    return;
  }
  traverse_dfs_postorder(node->left, queue);
  traverse_dfs_postorder(node->right, queue);
  enqueue(queue, node);
}

/*=============================================*/

struct tree *create_testtree() {
  struct tree *tree = create_tree();

  struct node *n1 = create_node(15, 'j');
  tree->root = n1;

  struct node *n2 = create_node(12, 'h');
  struct node *n3 = create_node(21, 'a');
  n1->left = n2;
  n1->right = n3;

  struct node *n4 = create_node(10, 'i');
  struct node *n5 = create_node(14, 'd');
  n2->left = n4;
  n2->right = n5;

  struct node *n6 = create_node(1, 'f');
  n4->left = n6;

  struct node *n7 = create_node(20, 'e');
  struct node *n8 = create_node(31, 'c');
  n3->left = n7;
  n3->right = n8;

  struct node *n9 = create_node(24, 'g');
  struct node *n10 = create_node(33, 'b');
  n8->left = n9;
  n8->right = n10;

  return tree;
}

void test1() {
  struct tree *tree = create_testtree();

  struct queue *queue = create_queue(MAX_NODE_NUM);
  traverse_dfs_preorder(tree->root, queue);

  assert(get_in_queue(queue, 0)->data->key == 15);
  assert(get_in_queue(queue, 1)->data->key == 12);
  assert(get_in_queue(queue, 2)->data->key == 10);
  assert(get_in_queue(queue, 3)->data->key == 1);
  assert(get_in_queue(queue, 4)->data->key == 14);
  assert(get_in_queue(queue, 5)->data->key == 21);
  assert(get_in_queue(queue, 6)->data->key == 20);
  assert(get_in_queue(queue, 7)->data->key == 31);
  assert(get_in_queue(queue, 8)->data->key == 24);
  assert(get_in_queue(queue, 9)->data->key == 33);

  print_queue(queue);
  print(tree);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct tree *tree = create_testtree();

  struct queue *queue = create_queue(MAX_NODE_NUM);
  traverse_dfs_inorder(tree->root, queue);

  assert(get_in_queue(queue, 0)->data->key == 1);
  assert(get_in_queue(queue, 1)->data->key == 10);
  assert(get_in_queue(queue, 2)->data->key == 12);
  assert(get_in_queue(queue, 3)->data->key == 14);
  assert(get_in_queue(queue, 4)->data->key == 15);
  assert(get_in_queue(queue, 5)->data->key == 20);
  assert(get_in_queue(queue, 6)->data->key == 21);
  assert(get_in_queue(queue, 7)->data->key == 24);
  assert(get_in_queue(queue, 8)->data->key == 31);
  assert(get_in_queue(queue, 9)->data->key == 33);

  print_queue(queue);
  print(tree);
  printf("Success: %s\n", __func__);
}

void test3() {
  struct tree *tree = create_testtree();

  struct queue *queue = create_queue(MAX_NODE_NUM);
  traverse_dfs_postorder(tree->root, queue);

  assert(get_in_queue(queue, 0)->data->key == 1);
  assert(get_in_queue(queue, 1)->data->key == 10);
  assert(get_in_queue(queue, 2)->data->key == 14);
  assert(get_in_queue(queue, 3)->data->key == 12);
  assert(get_in_queue(queue, 4)->data->key == 20);
  assert(get_in_queue(queue, 5)->data->key == 24);
  assert(get_in_queue(queue, 6)->data->key == 33);
  assert(get_in_queue(queue, 7)->data->key == 31);
  assert(get_in_queue(queue, 8)->data->key == 21);
  assert(get_in_queue(queue, 9)->data->key == 15);

  print_queue(queue);
  print(tree);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}
