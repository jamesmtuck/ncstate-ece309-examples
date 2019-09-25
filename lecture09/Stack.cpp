#include "Stack.h"
#include <iostream>

void Stack::push(Item i)
{
  iterator it;
  insertAfter(it, i);
}

void Stack::pop()
{
  iterator it;
  Item i;
  removeAfter(it,i);
}

Item& Stack::peek()
{
  iterator it = begin();
  return it.getItem();
}

bool Stack::empty()
{
  return List::empty();
}

int main() {

  Stack s;

  s.push("apples");
  s.push("bread");
  s.push("snack");

  Item &i = s.peek();
  std::cout << i << std::endl;
  
  return 0;
}
