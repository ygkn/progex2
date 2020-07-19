/*
  measurement.h
*/

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "arraytable-common.h"
#include "chaintable-common.h"

extern void measure(char *title,
    int (*insert)(struct table *table, struct data data),
    struct data* (*search)(struct table *table, int key),
    int size);

extern void measure_chain(char *title,
    int (*insert)(struct chain_table *table, struct chain_data data),
    struct chain_data* (*search_chain)(struct chain_table *table, int key),
    int size);

#endif /* MEASUREMENT_H */
