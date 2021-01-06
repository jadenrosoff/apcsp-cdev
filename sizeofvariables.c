#include<stdio.h>

int main()
{
  int a = 545;
  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char c = 'b';
  printf("int c value: %c and size: %lu bytes\n", c, sizeof(c));

  float f = 1.5;
  printf("int f value: %f and size: %lu bytes\n", f, sizeof(f));

  double d = 123.456;
  printf("int d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int u = 7;
  printf("int u value: %d and size: %lu bytes\n", u, sizeof(u));

  short int s = 8;
  printf("int s value: %d and size: %lu bytes\n", s, sizeof(s));
}

