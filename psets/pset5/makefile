# a makefile example 
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

SRC1 = clock1.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = clock1

SRC2 = clock2.cpp 
OBJ2 = $(SRC2:.cpp=.o)
EXE2 = clock2

SRC3 = clock3.cpp 
OBJ3 = $(SRC3:.cpp=.o)
EXE3 = clock3

SRC4 = clock4.cpp 
OBJ4 = $(SRC4:.cpp=.o)
EXE4 = clock4

#SRC = clock.cpp clockDriver.cpp
#OBJ = $(SRC:.cpp=.o)
#EXE = clock

# rule for link
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE)

$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXE4): $(OBJ4)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)  

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -I$(INCDIR)

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(EXE1) $(EXE2) $(EXE3) $(EXE4) 
install:
ifeq ($(OS),Windows_NT)
	cp makefile pset-clock.pdf clockDriver.cpp ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset5
	xcopy .vscode ..\..\..\nowic\psets\pset5\.vscode //E //H //K //Y //I 
endif

