/*********************************************
  prog2-1.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void print(int data[], int num);
int get(int data[], int num, int index);
int sum(int data[], int num);

void print(int data[], int num) {
  rep(i, num) { printf(" %d", data[i]); }
  printf("\n");
}

int get(int data[], int num, int index) {
  if (index < 0 || num < index) {
    return -1;
  }

  return data[index];
}

int sum(int data[], int num) {
  if (num == 0) {
    return -1;
  }

  int result = 0;

  rep(i, num) { result += data[i]; }

  return result;
}

/*=============================================*/

void test1() {
  int data[4] = {10, 20, 30, 40};
  int num = 4;

  assert(get(data, num, 0) == 10);
  assert(get(data, num, num + 1) == -1);

  print(data, 4);
  printf("Success: %s\n", __func__);
}

void test2() {
  int data[4] = {10, 20, 30, 40};
  int num = 4;

  assert(sum(data, num) == 100);
  assert(sum(data, 0) == -1);

  print(data, 4);
  printf("Success: %s\n", __func__);
}

int main() {
  test1();
  test2();

  return 0;
}
