ifneq (DEBUG, "-g")
	DEBUG += -O2
endif

IDIR = ../include
CC = icc
CPPFLAGS = -Wall $(DEBUG) -I$(IDIR)

EXEC = read64_base.exe

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
