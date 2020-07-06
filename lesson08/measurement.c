/*
  measurement.c
*/

#include "measurement.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort-common.h"

#define MAX_NUM 50000
#define SMALL_NUM 100
#define MEDIUM_NUM 1000
#define LARGE_NUM MAX_NUM

struct timespec start_ts;

void start() { clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_ts); }

void stop(char *header) {
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

struct data *generate_data(int num) {
  struct data *data = (struct data *)calloc(num, sizeof(struct data));

  int i;
  for (i = 0; i < num; i++) {
    data[i].key = i;
    data[i].value = 'a';
  }

  srand(time(NULL));
  for (i = 0; i < num; i++) {
    int j = i + (rand() % (num - i));
    struct data tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
  return data;
}

void measure(char *title, void (*sort)(struct data data[], int)) {
  struct data *data;
  int num;

  printf("-------------------------------\n");
  printf("  %s\n", title);

  printf("-------------------------------\n");
  num = SMALL_NUM;
  data = generate_data(num);
  start();
  sort(data, num);
  stop("SMALL:  ");

  num = MEDIUM_NUM;
  data = generate_data(num);
  start();
  sort(data, num);
  stop("MEDIUM: ");

  num = LARGE_NUM;
  data = generate_data(num);
  start();
  sort(data, num);
  stop("LARGE:  ");
  printf("-------------------------------\n");
}
