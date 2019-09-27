#include <iostream>

class IntArray
{
private:
  int *array;
  int size;

public:
  IntArray(int size=10, int init=0)
  {
    array = new int [size];
    this->size = size;
    for(int i=0; i<size; i++)
      array[i] = init;
  }

  int& get(int index)
  {
    if (index >= size)
      {
	int *tmp = new int [index+1];
	for(int j=0; j<size; j++)
	  tmp[j] = array[j];
	
	for(int j=size; j<index+1; j++)
	  tmp[j] = 0;
	
	size = index+1;
	delete array;
	array = tmp;
      }
    
    return array[index];
  }

  IntArray(const IntArray &other)
  {
    size = other.size;	
    array = new int [size];
    for(int i=0; i<size; i++)
      array[i] = other.array[i];
  }

  ~IntArray()
  {
    delete [] array;
  }


  IntArray operator + (const IntArray &rhs) const
  {
    IntArray result(size);

    for(int j=0; j<size; j++)
      result.array[j] = array[j] + rhs.array[j];

    return result;
  }
  
  IntArray& operator = (const IntArray& rhs)
  {
    if (this == &rhs) return *this; // avoid self assignment

    delete [] array;
    
    size = rhs.size;	
    array = new int [size];
    for(int i=0; i<size; i++)
      array[i] = rhs.array[i];
    
    return *this;
  }

};

int main()
{
  IntArray a(100,0);
  IntArray b(100,1);
  
  std::cout << "a[0] = " << a.get(0) << std::endl;
  std::cout << "b[99] = " << b.get(99) << std::endl;

  b.get(1000) = 50;

  std::cout << "b[1000] = " << b.get(1000) << std::endl;

  a = b;
  b.get(1000) = 100;

  
  std::cout << "a[1000] = " << a.get(1000) << std::endl;
  std::cout << "b[1000] = " << b.get(1000) << std::endl;

  a = a + b;

  std::cout << "a[1000] = " << a.get(1000) << std::endl;

  return 0;
}
