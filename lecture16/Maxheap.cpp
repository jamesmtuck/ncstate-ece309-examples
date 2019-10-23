#include <iostream>

class Maxheap {
protected:
  int *heapArray;
  int heapArraySize;
  int nextIndex;

  int getParent(int index)
  {
    return (index-1)/2;
  }

  int getLeftChild(int index)
  {
    return index*2+1;
  }

  int getRightChild(int index)
  {
    return index*2+2;
  }

  void percolateUp(int index)
  {
    while(index > 0)
      {
	int parent = getParent(index);
	if ( heapArray[index] > heapArray[parent] )
	  {
	    std::swap(heapArray[index],heapArray[parent]);
	    index = parent;
	  }
	else
	  return;
      }

  }

public:
  Maxheap(int size)
  {
    heapArray= new int[size];
    nextIndex = 0;
    heapArraySize = size;
  }

  bool insert(int data)
  {
    if ( nextIndex < heapArraySize )
      {
	// there's still room in my array

	heapArray[nextIndex] = data;
	percolateUp(nextIndex);
	nextIndex++;
      }
    return false;
  }

  
  void print()
  {
    for(int i=0; i<nextIndex; i++)
      {
	std::cout << heapArray[i] << " ";
      }
    std::cout << std::endl;
  }
  
};


int main()
{
  Maxheap h(10);

  h.insert(5);
  h.insert(10);
  h.insert(100);
  h.insert(1);
  h.insert(7);
  h.insert(11);

  h.print();
  
  return 0;
}
