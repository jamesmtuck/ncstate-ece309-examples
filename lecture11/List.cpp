#include <string>
#include <iostream>
#include <cstddef>

template <typename Item>
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

  bool remove (Item &copy) {
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

int main() {
  List<std::string> l;

  List<int> l_int;

  l.append("eggs");
  l.append("milk");
  l.append("bread");

  std::cout << "traversing the list: \n";
  
  List<std::string>::iterator i = l.begin();
  while(!i.end()) {
    std::cout << "next item is";
    std::cout << i.getItem() << "\n";
    
    i.next();
  }
  
  std::string eggs;

  while(!l.empty())
    {
      l.remove(eggs);
      std::cout << "Just removed: " << eggs << "\n";
    }
  
  return 0;
}
