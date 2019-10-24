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

  void percolateDown(int index)
  {
    // while my index is within the bounds of the max-heap
    while(index < nextIndex)
      {
	// assume value at index is maximum, and prove otherwise
	int maxVal = heapArray[index];
	int maxIndex = index;

	// get first child; remember that left comes first, then beside
	// it is the right node (+1).
	int child = getLeftChild(index);

	// a for loop is convenient here because we need to do the same
	// thing twice, once for left and once for right.
	// also, we may exceed bounds of max-heap between the left and right
	// children. The extra check against nextIndex saves us from an
	// illegal access past the end of the max-heap.
	for(int i=child; i<child+2 && i<nextIndex; i++)
	  {
	    // i is the child location; compare heapArray[i] to maxVal
	    if ( heapArray[i] > maxVal )
	      {
		// if child's value is bigger, remember the value and the index
		maxVal = heapArray[i];
		maxIndex = i;
	      }	   
	  }

	// if the maxIndex is not changed to a child, then just quit the loop.
	// There's no more percolateDown to do.
	if (index == maxIndex)
	  {
	    // children are not bigger
	    // we are done percolatingDown
	    break;
	  }

	// Else, do the swap with the child. And, update index to child's
	// index to continue percolatingDown.
	std::swap(heapArray[index],heapArray[maxIndex]);
	index = maxIndex;
      }
  }
  
public:
  Maxheap(int size)
  {
    heapArray= new int[size];
    nextIndex = 0;
    heapArraySize = size;
  }

  Maxheap(int *array, int array_size, int numElements)
  {
    heapArray = array;
    heapArraySize = array_size;
    nextIndex = numElements;

    // turn this array into a legal max-heap
    int m = getParent(nextIndex-1);
    while(m >= 0)
      {
	percolateDown(m);
	m--;
      }
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

  bool remove(int &max)
  {
    // if the max-heap as something in it:
    if (nextIndex>0) {
      // get the max from index=0 and return it by reference in max variable.
      max = heapArray[0];
      // move last index to the root
      heapArray[0] = heapArray[--nextIndex];
      // the "root" is now out of position, likely, so percolate down.
      percolateDown(0);
      // true means we found a max
      return true;
    }
    // false means the max-heap is empty.
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

  // Using a static function because we don't
  // want a user to build their own heapsort,
  // and we don't a user to see a weird
  // intermediate state inside the Maxheap.
  // Also, we want to be able to update the
  // array in place. A static function
  // allows us to control the whole process
  // with a clear interface.
  static void sort(int *array, int num)
  {
    Maxheap heap(array, num, num);

    int max;
    while(heap.remove(max))
      {
	// put the max value at the end of
	// the array. 
	array[--num] = max;
      }
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

  int max;
  while(h.remove(max))
    h.print();

  int arr[] = {5, 2, 22, 100, 23, 1};

  // sort arr using heap sort
  Maxheap::sort(arr, 6);

  // print it out to see that it's sorted
  for(int i=0; i<6; i++)
    std::cout << arr[i] << " ";
  
  return 0;
}
