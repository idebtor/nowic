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
#CCFLAGS += -DDEBUG -ggdb        # uncomment for debugging
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif

# macro for files (sources, objects, executable)
SRCS = hellowhox.cpp 
OBJS = $(SRCS:.cpp=.o) 
EXEC = hellowhox

all: $(EXEC) 
# rule for link
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.cpp
	$(CC) -c $<

.PHONY: all clean install 
clean:
	rm -f $(EXEC) $(OBJS)

install:
ifeq ($(OS),Windows_NT)
	cp hellowho.pdf names.txt makefile *.md $(EXEC).exe ./deliverable
	cp -v ./deliverable/* ../../../nowic/psets/pset01
else
	cp $(EXEC) ./deliverable
	cp -v $(EXEC) ../../../nowic/psets/pset01
endif
