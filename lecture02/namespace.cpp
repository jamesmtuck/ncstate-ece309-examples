#include <stdio.h>

int a;
namespace A {
  int a;
}

int main(){
  int a;

  printf("&a=%p &::a=%p &A::a=%p\n",
	 &a, &::a, &A::a);
  
  return 0;
}
