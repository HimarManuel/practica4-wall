IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = wall_t.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: wall

$(ODIR)/wall_t.o: $(ODIR)/wall_t_remake.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/wall_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

wall: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
