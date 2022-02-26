# 
# 2020/03/05 Created by idebtor@gmail.com
# 2021/01/02 Updated for macOS and DEBUG options
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
# $* The stem (the bit which matches the % wildcard in the rule definition.
#
CC = g++ $(CCFLAGS)

LIBDIR = ../../lib
INCDIR = ../../include
CCFLAGS = -std=c++11 -Wall -g
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = hellowho.cpp
SRC2 = helloargs.cpp
SRC3 = hellofunc.cpp printfunc.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
OBJ3 = $(SRC3:.cpp=.o) 
EXE1 = hellowho
EXE2 = helloargs
EXE3 = hellofunc

# rule for link
all: $(EXE1) $(EXE2) $(EXE3) 

$(EXE1): $(OBJ1)
	$(CC) -o $@ $^     

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^  

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^  

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: all clean install 
clean:
	rm -f *.o *.exe $(EXE1) $(EXE2) $(EXE3) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp pset1-KOR.pdf makefile names.txt argcargv.md getinputs.md ./deliverable
	cp $(EXE3) ./deliverable
	cp -v ./deliverable/* ../../../nowic/psets/pset1
	xcopy .vscode ..\..\..\nowic\psets\pset1\.vscode //E //H //K //Y //I 
else
	cp $(EXE3) ./deliverable
	cp -v $(EXE3) ../../../nowic/psets/pset1
endif
