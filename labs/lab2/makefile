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
CCFLAGS = -Wall -std=c++11 -g
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = args1.cpp printfunc.cpp
SRC2 = args2.cpp printfunc.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
EXE1 = args1
EXE2 = args2

# rule for link
all: $(EXE1) $(EXE2) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ 

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -I$(INCDIR)

.PHONY: all clean install 
clean:
	rm -f *.o *.exe $(EXE1) $(EXE2) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab2.md makefile $(EXE1)x.exe $(EXE2)x.exe ./deliverable 
	cp args1.cpp args2.cpp printfunc.cpp ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab2
	xcopy .vscode ..\..\..\nowic\labs\lab2\.vscode //E //H //K //Y //I 
else
	cp $(EXE1)x $(EXE2)x ./deliverable
	cp -v $(EXE1) $(EXE2)x ../../../nowic/labs/lab2
endif
