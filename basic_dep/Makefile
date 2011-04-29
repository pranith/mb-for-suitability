ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = ../include
CC = gcc
CPPFLAGS = -Wall $(DEBUG) -I$(IDIR)

EXEC = read64_dependent.exe read64_independent.exe read64_dependent2.exe read64_independent2.exe read64_independent3.exe

all: $(EXEC)

.PHONY: all 

$(EXEC): %.exe : %.o 
		  $(CC) $< -o $@ $(CPPFLAGS) 

$(OBJ): %.o : %.cpp 
		  $(CC) -o $@ -c $< $(CPPFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: clean
clean:
	rm -f *.o *.exe
