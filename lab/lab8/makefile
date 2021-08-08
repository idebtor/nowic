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
#CCFLAGS += -DDEBUG -Og        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic -lsort
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac -lsort_mac
endif

SRC1 = sortDriver.cpp
SRC2 = nowicDriver.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
EXE1 = sortDriver
EXE2 = nowicDriver

# rule for link
all: $(EXE1) $(EXE2) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^  $(LDFLAGS)

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^  $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -I$(INCDIR)

.PHONY: all clean install 
clean:
	rm -f *.o *.exe $(EXE1) $(EXE2) 

install:
ifeq ($(OS),Windows_NT)
	cp staticlib.pdf makefile ./deliverable
	cp $(EXE1) $(EXE2) ./deliverable
	cp -v ./deliverable/* ../../../nowic/labs/lab7
	xcopy .vscode ..\..\..\nowic\labs\lab7\.vscode //E //H //K //Y //I 
else
	cp $(EXE1) $(EXE2)  ./deliverable
	cp -v $(EXE1) $(EXE2)  ../../../nowic/labs/lab7
endif
