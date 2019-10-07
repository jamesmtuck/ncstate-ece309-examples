#include <random>
#include <iostream>
#include <chrono>

#include "IntegerSet.h"


// Is only for positive integers 
class IntegerSetHT : public IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
   int *table;  // pointer to the table

public:
  IntegerSetHT(int htsize=1000)
  {
    table = new int [ htsize ];
    for(int i=0; i<htsize; i++)
      {
	table[i] = -1; // -1 will mean the entry is unused
      }
    size = htsize;
  }
  
   // override ABC
  bool insert(int data) override {
    int index = hash(data);
    
    if ( table[index] != -1 )
      std::cout << "Have a collision!!!" << std::endl;
      
    table[ index  ] = data;
    return true;
  }

  //override keyword asks compiler to do extra checks
  bool find(int data) override
  {
    int index = hash(data);
    if ( table[index] == data )
      return true;
    else
      return false;
  }

   void remove(int data) override
  {
    if ( find(data) == true )
      {
	int index = hash(data);
	table[index] = -1;
      }
  }
};

using namespace std::chrono;

int main()
{
  // random number generation
  std::random_device generator;
  std::uniform_int_distribution<int> dist(0,1000000);

  auto start = high_resolution_clock::now();


  IntegerSetHT myset(10000);
  
  for(int i=0; i<100; i++)
    {
      myset.insert(dist(generator));      
    }

  for(int i=0; i<100; i++)
    {
      auto r = dist(generator);
      if(myset.find(r)==true) {
	std::cout << "found " << r << " in the set." << std::endl;
      }
    }

  auto stop = high_resolution_clock::now();
  
  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << duration.count() << std::endl;
  
 return 0;
}
