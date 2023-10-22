# a makefile example using multiple libraries and include 
# 
# Created by idebtor@gmail.com
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
	LDFLAGS = -L$(LIBDIR) -lnowic -lrand
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac -lrand_mac
endif

SRC1 = listdbl.cpp driver.cpp
OBJ1 = $(SRC1:.cpp=.o)
EXE1 = listdbl

# rule for link
all: $(EXE1)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

# rule for compilation
%.o: %.cpp
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o *.exe $(OBJ1) $(EXE1) 

TARGET_PATH = ../../../nowic/psets/pset8
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp listdbl.pdf listdblENG.pdf makefile ./deliverable
	cp listdbl.cpp driver.cpp ./deliverable
	mkdir -p $(TARGET_PATH) && \
	cp -v deliverable/* $(TARGET_PATH)
	#xcopy .vscode $(TARGET_PATH)/.vscode //E //H //K //Y //I 
endif

