#include "Graph.h"
#include <iostream>

SparseGraph::SparseGraph(int n)
  :Graph(n)
{
  nodes = new Node[n];
}

void SparseGraph::addEdge(int v1, int v2)
{
  nodes[v1].edge.push_back(v2);
  nodes[v2].edge.push_back(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2)
{
  List &adjList = nodes[v1].edge;
  for(auto it = adjList.begin();
      it!= adjList.end(); it++)
    {
      if ( *it == v2 ) {
	return true;
      }
    }
  return false;
}

DenseGraph::DenseGraph(int n)
  :Graph(n)
{
  edges = new bool [numNodes * numNodes];
  for(int i=0; i<numNodes*numNodes; i++)
    edges[i] = false; // no edges present yet
}

void DenseGraph::addEdge(int v1, int v2)
{
  edges[ getIndex(v1,v2) ] = true;
  edges[ getIndex(v2,v1) ] = true;
}

bool DenseGraph::isAdjacent(int v1, int v2)  {
  return edges[ getIndex(v1,v2) ];
}

int main() {

  Graph *g = new DenseGraph(5);

  g->addEdge(0,3);
  g->addEdge(0,1);
  g->addEdge(1,2);
  g->addEdge(1,4);
  g->addEdge(3,2);
  g->addEdge(2,4);

  // Should have a representation in memory

  // does some calculate on this graph

  if (g->isAdjacent(1,3)) {
    std::cout << "1 and 3 are adjacent!";
  } else {
    std::cout << "1 and 3 are not adjacent!";
  }
  
  return 0;
}
