#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <random>
#include <string>
#include <climits>
#include <queue>

using std::list;

// Graph : represents a single vertex
class Graph {
public:
  std::string name;
  
  class Edge {
  public:
    Edge(Graph *n, int w) {
      node = n;
      weight = w;
    }
    Graph *node;
    int   weight;
  };

  int distance; //shortest path distance
  Graph *pred;  // tells us where we came from in the shortest path
  
  list<Edge> adjList;
  using iterator = list<Edge>;

  Graph(std::string n):name(n)
  {
    distance = INT_MAX;
    pred = nullptr;
  }

  void addEdge(Graph *to, int weight)
  {
    adjList.push_back( Edge(to,weight)  );
    to->adjList.push_back( Edge(this, weight) );
  }  
};

std::ostream& operator << (std::ostream& out, const std::list<Graph*> &dfs)
{
  for(auto i = dfs.cbegin(); i!=dfs.cend(); i++)
    {
      if (i!=dfs.cbegin())
	out << ", ";
      out << (*i)->name;
    }
  out << std::endl;
  return out;
}

std::vector<Graph*> random_graph(int nodes)
{
  std::vector<Graph*> graph;
  for(auto i = 0;  i<nodes; i++)
    {
      graph.push_back( new Graph( std::to_string(i) ) );
    }

  std::cout << graph.size() << std::endl;
  
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0,nodes);
  std::uniform_int_distribution<int> weight(0,1000);

  for(auto i = 0; i<nodes; i++)
    {
      auto r = dist(generator);
      auto w = weight(generator);
      graph[i]->addEdge( graph[r], w );
      if (i>0)
	graph[i]->addEdge( graph[i-1], w );
    }

  return graph;
}

class Greater {
public:
  bool operator() (Graph* lhs, Graph* rhs) const
  {
    return lhs->distance > rhs->distance;
  }
};


void ShortestPath(Graph *start, std::vector<Graph*> &graph)
{
  std::vector<Graph*> visited = graph;
  for(size_t i=0; i<visited.size(); i++)
    {
      visited[i]->distance = INT_MAX;
      visited[i]->pred = nullptr;
    }

  start->distance = 0;

  while( visited.size() > 0 )
    {
      // implement a little search for the node with the smallest distance
      int min = INT_MAX;
      std::vector<Graph*>::iterator smallest;
      for(auto i = visited.begin(); i != visited.end(); i++)
	{
	  if ( (*i)->distance < min )
	    {
	      smallest = i;
	      min = (*i)->distance;
	    }	
	}

      Graph* g = *smallest;
      visited.erase(smallest);

      for(auto j = g->adjList.begin(); j != g->adjList.end(); j++)
	{
	  int distance = g->distance + (*j).weight;
	  if ( distance < (*j).node->distance ) {
	    (*j).node->distance = distance;
	    (*j).node->pred = g;
	  }
	}
    }
}


int main()
{
  {
    Graph *RDU = new Graph("RDU");
    Graph *ATL = new Graph("ATL");
    Graph *JFK = new Graph("JFK");
    Graph *CLT = new Graph("CLT");
    Graph *BNA = new Graph("BNA");
    Graph *HON = new Graph("HON");

    RDU->addEdge(ATL,370);
    RDU->addEdge(CLT,200);
    RDU->addEdge(JFK,180);
    RDU->addEdge(BNA,400);

    JFK->addEdge(HON, 500);
    CLT->addEdge(HON, 300);
    CLT->addEdge(ATL, 190);
    CLT->addEdge(JFK, 500);
    ATL->addEdge(BNA, 200);

    std::vector<Graph*> graph = {RDU,ATL,CLT,JFK,BNA,HON};
    ShortestPath(RDU,graph);

    Graph *path = HON;
    while (path != nullptr) {
      std::cout << "To: " << path->name << " for " << path->distance << std::endl;
      path = path->pred;
    }
    std::cout << "From RDU" << std::endl;
    
  }
  
  {
    Graph *a = new Graph("a");
    Graph *b = new Graph("b");
    Graph *c = new Graph("c");
    Graph *d = new Graph("d");
    Graph *e = new Graph("e");
    
    a->addEdge(b,0);
    b->addEdge(e,1);
    a->addEdge(c,10);
    a->addEdge(d,15);
    d->addEdge(e,10);

  
    //a->distance = 0;
    
    std::vector<Graph*> graph( {a,b,c,d,e} );

    //ShortestPath(a,graph);

    //std::cout << e->pred->name << " " << e->distance << std::endl;
    
   }
  {
    //std::vector<Graph*> r = random_graph(100);
  
  }
    
  return 0;
}
