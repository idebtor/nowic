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

SRC1 = args1x.cpp printfuncx.cpp
SRC2 = args2x.cpp printfuncx.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
EXE1 = args1x
EXE2 = args2x

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

TARGET_FOLDER = ../../../nowic/labs/lab2
install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp lab2.md lab2.pdf makefile $(EXE1).exe $(EXE2).exe ./deliverable 
	cp args1.cpp args2.cpp printfunc.cpp ./deliverable 
	mkdir -p $(TARGET_FOLDER)
	cp -v ./deliverable/* $(TARGET_FOLDER)
else
	cp $(EXE1) $(EXE2) ./deliverable
	cp -v $(EXE1) $(EXE2) $(TARGET_FOLDER)
endif
