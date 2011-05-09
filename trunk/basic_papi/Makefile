ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = .
CC = gcc
CFLAGS = -lpapi -Wall $(DEBUG) -I$(IDIR)

EXEC = peak.exe index_array.exe newtest.exe read64_dependent.exe read64_base.exe read64_independent_0.exe read64_independent_2.exe read64_independent_4.exe read64_independent_6.exe read64_independent_8.exe
EXEC2 = read64_base_native.exe

all: $(EXEC)
native: $(EXEC2)

.PHONY: all 

$(EXEC): %.exe : %.o 
		  $(CC) -I$(IDIR) $< -o $@ $(CFLAGS) papi_base.c test_utils.c

$(EXEC2): %.exe :  
		  $(CC) -I$(IDIR) $< -o $@ $(CFLAGS) main.c

$(OBJ): %.o : %.cpp 
		  $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: debug
debug: clean
		  $(MAKE) $(MAKEFILE) all DEBUG="-g"

.PHONY: native
native: clean
		  $(MAKE) $(MAKEFILE) native 

.PHONY: clean
clean:
	rm -f *.o *.exe
