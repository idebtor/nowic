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
	LDFLAGS = -L$(LIBDIR) -lnowic 
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac 
endif

SRC1 = binsearch.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = binsearch

SRC1x = binsearchx.cpp 
OBJ1x = $(SRC1x:.cpp=.o)
EXE1x = binsearchx

SRC1Tx = binsearchTx.cpp 
OBJ1Tx = $(SRC1x:.cpp=.o)
EXE1Tx = binsearchTx

# rule for link
all: $(EXE1) $(EXE1x) $(EXE1Tx)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE1x): $(OBJ1x)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE1Tx): $(OBJ1Tx)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(EXE1x) $(EXE1Tx)
install:
ifeq ($(OS),Windows_NT)
	cp pset2b.pdf makefile $(EXE1x) $(EXE1Tx) ./deliverable
	cp binsearch.cpp ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset2b
	xcopy .vscode ..\..\..\nowic\psets\pset2b\.vscode //E //H //K //Y //I 
else
	cp $(EXE1x) $(EXE1Tx)  ./deliverable
	cp -v $(EXE1x) $(EXE1Tx) ../../../nowic/psets/pset2b
endif
