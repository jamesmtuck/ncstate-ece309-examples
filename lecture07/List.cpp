#include <iostream>
#include <cstddef>

#include "List.h"
#include "List.h"

void List::append(Item a) {
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

void List::insertAfter(iterator it, Item item)
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

void List::removeAfter(iterator it, Item& item)
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
