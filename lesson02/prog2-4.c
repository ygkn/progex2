/*********************************************
  prog2-4.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct data {
  char key;
  int value;
};

void print(struct data *data[], int num);
struct data *get(struct data *data[], int num, int index);
void plus(struct data *data[], int num, int value);

void print(struct data *data[], int num) {
  rep(i, num) { printf(" %c:%d", data[i]->key, data[i]->value); }
  printf("\n");
}

struct data *get(struct data *data[], int num, int index) {
  if (index < 0 || num < index) {
    return NULL;
  }

  return data[index];
}

void plus(struct data *data[], int num, int value) {
  rep(i, num) { data[i]->value += value; }
}

/*=============================================*/

void test1() {
  struct data init[4] = {{'a', 10}, {'b', 20}, {'c', 30}, {'d', 40}};
  struct data *data[4];
  data[0] = &init[0];
  data[1] = &init[1];
  data[2] = &init[2];
  data[3] = &init[3];
  int num = 4;

  assert(get(data, num, 0)->key == 'a');
  assert(get(data, num, 0)->value == 10);

  print(data, num);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct data init[4] = {{'a', 10}, {'b', 20}, {'c', 30}, {'d', 40}};
  struct data init2[4] = {{'a', 10}, {'b', 20}, {'c', 30}, {'d', 40}};

  struct data *data[4];
  data[0] = &init[0];
  data[1] = &init[1];
  data[2] = &init[2];
  data[3] = &init[3];
  int num = 4;

  plus(data, num, 10);

  rep(i, num) { assert(data[i]->value - 10 == (init2 + i)->value); }

  print(data, num);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();

  return 0;
}
