ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

CC = g++
CPPFLAGS = -Wall -fopenmp $(DEBUG) 

EXEC = read1.exe read2.exe

all: $(EXEC)

.PHONY: all 

$(EXEC): %.exe : %.o main.o 
		  $(CC) $< -o $@ $(CPPFLAGS) main.o

$(OBJ): %.o : %.cpp main.cpp
		  $(CC) -o $@ -c $< $(CPPFLAGS)

main.o: main.cpp 
		  $(CC) -c main.cpp $(CPPFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: clean
clean:
	rm -f *.o *.exe
