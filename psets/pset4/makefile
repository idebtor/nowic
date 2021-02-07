# a makefile example using multiple libraries and include 
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
	LDFLAGS = -L$(LIBDIR) -lsort -lnowic -lrand
else
	LDFLAGS = -L$(LIBDIR) -lsort_mac -lnowic_mac -lrand_mac
endif


$(info )
$(info To use main() in profiling.cpp as a standalone,)
$(info turn on, #if 1, just above main() in profiling.cpp)
$(info )
SRC1 = profiling.cpp 
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = profiling

#SRC2 = profile.cpp 
#OBJ2 = $(SRC2:.cpp=.o)
#EXE2 = profile#

$(info )
$(info To use main() in profilingDriver.cpp with profiling.cpp,)
$(info turn off, #if 0, just above main() in profiling.cpp)
$(info )
SRC3 = profile.cpp driver.cpp 
OBJ3 = $(SRC3:.cpp=.o)
EXE3 = driver

# rule for link
all: $(EXE1)  $(EXE2) $(EXE3) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

#$(EXE2): $(OBJ2)
#	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) $(OBJ2) $(EXE2) $(OBJ3) $(EXE3)
install:
ifeq ($(OS),Windows_NT)
	cp profiling.pdf makefile $(EXE3) ./deliverable
	cp profiling.cpp ./deliverable
	cp -v deliverable/* ../../../nowic/psets/pset4
	xcopy .vscode ..\..\..\nowic\psets\pset4\.vscode //E //H //K //Y //I 
else
	cp $(EXE3) ./deliverable
	cp -v $(EXE3) ../../../nowic/psets/pset4
endif

