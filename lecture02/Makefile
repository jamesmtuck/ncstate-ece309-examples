
EXE = lec02 namespace

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -o $@ $< 
