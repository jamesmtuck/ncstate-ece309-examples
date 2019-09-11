#include <string>
#include <cstddef>

using std::string;

class Item {
public:
  string s;
  Item(string a_s = "")
  {
    s = a_s;
  }
};

class ListNode {
public:
  Item item;
  ListNode * next;
  ListNode(Item i) {
    item = i;
    next = nullptr;
  }
};

class List {
private:
  ListNode * head;
  ListNode * tail;

public:
  List() {
    // list is empty
    head = nullptr;
    tail = nullptr;
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
};

int main() {
  List l;

  l.append(Item("eggs"));
  l.append(Item("milk"));
  l.append(Item("bread"));

  return 0;
}
