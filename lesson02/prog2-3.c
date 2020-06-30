/*********************************************
  prog2-3.c
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

void print(struct data data[], int num);
struct data *get(struct data data[], int num, int index);

void print(struct data data[], int num) {
  rep(i, num) { printf(" %c:%d", data[i].key, data[i].value); }

  printf("\n");
}

struct data *get(struct data data[], int num, int index) {
  if (index < 0 || num < index) {
    return NULL;
  }

  return data + index;
}

int sum(struct data data[], int num) {
  int result = 0;

  rep(i, num) { result += (data + i)->value; }

  return result;
}

/*=============================================*/

void test1() {
  struct data data[4] = {{'a', 10}, {'b', 20}, {'c', 30}, {'d', 40}};
  int num = 4;

  assert(get(data, num, 0)->key == 'a');
  assert(get(data, num, 0)->value == 10);

  print(data, num);
  printf("Success: %s\n", __func__);
}

void test2() {
  struct data data[4] = {{'a', 10}, {'b', 20}, {'c', 30}, {'d', 40}};
  int num = 4;

  assert(sum(data, num) == 100);
  assert(sum(data, 0) == 0);

  print(data, num);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();

  return 0;
}
