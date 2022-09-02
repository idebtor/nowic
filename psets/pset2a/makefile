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
CCFLAGS = -std=c++11 -Wall -g 
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR)
else
	LDFLAGS = -L$(LIBDIR) 
endif

SRC1 = calc1.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = calc1
SRC2 = calc2.cpp 
OBJ2 = $(SRC2:.cpp=.o)
EXE2 = calc2
SRC3 = calc3.cpp 
OBJ3 = $(SRC3:.cpp=.o)
EXE3 = calc3
SRC4 = map.cpp 
OBJ4 = $(SRC4:.cpp=.o)
EXE4 = map

# rule for link
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2): $(OBJ2)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE3): $(OBJ3)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE4): $(OBJ4)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) $(OBJ2) $(EXE2) $(OBJ3) $(EXE3) $(OBJ4) $(EXE4) 
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp pset2a.pdf makefile $(EXE3) $(EXE4) ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset2a
	xcopy .vscode ..\..\..\nowic\psets\pset2a\.vscode //E //H //K //Y //I 
else
	cp $(EXE3) $(EXE4) ./deliverable
	cp -v $(EXE3) $(EXE4) ../../../nowic/psets/pset2a
endif
