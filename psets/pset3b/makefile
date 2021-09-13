# a makefile example using two libraries and include 
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
CCFLAGS = -Wall -std=c++11
#CCFLAGS += -DDEBUG -ggdb        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic 
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac 
endif

SRC1 = binsearch.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = binsearch

#SRC1T = binsearchT.cpp 
#OBJ1T = $(SRC1T:.cpp=.o)
#EXE1T = binsearchT

# rule for link
all: $(EXE1) $(EXE1T) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

#$(EXE1T): $(OBJ1T)
#	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS)  -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(EXE1) $(EXE1T)
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp pset3b.pdf makefile ./deliverable
	cp binsearch.cpp ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset3b
	xcopy .vscode ..\..\..\nowic\psets\pset3b\.vscode //E //H //K //Y //I 
endif
