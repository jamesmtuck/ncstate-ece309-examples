#include <iostream>
#include <string>
//#include <list>
#include <set>
#include <string.h>

using namespace std;

class lt_str {
public:
  bool operator() ( const char* lhs,
		    const char* rhs )
  {
    return strcmp(lhs,rhs) < 0;
  }
};

class Edge {
public:
  Edge(int f, int t, int w)
    :from(f),to(t),weight(w){}
  int from;
  int to;
  int weight;

  // operator<
};

class EdgeCompare {
public:
  bool operator() (const Edge &lhs,
		   const Edge &rhs) {
    return lhs.weight < rhs.weight ||
	   (lhs.weight==rhs.weight && lhs.from < rhs.from) ||
      (lhs.weight==rhs.weight && lhs.from==rhs.from && lhs.to < rhs.to);
      ;
  }
};

int main()
{
  //  list<const char*> l;
  set<const char*,lt_str> s;
  s.insert("eggs");
  s.insert("milk");
  s.insert("flour");
  
  for(auto i = s.begin();
      i != s.end(); i++)
    {
      //void *p = (void*)(*i);
      std::cout << *i << std::endl;
    }

  if ( s.find("flour") != s.end() )
    {
      std::cout << "flour is in my set!" << std::endl;
    }


  
  set<Edge,EdgeCompare> edgeSet;
  edgeSet.insert( Edge(0,1,1) );
  edgeSet.insert( Edge(1,2,10) );
  edgeSet.insert( Edge(2,3,10) );

  for(auto i = edgeSet.begin();
      i != edgeSet.end(); i++)
    {
      //void *p = (void*)(*i);
      std::cout << (*i).from << "->" << (*i).to << "(" << (*i).weight << ")" << std::endl;
    }
  
  return 0;
}
