#include <stdio.h>
#include <board.h>
#include <evaluate.h>

void main()
{
    board* b = init_board();
    print_board(b);
    int eval = evaluate(b);
    printf("evaluation = %d", eval);
}
