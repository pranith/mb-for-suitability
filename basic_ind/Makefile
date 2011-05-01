ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = ../include
CC = gcc
CPPFLAGS = -Wall $(DEBUG) -I$(IDIR)

EXEC = read64_independent_0.exe read64_independent_2.exe read64_independent_4.exe read64_independent_6.exe read64_independent_8.exe read64_base.exe

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
