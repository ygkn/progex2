/*
  measurement.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arraytable-common.h"
#include "chaintable-common.h"
#include "measurement.h"

#define MAX_NUM    50000
#define SMALL_NUM  100
#define MEDIUM_NUM 1000
#define LARGE_NUM  MAX_NUM

#define SEARCH_TRIALS 10000

struct timespec start_ts;

void start()
{
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_ts);
}    

void stop(char *header)
{
    struct timespec end_ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_ts);

    time_t sec;
    long nsec;
    if (end_ts.tv_nsec < start_ts.tv_nsec) {
        sec = end_ts.tv_sec - start_ts.tv_sec - 1;
        nsec = end_ts.tv_nsec + 1000000000 - start_ts.tv_nsec;
    } else {
        sec = end_ts.tv_sec - start_ts.tv_sec;
        nsec = end_ts.tv_nsec - start_ts.tv_nsec;
    }
    printf("%s %10ld.%09ld\n", header, sec, nsec);
}    

void scramble(struct data *data, int num)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < num; i++) {
        int j = i + (rand() % (num - i));
        struct data tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}

struct data *generate_data(int num)
{
    struct data *data = (struct data *)calloc(num, sizeof(struct data));

    int i;
    for (i = 0; i < num; i++) {
        data[i].key = i;
        data[i].value = 'a';
    }

    scramble(data, num);
    return data;
}

struct table *insert_test(
    int (*insert)(struct table *table, struct data data),
    struct data *data, int num, int size)
{
    if (size < 0) {
        size = num;
    }

    struct table *table = create_table(size);
    int i;
    for (i = 0; i < num; i++) {
        insert(table, data[i]);
    }
    return table;
}

void search_test(
    struct data* (*search)(struct table *table, int key),
    struct table *table, int num)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < SEARCH_TRIALS; i++) {
        int key = rand() % num;
        struct data *data = search(table, key);
    }
}

void measure(char *title,
    int (*insert)(struct table *table, struct data data),
    struct data* (*search)(struct table *table, int key),
    int size)
{
    struct table *table;
    struct data *data;
    int num;

    printf("---------------------------------------\n");
    printf("  %s\n", title);

    printf("---------------------------------------\n");
    if (size < 0) {
        printf(" TRIALS = %d\n", SEARCH_TRIALS);
    } else {
        printf(" TRIALS = %d; TABLE SIZE = %d\n", SEARCH_TRIALS, size);
    }
    printf("---------------------------------------\n");

    num = SMALL_NUM;
    data = generate_data(num);

    start();
    table = insert_test(insert, data, num, size);
    stop("SMALL(INSERT):  ");

    start();
    search_test(search, table, num);
    stop("SMALL(SEARCH):  ");

    num = MEDIUM_NUM;
    data = generate_data(num);

    start();
    table = insert_test(insert, data, num, size);
    stop("MEDIUM(INSERT): ");

    start();
    search_test(search, table, num);
    stop("MEDIUM(SEARCH): ");

    num = LARGE_NUM;
    data = generate_data(num);
    start();
    table = insert_test(insert, data, num, size);
    stop("LARGE(INSERT):  ");

    start();
    search_test(search, table, num);
    stop("LARGE(SEARCH):  ");
    printf("---------------------------------------\n");
}

void scramble_chain(struct chain_data *data, int num)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < num; i++) {
        int j = i + (rand() % (num - i));
        struct chain_data tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}

struct chain_data *generate_chain_data(int num)
{
    struct chain_data *data = (struct chain_data *)calloc(num, sizeof(struct chain_data));

    int i;
    for (i = 0; i < num; i++) {
        data[i].key = i;
        data[i].value = 'a';
    }

    scramble_chain(data, num);
    return data;
}

struct chain_table *insert_chain_test(
    int (*insert)(struct chain_table *table, struct chain_data data),
    struct chain_data *data, int num, int size)
{
    if (size < 0) {
        size = num;
    }

    struct chain_table *table = create_chain_table(size);
    int i;
    for (i = 0; i < num; i++) {
        insert(table, data[i]);
    }
    return table;
}

void search_chain_test(
    struct chain_data* (*search)(struct chain_table *table, int key),
    struct chain_table *table, int num)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < SEARCH_TRIALS; i++) {
        int key = rand() % num;
        struct chain_data *data = search(table, key);
    }
}

void measure_chain(char *title,
    int (*insert)(struct chain_table *table, struct chain_data data),
    struct chain_data* (*search)(struct chain_table *table, int key),
    int size)
{
    struct chain_table *table;
    struct chain_data *data;
    int num;

    printf("---------------------------------------\n");
    printf("  %s\n", title);

    printf("---------------------------------------\n");
    if (size < 0) {
        printf(" TRIALS = %d\n", SEARCH_TRIALS);
    } else {
        printf(" TRIALS = %d; TABLE SIZE = %d\n", SEARCH_TRIALS, size);
    }
    printf("---------------------------------------\n");

    num = SMALL_NUM;
    data = generate_chain_data(num);

    start();
    table = insert_chain_test(insert, data, num, size);
    stop("SMALL(INSERT):  ");

    start();
    search_chain_test(search, table, num);
    stop("SMALL(SEARCH):  ");

    num = MEDIUM_NUM;
    data = generate_chain_data(num);

    start();
    table = insert_chain_test(insert, data, num, size);
    stop("MEDIUM(INSERT): ");

    start();
    search_chain_test(search, table, num);
    stop("MEDIUM(SEARCH): ");

    num = LARGE_NUM;
    data = generate_chain_data(num);
    start();
    table = insert_chain_test(insert, data, num, size);
    stop("LARGE(INSERT):  ");

    start();
    search_chain_test(search, table, num);
    stop("LARGE(SEARCH):  ");
    printf("---------------------------------------\n");

}
