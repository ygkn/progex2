/*
  chaintable-check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "chaintable-common.h"

struct chain_table *create_chain_table(int size)
{
    struct chain_table *table = (struct chain_table *)malloc(sizeof(struct chain_table));
    if (table == NULL) {
        fprintf(stderr, "Not enough memory\n");
        return NULL;
    }

    table->data = (struct chain_data **)calloc(size, sizeof(struct chain_data));
    if (table->data == NULL) {
        fprintf(stderr, "Not enough memory\n");
        return NULL;
    }

    int i;
    for (i = 0; i < size; i++) {
        table->data[i] = NULL;
    }
    table->size = size;
    table->num = 0;
    return table;
}

void print_chain(struct chain_table *table)
{
    if (table->num == 0) {
        printf("No element\n");
        return;
    }

    int i;
    for (i = 0; i < table->size; i++) {
        struct chain_data *cur = table->data[i];
        if (cur != NULL) {
            printf(" %d:%c", cur->key, cur->value);
            while (cur->next != NULL) {
                printf("->%d:%c", cur->next->key, cur->next->value);
                cur = cur->next;
            }
        } else {
            printf(" []");
        }
    }
    printf("\n");
}
