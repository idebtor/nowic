# a makefile example using multiple libraries and include 
# 
# Created by idebtor@gmail.com
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
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

SRC0 = hashmap.cpp 
SRC1 = hash1.cpp hash1Driver.cpp 
SRC2 = hash2.cpp hash2Driver.cpp 

OBJ0 = $(SRC0:.cpp=.o)
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
EXE0 = hashmap
EXE1 = hash1
EXE2 = hash2

all: EXE0 EXE1 EXE2
EXE0: $(OBJ0)
	$(CC) -o $(EXE0) $(OBJ0) -I$(INCDIR) $(LDFLAGS)

EXE1: $(OBJ1)
	$(CC) -o $(EXE1) $(OBJ1) -I$(INCDIR) $(LDFLAGS)

EXE2: $(OBJ2)
	$(CC) -o $(EXE2) $(OBJ2) -I$(INCDIR) $(LDFLAGS)

# rule for link
all: $(EXE0) $(EXE1) $(EXE2)  
$(EXE0): $(OBJ0)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2): $(OBJ2)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install

clean:
	rm -f *.o *.exe $(OBJ0) $(EXE0)  $(OBJ1) $(EXE1)  $(OBJ2) $(EXE2) 

install:
ifeq ($(OS),Windows_NT)
	cp hashing.pdf hashingENG.pdf makefile kjv.txt shakespeare.txt ps23.txt 1co13.txt ./deliverable
	cp hash1x.exe hash2x.exe hashmapx.exe ./deliverable
	cp hash1Driver.cpp hash2Driver.cpp hash1.cpp hash2.cpp hashmap.cpp ./deliverable
	cp ../../include/hash?.h ../../../nowic/include
	cp -v ./deliverable/*   ../../../nowic/psets/pset-hashing
else
	cp -v $(EXE0) $(EXE1) $(EXE2) ./deliverable
	cp -v $(EXE0) $(EXE1) $(EXE2) ../../../nowic/psets/pset-hashing
endif
