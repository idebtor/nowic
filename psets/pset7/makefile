# 
# 2020/03/05 Created by idebtor@gmail.com
# 2021/01/02 Updated for macOS and DEBUG options
#
# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
# $* The stem (the bit which matches the % wildcard in the rule definition.
#
CC = g++ $(CCFLAGS)

LIBDIR = ../../lib
INCDIR = ../../include
CCFLAGS = -Wall -std=c++11 -g 
#CCFLAGS += -DDEBUG      # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = infix.cpp infixDriver.cpp
SRC2 = infixall.cpp infixallDriver.cpp
SRC3 = postfix.cpp postfixDriver.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
OBJ3 = $(SRC3:.cpp=.o) 
EXE1 = infix
EXE2 = infixall
EXE3 = postfix

# rule for link
all: $(EXE1) $(EXE2) $(EXE3)
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^     

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^  

$(EXE3): $(OBJ3)
	$(CC) -o $@ $^  

# rule for compilation
%.o: %.cpp
	$(CC) -c $<

.PHONY: all clean install 
clean:
	rm -f *.o $(EXE1) $(EXE2) $(EXE3)

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp infixpostfix.pdf makefile ./deliverable
	cp infix.cpp infixDriver.cpp ./deliverable
	cp infixall.cpp infixallDriver.cpp ./deliverable
	cp postfix.cpp postfixDriver.cpp ./deliverable
	mkdir -p ../../../nowic/psets/pset7 && \
	cp -v ./deliverable/* ../../../nowic/psets/pset7
endif
