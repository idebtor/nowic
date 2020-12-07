# makefile - final pset hashing
# 2020/12/04	created by idebtor@gmail.com
.SUFFIXES: .cpp .o
GCC = g++
INCDIR = ../../include
#LIBDIR = ../../lib
#LDFLAGS = -L$(LIBDIR) -lnowic
CFLAGS = -std=c++11 -I$(INCDIR)

SRC0 = hashmapx.cpp nowic.cpp
SRC1 = hash1x.cpp hash1Driver.cpp nowic.cpp
SRC2 = hash2x.cpp hash2Driver.cpp nowic.cpp

OBJ0 = $(SRC0:.cpp=.o)
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
EXE0 = hashmapx
EXE1 = hash1x
EXE2 = hash2x

all: EXE0 EXE1 EXE2

%.o:%.cpp $(INCDIR)/nowic.h
	$(GCC) -c -o $@ $< $(CFLAGS)

EXE0: $(OBJ0)
	$(GCC) -o $(EXE0) $(OBJ0) -I$(INCDIR) $(LDFLAGS)

EXE1: $(OBJ1)
	$(GCC) -o $(EXE1) $(OBJ1) -I$(INCDIR) $(LDFLAGS)

EXE2: $(OBJ2)
	$(GCC) -o $(EXE2) $(OBJ2) -I$(INCDIR) $(LDFLAGS)

dep:
	gccmakedep $(SRC0) $(SRC1) $(SRC2)

.PHONY: all clean cleanx install
clean:
	rm -f *.o
cleanx:
	rm -f *.exe *.o
debug:
	GCC += -DDEBUG -g

install:
	cp hash.pdf kjv.txt shakespeare.txt ps23.txt 1co13.txt makefile ./deliverable
	cp hash1Driver.cpp hash2Driver.cpp hash1.cpp hash2.cpp hashmap.cpp nowic.cpp ./deliverable
	cp hash1x.exe hash2x.exe hashmapx.exe ./deliverable
	cp ../../include/hash?.h ../../../nowic/include
	cp ../../include/nowic.h ../../../nowic/include
	cp ./deliverable/*   ../../../nowic/psets/pset-final
