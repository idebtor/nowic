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

SRC3 = clock3.cpp 
OBJ3 = $(SRC3:.cpp=.o)
EXE3 = clock3

SRC4 = clock4.cpp 
OBJ4 = $(SRC4:.cpp=.o)
EXE4 = clock4

SRCx = clockx.cpp clockDriver.cpp
OBJx = $(SRCx:.cpp=.o)
EXEx = clockx

# rule for link
all: $(EXE3) $(EXE4) $(EXEx)

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXE4): $(OBJ4)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(EXEx): $(OBJx)
	$(CC) -o $@ $^ $(LDFLAGS)  

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -I$(INCDIR)

.PHONY: all clean install
clean:
	rm -f *.o  $(EXE3) $(EXE4) $(EXEx)
install:
ifeq ($(OS),Windows_NT)
	cp makefile lab9clock.pdf $(EXE3) $(EXE4)  $(EXEx) ./deliverable
	cp -v deliverable/* ../../../nowic/labs/lab9
	xcopy .vscode ..\..\..\nowic\labs\lab9\.vscode //E //H //K //Y //I 
else
	cp $(EXE3) $(EXE4)  $(EXEx) ./deliverable
	cp -v $(EXE3) $(EXE4)  $(EXEx) ../../../nowic/labs/lab9
endif
