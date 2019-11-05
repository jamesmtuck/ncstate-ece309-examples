#ifndef GRAPH_H
#define GRAPH_H

#include <list>

using List = std::list<int>;

// Graph Abstract Base Class
//
// We have to specify the number of nodes at construction, and then we can set
// adjacency information as needed using addEdge. 
class Graph {
protected:
  int numNodes;

public:
  Graph(int n) : numNodes(n){};
  virtual void addEdge(int, int) = 0;

  virtual bool isAdjacent(int, int) = 0;
};

//
// Represent edges sparsely using a list
//
class SparseGraph : public Graph {
protected:
  class Node {
  public:
    List edge;
  };
  Node *nodes; // array of Nodes

public:
  SparseGraph(int n);
  void addEdge(int, int) override;

  bool isAdjacent(int, int) override;
};

//
// Represent edges densely using an array per node.
// This assumes that only one edge can exist between two nodes.
//
class DenseGraph : public Graph {
  bool *edges;

  int getIndex(int v1, int v2)
  {
    return v1*numNodes + v2;
  }
  
public:
  DenseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) override;
};

#endif // GRAPH_H
