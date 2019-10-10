#include <random>
#include <iostream>
#include <chrono>

#include "IntegerSet.h"
#include "TList.h"

class IntegerSetHTChain : public IntegerSet {
protected:

  TList<int> *table;
  int size;
  int hash(int key) { return (key * 997) % size; }

public:
  IntegerSetHTChain(int htsize=1000)
  {
    size = htsize;
    table = new TList<int> [size];
  }

  bool insert(int data) override
  {
    int index = hash(data);
    table[index].append(data);
    return true;
  }

  bool find(int data) override
  {
    int index = hash(data);
    TList<int>::iterator it =
      table[index].begin();

    while(!it.end()) {
      if (it.getItem()==data) {
	return true;
      }
      it.next();
    }
    return false;
  }
  
  

};
