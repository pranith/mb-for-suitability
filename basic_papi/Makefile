ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = .
CC = gcc
CFLAGS = -lpapi -Wall $(DEBUG) -I$(IDIR)

EXEC = read64_dependent.exe read64_base.exe # read64_dependent2.exe read64_independent2.exe read64_independent3.exe

all: $(EXEC)

.PHONY: all 

$(EXEC): %.exe : %.o 
		  $(CC) -I$(IDIR) $< -o $@ $(CFLAGS) papi_base.c test_utils.c

$(OBJ): %.o : %.cpp 
		  $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: clean
clean:
	rm -f *.o *.exe
