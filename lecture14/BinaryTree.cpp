#include <iostream>
#include <random>

// Class to represent a node of a binary tree, left here so that main will compile
class BTNode
{
public:
  int data;
  BTNode *right;
  BTNode *left;

  BTNode(int d, BTNode *l=nullptr, BTNode *r=nullptr)
  {
    data = d;
    right = r;
    left = l;
  }  
};

class BinarySearchTree {
protected:
  // Class to represent a node of a binary tree
  class BTNode
  {
  public:
    int data;
    BTNode *right;
    BTNode *left;
    
    BTNode(int d, BTNode *l=nullptr, BTNode *r=nullptr)
    {
      data = d;
      right = r;
      left = l;
    }  
  };

  BTNode *root;
  
public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  void insert(int data)
  {
    BTNode *node = new BTNode(data);

    if (root == nullptr)
      {
	root = node;
      }
    else
      {   
	BTNode * tmp = root;
	while (tmp != nullptr)
	  {	    
	    if (data < tmp->data)
	      {
		// data must be on left side
		if (tmp->left == nullptr)
		  {
		    tmp->left = node; // 
		    return;
		  }
		else
		  tmp = tmp->left;
	      }
	    else
	      {
		// data must be on right side
		if (tmp->right == nullptr)
		  {
		    tmp->right = node;
		    return;		    
		  }
		else
		  tmp = tmp->right;
	      }
	  }
      }

  }

  bool search(int data) {
    BTNode * tmp = root;
    while (tmp != nullptr)
      {
	if (data == tmp->data)
	  return true;
	
	if (data < tmp->data)
	  tmp = tmp->left;
	else
	  tmp = tmp->right;
      }
    return false;
  }
};
  
int main()
{
  BTNode * root_1 = new BTNode(100, new BTNode(25), new BTNode(150));

  // 100, 150, 200

  BTNode * root_2 = new BTNode(100, nullptr,
			       new BTNode(150, nullptr,
					  new BTNode(200)));
  
  
  

  BinarySearchTree b;

  b.insert(100);
  b.insert(25);
  b.insert(150);


  std::random_device generator;
  std::uniform_int_distribution<int> dist(0,1000000);

  BinarySearchTree b2;
  for(int i=0; i<10000; i++)
    {
      b2.insert(dist(generator));      
    }

    
  return 0;
}
