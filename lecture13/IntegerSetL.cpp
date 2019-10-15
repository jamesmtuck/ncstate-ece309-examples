#include <iostream>
#include <random>
#include <chrono>

#include "IntegerSet.h"
#include "TList.h"


class IntegerSetL : public IntegerSet {
protected:
  TList<int> set;
  
public:
  IntegerSetL() {}

  // O(1) - appending to a list O(1)
  bool insert(int item) override
  {
    set.append(item);
    return true;
  }

  // O(N) - might have to look at everything
  // in the list to disprove that its not there
  // 
  bool find(int item) override
  {
    auto it = set.begin();
    while(!it.end()) {
      if ( it.getItem() == item ) {
	return true;
      }
      it.next();
    }
    return false;
  }

  // O(N) - might have to look at everything
  // in the list to disprove that its not there
  // 
  void remove(int item) override
  {
    auto it = set.begin();
    TList<int>::iterator prev;
    bool found = false;
    while(!it.end())
      {
	if ( it.getItem() == item ) {
	  found = true;
	  break;
	}
	prev = it;
	it.next();      
      }
    if (found)
      {
	int rm;
	set.removeAfter(prev,rm);
      }
  }
};

using namespace std::chrono;

int main()
{
  // random number generation
  std::random_device generator;
  std::uniform_int_distribution<int> dist(0,1000000);

  // random numbers to insert into the set


  IntegerSetL myset;
  
  for(int i=0; i<10000; i++)
    {
      myset.insert(dist(generator));      
    }

  auto start = high_resolution_clock::now();

  for(int i=0; i<100000; i++)
    {
      auto r = dist(generator);
      if(myset.find(r)==true) {
	//std::cout << "found " << r << " in the set." << std::endl;
      }
    }

  auto stop = high_resolution_clock::now();
  
  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << duration.count() << std::endl;

  return 0;

}
