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
#CCFLAGS += -DDEBUG           # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = selection.cpp printlist.cpp
OBJ1 = $(SRC1:.cpp=.o) 
EXE1 = selection

# rule for link
all: $(EXE1) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< 

.PHONY: all clean install 
clean:
	rm -f *.o $(EXE1) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab5.md makefile ./deliverable 
	cp selection.cpp printlist.cpp ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab5
	xcopy .vscode ..\..\..\nowic\labs\lab5\.vscode //E //H //K //Y //I 
endif
