#include <stdio.h>

void f()
{
  static int a = 3;
  static int b;
  int c;
  ++a;++b;++c;
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);
}

int main(void)
{
  f();
  f();
  f();
}
