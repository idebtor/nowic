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
CCFLAGS = -Wall -std=c++11 
#CCFLAGS += -DDEBUG -Og        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

SRC1 = cprog.cpp
SRC2 = cplus.cpp
OBJ1 = $(SRC1:.cpp=.o) 
OBJ2 = $(SRC2:.cpp=.o) 
EXE1 = cprog
EXE2 = cplus

# rule for link
all: $(EXE1) $(EXE2) 
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^     

$(EXE2): $(OBJ2)
	$(CC) -o $@ $^  

# rule for compilation
%.o: %.cpp
	$(CC) -c $<

.PHONY: all clean install 
clean:
	rm -f *.o $(EXE1) $(EXE2) 

install:
ifeq ($(OS),Windows_NT)
	mkdir -p ./deliverable && \
	cp "1-8 lab01.pdf" makefile $(EXE2) ./deliverable 
	cp -v ./deliverable/* ../../../nowic/labs/lab01
else
	cp $(EXE2) ./deliverable
	cp -v $(EXE2) ../../../nowic/labs/lab01
endif
