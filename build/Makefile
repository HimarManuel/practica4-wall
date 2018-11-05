IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = context_t.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: wall

$(ODIR)/context_t.o: $(ODIR)/context_t.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/context_t.hpp $(IDIR)/wall_t.hpp $(IDIR)/row_t.hpp $(IDIR)/block_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

wall: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
