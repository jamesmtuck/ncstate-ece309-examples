
EXE = graph

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

graph:  graph.cpp
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
