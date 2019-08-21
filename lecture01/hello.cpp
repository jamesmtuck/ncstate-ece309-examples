#include <stdio.h>

class Rectangle {
private:
  int width;
  int length;
public:
  Rectangle(int w, int l) {
    width = w;
    length = l;
  }
  int area() { return width * length; }
};

int main()
{
  int x;
  Rectangle r1(5,10);
  Rectangle r2(2,3);

  //printf("Where are all the aliens?\n");

  printf("r1 is %d square units\n", r1.area());
  printf("r2 is %d square units\n", r2.area());
  
  return 0;
}
