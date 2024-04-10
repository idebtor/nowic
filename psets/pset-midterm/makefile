# a makefile example using multiple libraries and include 
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
#
CC = g++
LIBDIR = ../../lib
INCDIR = ../../include
CCFLAGS = -Wall -std=c++11 -g 
#CCFLAGS += -DDEBUG        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L../../lib -lnowic
else
	LDFLAGS = -L../../lib -lnowic_mac
endif

SRC1 = cirque1x.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = cirque1x
SRC = cirquex.cpp driver.cpp
OBJ = $(SRC:.cpp=.o)
EXE = cirquex

# rule for link
all: $(EXE1) $(EXE)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp $(INCDIR)/cirque.h
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) $(OBJ) $(EXE) 
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp cirque.pdf makefile cirque1.cpp driver.cpp $(EXE1).exe $(EXE).exe ./deliverable
	mkdir -p ../../../nowic/psets/pset-midterm && \
	cp -v deliverable/* ../../../nowic/psets/pset-midterm
	xcopy .vscode ..\..\..\nowic\psets\pset-midterm\.vscode //E //H //K //Y //I 
else
	cp $(EXE1) $(EXE)  ./deliverable
	cp -v $(EXE1) $(EXE)  ../../../nowic/psets/pset-midterm
endif
