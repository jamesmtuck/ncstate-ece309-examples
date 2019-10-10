#include <random>
#include <iostream>
#include <chrono>

#include "IntegerSet.h"

class IntegerSetHT : public IntegerSet {
protected:
  
  const int empty_since_start = -1;
  const int empty_after_removal = -2;
  int probeDistance;
  int *table;  // pointer to the table

  int size;
  int hash(int key) { return (key * 997) % size; }


public:
  IntegerSetHT(int htsize=1000, int probeDist = 5)
  {
    probeDistance = probeDist;
    table = new int [ htsize ];
    for(int i=0; i<htsize; i++)
      {
	table[i] = empty_since_start; // -1 will mean the entry is unused
      }
    size = htsize;
  }
  
  bool insert(int data) override {
    int index = hash(data);
    
    int bucketsProbed = 0;
    while (bucketsProbed++ < probeDistance) {
      if ( table[index] < 0 ) {
	// the entry is unused so put our data there!
	table[ index  ] = data;
	return true;	    
      }

      std::cout << "collision detected!" << std::endl;
      
      index = (index + 1) % size;
    }

    std::cout << "collision unresolved!" << std::endl;
    return false;
  }

  //override keyword asks compiler to do extra checks
  bool find(int data) override
  {
    int index = hash(data);

    int bucketsProbed = 0;
    while (table[index] != empty_since_start
	   && bucketsProbed++ < probeDistance) {

      if ( table[index] == data )
	return true;
            
      index = (index + 1) % size;
    }
    
    return false;
  }

   void remove(int data) override
  {
    int index = hash(data);

    int bucketsProbed = 0;
    while (table[index] != empty_since_start
	   && bucketsProbed++ < probeDistance) {

      if ( table[index] == data ) {
	table [index] = empty_after_removal;
	return;
      }
	
      index = (index + 1) % size;
    }
  }
};

using namespace std::chrono;

int main()
{
  // random number generation
  std::random_device generator;
  std::uniform_int_distribution<int> dist(0,1000000);


  IntegerSetHT myset(1000000);
  
  for(int i=0; i<100000; i++)
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
