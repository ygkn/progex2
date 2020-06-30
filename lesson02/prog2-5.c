/*********************************************
  prog2-5.c
    Student ID: 2600190375-5
    Name: 八木田裕伍
**********************************************/

#include <assert.h>
#include <stdio.h>

int gcd(int p, int q);

int gcd(int p, int q) {
  if (p < 0 || q < 0) {
    return -1;
  }

  if (p < q) {
    int tmp = p;
    p = q;
    q = tmp;
  }

  return q == 0 ? p : gcd(q, p % q);
}

/*=============================================*/

void test1() {
  assert(gcd(12, 8) == 4);

  printf("Success: %s\n", __func__);
}

int main() {
  test1();

  return 0;
}
