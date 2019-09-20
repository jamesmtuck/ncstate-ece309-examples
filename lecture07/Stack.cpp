#include "Stack.h"
#include <iostream>

void Stack::push(Item i)
{
  List::iterator it;
  list.insertAfter(it, i);
}

void Stack::pop()
{
  List::iterator it;
  Item i;
  list.removeAfter(it,i);
}

Item& Stack::peek()
{
  List::iterator it = list.begin();
  return it.getItem();
    
}

bool Stack::empty()
{
  return list.empty();
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
