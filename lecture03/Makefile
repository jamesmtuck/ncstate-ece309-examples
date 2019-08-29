
EXE = lec03

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -o $@ $< 
