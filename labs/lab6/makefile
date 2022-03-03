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

SRC1 = bubble.cpp
SRC2 = insertion.cpp
SRC3 = merge.cpp
SRC4 = quick.cpp
SRC5 = selection.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
OBJ3 = $(SRC3:.cpp=.o) 
OBJ4 = $(SRC4:.cpp=.o) 
OBJ5 = $(SRC5:.cpp=.o) 
EXE1 = bubble
EXE2 = insertion
EXE3 = merge
EXE4 = quick
EXE5 = selection

# rule for link
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^     

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^  

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^  

$(EXE4): $(OBJ4)
	$(CC) -o $@ $^  

$(EXE5): $(OBJ5)
	$(CC) -o $@ $^  

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: all clean install 
clean:
	rm -f *.o *.exe $(EXE1) $(EXE2) $(EXE3)  $(EXE4) $(EXE5)

install:
ifeq ($(OS),Windows_NT)
	cp lab6.md makefile $(SRC2) $(SRC3) $(SRC4)  ./deliverable
	cp -v ./deliverable/* ../../../nowic/labs/lab6
	xcopy .vscode ..\..\..\nowic\labs\lab6\.vscode //E //H //K //Y //I 
else
	cp $(EXE2) $(EXE3) $(EXE4)  ./deliverable
	cp -v $(EXE2) $(EXE3) $(EXE4) ../../../nowic/labs/lab6
endif
