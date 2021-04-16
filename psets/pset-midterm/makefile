# a makefile example using multiple libraries and include 
# 
# 2020/03/05 Created by idebtor@gmail.com
# 2021/01/02 Updated for macOS and DEBUG options
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
# $* The stem (the bit which matches the % wildcard in the rule definition.
#
CC = g++
LIBDIR = ../../lib
INCDIR = ../../include
CCFLAGS = -Wall -std=c++11 -g 
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = 
else
	LDFLAGS = 
endif

SRC1 = dial800.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = dial800

SRC2 = dialmap.cpp
OBJ2 = $(SRC2:.cpp=.o)
EXE2 = dialmap

# rule for link
all: $(EXE1)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE2): $(OBJ2)
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
	cp dial.pdf minstack.pdf makefile ./deliverable
	cp dial800.cpp ./deliverable
	mkdir -p ../../../nowic/psets/pset-midterm && \
	cp -v deliverable/* ../../../nowic/psets/pset-midterm
	xcopy .vscode ..\..\..\nowic\psets\pset-midterm\.vscode //E //H //K //Y //I 
endif

