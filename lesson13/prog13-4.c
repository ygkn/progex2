/*********************************************
  prog13-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree-common.h"

void traverse_dfs_inorder(struct node *node, struct queue *queue);

int is_binary_search_tree(struct tree *tree);

struct data *search(struct tree *tree, int key);
int insert(struct tree *tree, struct data data);
int delete(struct tree *tree, int key);

void traverse_dfs_inorder(struct node *node, struct queue *queue)
{
}

int is_binary_search_tree(struct tree *tree)
{
    return 0;
}

struct data *search(struct tree *tree, int key)
{
    return NULL;
}

int insert(struct tree *tree, struct data data)
{
    return 0;
}

int delete(struct tree *tree, int key)
{
    return 0;
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 17, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    struct tree *tree = create_tree();
    int i;
    for (i = 0; i < num; i++) {
        insert(tree, data[i]);
    }

    assert(is_binary_search_tree(tree));
    assert(search(tree, 12)->value = 'h');

    print(tree);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
