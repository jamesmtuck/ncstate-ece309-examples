#include <iostream>


class Shape {
public:
  // pure virtual function
  virtual int area() = 0;
};

class Rectangle : public Shape {
private:
  int w;
  int l;
public:
  Rectangle(int aw, int al)
  {
    w = aw;
    l = al;
  }
  int area() {
    return w * l;
  }
};

int main()
{
  Shape *s = nullptr;
  Rectangle r(1,1);

  s = &r;
  
  std::cout << "Area of my rectangle is " << s->area() << std::endl;
  
  return 0;
}
