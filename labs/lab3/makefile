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
#CCFLAGS += -DDEBUG -Og        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = times.cpp
SRC2 = setmax_val.cpp
SRC3 = setmax_ptr.cpp
SRC4 = setmax_ref.cpp
SRC5 = setmax_ret.cpp
SRC6 = touppers.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
OBJ3 = $(SRC3:.cpp=.o) 
OBJ4 = $(SRC4:.cpp=.o) 
OBJ5 = $(SRC5:.cpp=.o) 
OBJ6 = $(SRC6:.cpp=.o) 
EXE1 = times
EXE2 = setmax_val
EXE3 = setmax_ptr
EXE4 = setmax_ref
EXE5 = setmax_ret
EXE6 = touppers

# rule for link
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)  
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

$(EXE6): $(OBJ6)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< 

.PHONY: all clean install 
clean:
	rm -f *.o $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab3.md makefile $(EXE1).exe $(EXE2).exe $(EXE3).exe $(EXE6)x.exe ./deliverable 
	cp touppers.cpp ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab3
	xcopy .vscode ..\..\..\nowic\labs\lab3\.vscode //E //H //K //Y //I 
else
	cp $(EXE1) $(EXE2) $(EXE3) $(EXE6)x  ./deliverable
	cp -v $(EXE1) $(EXE2) $(EXE3) $(EXE6)x  ../../../nowic/labs/lab3
endif
