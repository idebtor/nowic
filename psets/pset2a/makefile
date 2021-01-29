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
CCFLAGS = -Wall -std=c++11
#CCFLAGS += -DDEBUG -ggdb        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic -lrand
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac 
endif

SRC1 = recursionDriver.cpp recursion.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = recursion

SRCx = recursionDriver.cpp recursionx.cpp
OBJx = $(SRCx:.cpp=.o)
EXEx = recursionx

# rule for link
all: $(EXE1) $(EXEx) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXEx): $(OBJx)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f $(OBJ1) $(EXE1) $(OBJx) $(EXEx) 
install:
ifeq ($(OS),Windows_NT)
	cp pset2a.pdf makefile $(EXEx).exe    ./deliverable
	cp recursionDriver.cpp recursion.cpp  ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset2a
	xcopy .vscode ..\..\..\nowic\psets\pset2a\.vscode //E //H //K //Y //I 
else
	cp $(EXEx) ./deliverable
	cp -v $(EXEx) ../../../nowic/psets/pset2a
endif
