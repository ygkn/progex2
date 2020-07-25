/*                                                                                                   list-check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "list-common.h"

struct list *create_list()
{
    struct list *list = (struct list *)malloc(sizeof(struct list));
    if (list == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        list->top = NULL;
    }
    return list;
}

void print(struct list *list)
{
    if (list->top == NULL) {
        printf("No element\n");
        return;
    }

    struct element *cur = list->top;
    while (cur != NULL) {
        printf(" %d:%c", cur->data->key, cur->data->value);
        cur = cur->next;
    }
    printf("\n");
}
