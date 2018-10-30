#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(){
  int add_ret = add(2, 3);
  int sub_ret = sub(5, 2);

  printf("add_ret = %d\n", add_ret);
  printf("sub_ret = %d\n", sub_ret);

  return 0;
}
