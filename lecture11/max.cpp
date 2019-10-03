#include <stdio.h>

template <typename T, typename S> T max(T a, S b) {
  if (a > b)
    return (T) a;
  else
    return (T) b;
}

int main() {
  printf("Hello, World!\n");
  printf("%lf\n", max(300.5,55));        
  return 0;
}
