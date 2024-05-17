# a makefile example using multiple libraries and include 
# 
# Created by idebtor@gmail.com
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
# $* The stem (the bit which matches the % wildcard in the rule definition.
#
CC = g++
LIBDIR = ../../lib
INCDIR = ../../include
CCFLAGS = -std=c++11 -Wall -g 
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic 
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac 
endif

SRC1 = heapsort.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = heapsort

SRC2 = heap.cpp driver.cpp heapprint.cpp treeprint.cpp
OBJ2 = $(SRC2:.cpp=.o)
EXE2 = heap

# rule for link
all: $(EXE1) $(EXE2) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) $(OBJ2) $(EXE2) 

TARGET_PATH = ../../../nowic/psets/pset10-11	
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp heap.pdf makefile ./deliverable
	cp heap.cpp heapsort.cpp driver.cpp ./deliverable
	cp heapprint.cpp treeprint.cpp ./deliverable
	mkdir -p $(TARGET_PATH) && \
	cp -v deliverable/* $(TARGET_PATH) 
	xcopy .vscode $(TARGET_PATH)/.vscode //E //H //K //Y //I 
endif

