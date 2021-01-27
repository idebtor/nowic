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
CCFLAGS = -Wall -std=c++11 -g
#CCFLAGS += -DDEBUG           # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = selectionx.cpp printlist.cpp
OBJ1 = $(SRC1:.cpp=.o) 
EXE1 = selectionx

# rule for link
all: $(EXE1) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.cpp
	$(CC) -c $< 

.PHONY: all clean install 
clean:
	rm -f *.o $(EXE1) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab05.md makefile $(EXE1) selection.cpp ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab05
	xcopy .vscode ..\..\..\nowic\labs\lab05\.vscode //E //H //K //Y //I 
else
	cp $(EXE1)  ./deliverable
	cp -v $(EXE1)  ../../../nowic/labs/lab05
endif
