#include <iostream>
#include <string.h>

class cstr {
  char *s;
  int size;

public:
  cstr(const char *str = "") {
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
  }

  const char *get() {
    return s;
  }

  cstr(const cstr &other)
  {
    std::cout << "made a copy!\n";
    s = new char[ other.size+1 ];
    strcpy(s, other.s);
    size = other.size;
  }
  
  ~cstr() {   
    delete s;
  }
};

void print(cstr s) {
  std::cout << s.get() << "\n";
}

int main() {

  cstr s = "hello, world!";
  cstr s2 = "doesn't really matter!";

  print(s);
  
  return 0;
}
