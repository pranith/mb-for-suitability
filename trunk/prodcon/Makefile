ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

CXX = icc 
CPPFLAGS = -Wall -openmp $(DEBUG) 

EXEC = prodcon.exe

all: $(EXEC)

.PHONY: all 

$(EXEC): %.exe : %.o 
		  $(CXX) $< -o $@ $(CPPFLAGS) 

$(OBJ): %.o : %.cpp main.cpp
		  $(CXX) -o $@ -c $< $(CPPFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: clean
clean:
	rm -f *.o *.exe
