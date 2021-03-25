# a makefile example using multiple libraries and include 
# 
# 2020/03/05 Created by idebtor@gmail.com
# 2021/01/02 proflie.cpp - updated for macOS and DEBUG options
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
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic -lsort -lrand
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac -lsort_mac -lrand_mac
endif

$(info )
$(info To use main() in profiling.cpp or profile.cpp as a standalone,)
$(info turn on, set #if 1, just above main() in profiling.cpp or profile.cpp)
$(info )
SRC1 = profiling.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = profiling

# rule for link
all: $(EXE1)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE2): $(OBJ2)
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
	cp profiling.pdf makefile $(EXE1).exe ./deliverable
	cp profiling.cpp ./deliverable
	mkdir -p ../../../nowic/psets/pset4 && \
	cp -v deliverable/* ../../../nowic/psets/pset4
	xcopy .vscode ..\..\..\nowic\psets\pset4\.vscode //E //H //K //Y //I 
else
	cp $(EXE1) ./deliverable
	cp -v $(EXE1) ../../../nowic/psets/pset4
endif

