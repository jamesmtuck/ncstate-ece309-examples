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
    size = other.size;
    s = new char[size+1];
    strcpy(s, other.s);
  }
  
  ~cstr() {
    delete s;
  }
};

void print(cstr s) {
  std::cout << s.get();
}

int main() {

  cstr s = "hello, world!";
  cstr s2 = "doesn't really matter!";

  print(s);
  print(s2);
  
  return 0;
}
