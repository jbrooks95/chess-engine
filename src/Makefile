CC=gcc
CFLAGS=-I.
DEPS = board.h bitboard.h
OBJ = board.o engine.o 

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

engine: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

clean:
	/bin/rm -f *.o engine core.* vgcore.*
