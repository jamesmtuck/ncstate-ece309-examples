
EXE = Maxheap

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -O2 -o $@ $< -std=c++11 
