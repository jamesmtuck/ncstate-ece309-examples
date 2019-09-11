#include <string>
#include <iostream>

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


class List {
private:

  class ListNode {
  public:
    Item item;
    ListNode * next;
    ListNode(Item i) {
      item = i;
      next = nullptr;
    }
  };
  
  ListNode * head;
  ListNode * tail;
  
public:
  class iterator {
    ListNode *node;
  public:
    iterator(ListNode *n = nullptr) {
      node = n;
    }

    Item& getItem() { return node->item; }
    void next() { node = node->next; }
    bool end() { return node==nullptr; }
  };

  

public:
  List() {
    // list is empty
    head = nullptr;
    tail = nullptr;
  }

  bool empty() {
    return head==nullptr;
  }
  
  void append(Item a) {
    ListNode *node = new ListNode(a);
    if ( head == nullptr ) {
      // empty list
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }

  bool remove (Item &copy);

  void traverse() {
    ListNode *tmp = head;
    while(tmp != nullptr)
      {

	tmp = tmp->next;
      }
  }

  iterator begin() {
    return iterator(head);
  }
  
};

bool List::remove(Item &copy)
{
  if (!empty()) {
    copy = head->item;
    ListNode *tmp = head->next;
    delete head;
    head = tmp;
    if (head==nullptr)
      tail = nullptr;
    return true;
  }
  return false;
}

int main() {
  List l;

  l.append("eggs");
  l.append("milk");
  l.append("bread");

  std::cout << "traversing the list: \n";
  
  List::iterator i = l.begin();
  while(!i.end()) {
    std::cout << "next item is";
    std::cout << i.getItem().s << "\n";
    
    i.next();
  }
  
  Item eggs;

  while(!l.empty())
    {
      l.remove(eggs);
      std::cout << "Just removed: " << eggs.s << "\n";
    }
  
  return 0;
}
