# a makefile example using multiple libraries and include 
# 
# Created by idebtor@gmail.com
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
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

SRC1 = graph.cpp driver.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = graph

# rule for link
all: $(EXE1)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) 
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp graph.pdf makefile $(EXE1).exe ./deliverable
	cp graph.cpp driver.cpp ./deliverable
	cp ../../include/graph.h ../../../nowic/include
	mkdir -p ../../../nowic/psets/pset15 && \
	cp -v deliverable/* ../../../nowic/psets/pset15
	xcopy .vscode ..\..\..\nowic\psets\pset15\.vscode //E //H //K //Y //I 
endif