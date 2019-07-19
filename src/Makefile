CC=gcc
CFLAGS=-I.
DEPS = board.h bitboard.h evaluate.h movegen.h movelist.h static_bitboards.h
OBJ = board.o engine.o evaluate.o movegen.o movelist.o bitboard.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

engine: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

clean:
	/bin/rm -f *.o engine core.* vgcore.*
