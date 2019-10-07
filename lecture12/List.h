#ifndef LIST_H
#define LIST_H

#include <string>

using Item = int;

class List {
private:

  class ListNode {
  public:
    Item item;
    ListNode * next;
    ListNode(Item i, ListNode *n=nullptr) {
      item = i;
      next = n;
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

    friend class List;
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
  
  // Only declared, here, implemented
  // in List.cpp
  void append(Item a);
  bool remove (Item &copy);

  void insertAfter(iterator, Item);
  void removeAfter(iterator, Item&);

  iterator begin() {
    return iterator(head);
  }  
};

#endif
