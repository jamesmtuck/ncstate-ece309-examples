#ifndef TLIST_H
#define TLIST_H

#include <cstddef>

template <typename Item>
class TList {
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

    friend class TList<Item>;
  };

  
public:
  TList() {
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

  iterator begin() {
    return iterator(head);
  }

  void insertAfter(iterator it, Item item)
  {
    if (it.node == nullptr)
      {
	// insert at head
	ListNode *tmp = new ListNode(item,head);
	// if list is empty, set tail to new node
	if (tail==nullptr) {
	  tail = tmp;
	}
	// set head to new node
	head = tmp;
      }
    else
      {
	ListNode *tmp = new ListNode(item,it.node->next);	
	it.node->next = tmp;
	// could be a new tail, if so update tail
	if (tail==it.node) {
	  tail = tmp;
	}     
      }
  }

  void removeAfter(iterator it, Item& item)
  {
    // emtpy list or at tail, just return
    if (it.node == tail) return;
    
    if (it.node == nullptr)
      {
	ListNode * tmp = head;
	head = head->next;
	delete tmp;
	if (head==nullptr)
	  tail = nullptr;
      }
    else
      {
	ListNode *tmp = it.node->next;
	it.node->next = tmp->next;
	delete tmp;
	// could be that it.node is the new nullptr
	if (it.node->next == nullptr)
	  tail = it.node;
      }
  }
  
};

#endif //TLIST_H

