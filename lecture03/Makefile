
EXE = lec03 cstr

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -o $@ $< 
