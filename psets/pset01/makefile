# created by idebtor@gmail.com
# $@ : current target name
# $^ : the list of items of the current dependency
GCC = g++
LIBDIR = ../../lib
INCDIR = ../../include
ifeq ($(OS),Windows_NT)
	LDFLAGS = -L$(LIBDIR) -lnowic
else
	LDFLAGS = -L$(LIBDIR) -lnowic_mac
endif
CCFLAGS = -std=c++11 -ggdb -I$(INCDIR)

EXE1 = hellowho
SRCS = $(EXE1).cpp 
OBJS = $(SRCS:.cpp=.o) 

all: $(EXE1) $(SRCS)
$(EXE1): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE1)

.PHONY: all clean debug install 

clean:
	rm -f *.exe *.o
debug: GCC += -DDEBUG 
install:
ifeq ($(OS),Windows_NT)
	cp hellowho.pdf names.txt makefile *.md *.exe ./deliverable
	cp -v ./deliverable/* ../../../nowic/psets/pset01
else
	cp $(EXE1) ./deliverable
	cp -v $(EXE1) ../../../nowic/psets/pset01
endif
