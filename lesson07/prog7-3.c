/*********************************************
  prog7-3.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};

struct tree {
  struct node *root;
};

struct tree *create_tree();
struct node *create_node(int value);

void print_tree(struct tree *tree);

struct tree *create_tree() {
  struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
  if (tree == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    tree->root = NULL;
  }
  return tree;
}

struct node *create_node(int value) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  if (node == NULL) {
    fprintf(stderr, "Not enough memory\n");
  } else {
    node->value = value;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

void print_node(struct node *node, int indent) {
  printf("\n");
  if (node->left != NULL) {
    int s;
    for (s = 0; s < indent; s++) {
      printf(" ");
    }
    printf("%d (left)", node->left->value);
    print_node(node->left, indent + 2);
  }

  if (node->right != NULL) {
    int s;
    for (s = 0; s < indent; s++) {
      printf(" ");
    }
    printf("%d (right)", node->right->value);
    print_node(node->right, indent + 2);
  }
}

void print_tree(struct tree *tree) {
  if (tree->root == NULL) {
    printf("No node\n");
    return;
  }

  printf("%d (root)", tree->root->value);
  print_node(tree->root, 2);
}

void test1() {
  struct tree *tree = create_tree();
  tree->root = create_node(1);
  tree->root->left = create_node(2);
  tree->root->left->left = create_node(4);
  tree->root->left->right = create_node(5);
  tree->root->right = create_node(3);
  tree->root->right->left = create_node(6);

  print_tree(tree);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct tree *tree = create_tree();
  tree->root = create_node(7);
  tree->root->left = create_node(2);
  tree->root->left->left = create_node(1);
  tree->root->left->right = create_node(5);
  tree->root->left->right->left = create_node(4);
  tree->root->right = create_node(15);
  tree->root->right->left = create_node(10);
  tree->root->right->right = create_node(17);

  print_tree(tree);
  printf("Success: %s\n", __func__);
}

/*=============================================*/

int main() {
  test1();
  test2();

  return 0;
}
