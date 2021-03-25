# a makefile example using two libraries and include 
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
CCFLAGS = -std=c++11 -Wall -g
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac 
endif

SRC1 = factorial.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = factorial

SRC2 = driver.cpp recursion.cpp
OBJ2 = $(SRC2:.cpp=.o)
EXE2 = recursion

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
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp pset3a.pdf makefile ./deliverable
	cp driver.cpp recursion.cpp  ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset3a
	xcopy .vscode ..\..\..\nowic\psets\pset3a\.vscode //E //H //K //Y //I 
endif
