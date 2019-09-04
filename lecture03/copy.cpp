#include <stdio.h>
#include <cstddef>

class A {
private:
  int x;
public:
  A(int a=0) { x = a; }

  A(const A& copy) {
    printf("Making a copy of %d.\n",copy.x);
    x = copy.x;
  }

  void print() {
    printf("print %d.\n",x);
  }
};

A print(A a)
{
  return a;
}


int main(){
  
  A a1(1);
  A a2 = 5;

  printf("Before we make a3.\n");
  A a3 = a1;
  printf("After we make a3.\n");
  
  print(a1);

  printf("just before we return from main!\n");
  
  return 0;
}
