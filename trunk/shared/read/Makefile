ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = ../../include
CXX = icc 
CPPFLAGS = -Wall -openmp $(DEBUG) -I$(IDIR)

EXEC = read1.exe 

all: $(EXEC)

.PHONY: all 

$(EXEC): %.exe : %.o main.o 
		  $(CXX) $< -o $@ $(CPPFLAGS) main.o

$(OBJ): %.o : %.cpp main.cpp
		  $(CXX) -o $@ -c $< $(CPPFLAGS)

main.o: main.cpp 
		  $(CXX) -c main.cpp $(CPPFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: clean
clean:
	rm -f *.o *.exe
