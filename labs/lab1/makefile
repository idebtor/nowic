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

SRC1 = cplus.cpp
OBJ1 = $(SRC1:.cpp=.o) 
EXE1 = cplus

# rule for link
all: $(EXE1) $(EXE2) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^     

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: all clean install 
clean:
	rm -f *.o *.exe $(EXE1) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab1.md makefile $(EXE1).exe ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab1
	xcopy .vscode ..\..\..\nowic\labs\lab1\.vscode //E //H //K //Y //I 
else
	cp $(EXE1) ./deliverable
	cp -v $(EXE1) ../../../nowic/labs/lab1
endif
