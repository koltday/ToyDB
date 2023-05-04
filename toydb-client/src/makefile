IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++20

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = user.h toydb.h clientsocket.h serversocket.h socket.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o toydb.o user.o clientsocket.o serversocket.o socket.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

toydb: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
