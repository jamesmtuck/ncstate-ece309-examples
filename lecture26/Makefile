
EXE = lec24

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

lec24:  lec24.o
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
