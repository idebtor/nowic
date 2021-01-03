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
OBJ1 = $(EXE1)x.o 
SRCS = $(OBJ1:.o=.cpp) 

all: $(EXE1)x $(SRCS)
$(EXE1)x: $(OBJ1)
	$(GCC) $(OBJ1) -o $(EXE1)x 

.PHONY: all clean debug install 

clean:
	rm -f *.exe *.o
debug: GCC += -DDEBUG 
install:
ifeq ($(OS),Windows_NT)
	cp hellowho.pdf names.txt makefile make.mac *.md *.exe ./deliverable
	cp -v ./deliverable/* ../../../nowic/psets/pset01
else
	cp $(EXE1)x ./deliverable
	cp -v $(EXE1)x ../../../nowic/psets/pset01
endif
