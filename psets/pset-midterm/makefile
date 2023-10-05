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

SRC1 = quecirx.cpp driver.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = quecirx

# rule for link
all: $(EXE1) $(EXE2) $(EXE3)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) 
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp quecir.pdf driver.cpp makefile $(EXE1).exe  ./deliverable
	mkdir -p ../../../nowic/psets/pset-midterm && \
	cp -v deliverable/* ../../../nowic/psets/pset-midterm
	xcopy .vscode ..\..\..\nowic\psets\pset-midterm\.vscode //E //H //K //Y //I 
endif

