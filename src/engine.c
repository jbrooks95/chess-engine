#include <stdio.h>
#include <board.h>
#include <evaluate.h>

void main()
{
    board* b = init_board();
    print_board(b);
    printf("\n");

    char* fen = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
    char* fen2 = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
    board* b2 = parse_fen(fen2);
    print_board(b2);
    printf("\n");


    int eval = evaluate(b);
    printf("evaluation = %d", eval);
}
