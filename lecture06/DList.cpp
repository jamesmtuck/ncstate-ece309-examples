#include <string>
#include <iostream>
#include <cstddef>

using std::string;

class Item {
public:
  string s;
  Item(const char *a_s = "")
  {
    s = a_s;
  }
  Item(string a_s)
  {
    s = a_s;
  }
};


class DList {
private:

  class DListNode {
  public:
    Item item;
    DListNode * next;
    DListNode * prev;
    DListNode(Item i, DListNode *n=nullptr, DListNode *p=nullptr) {
      item = i;      
      next = n;
      prev = p;
    }
  };
  
  DListNode * head;
  DListNode * tail;
  
public:
  class iterator {
    DListNode *node;
  public:
    iterator(DListNode *n = nullptr) {
      node = n;
    }

    Item& getItem() { return node->item; }
    void next() { node = node->next; }
    void prev() { node = node->prev; }
    bool end() { return node==nullptr; }
  };

  

public:
  DList() {
    // list is empty
    head = nullptr;
    tail = nullptr;
  }

  bool empty() {
    return head==nullptr;
  }
  
  void append(Item a) {
    DListNode *node = new DListNode(a,nullptr,tail);
    if ( head == nullptr ) {
      // empty list
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }

  void insertAfter(iterator it, Item item);
  
  bool erase (iterator i);

  iterator begin() {
    return iterator(head);
  }

  iterator reverse_begin() {
    return iterator(tail);
  }
};


int main()
{
  DList l;

  l.append("eggs");
  l.append("milk");
  l.append("bread");

  return 0;
}
