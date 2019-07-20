#include <stdio.h>
#include <board.h>
#include <static_bitboards.h>
#include <bitboard.h>
#include <evaluate.h>
#include <movegen.h>

void main()
{

    bitboard test = (bitboard) 16777216;
    printf(get_algebraic(test));
    printf("\n");
    printf("\n");
    printf("\n");

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
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    /*
    printf("rank1: ");
    printf("\n");
    print_bitboard(RANK_1);
    printf("\n");

    printf("rank2: ");
    printf("\n");
    print_bitboard(RANK_2);
    printf("\n");

    printf("rank3: ");
    printf("\n");
    print_bitboard(RANK_3);
    printf("\n");

    printf("rank4: ");
    printf("\n");
    print_bitboard(RANK_4);
    printf("\n");

    printf("rank5: ");
    printf("\n");
    print_bitboard(RANK_5);
    printf("\n");

    printf("rank6: ");
    printf("\n");
    print_bitboard(RANK_6);
    printf("\n");

    printf("rank7: ");
    printf("\n");
    print_bitboard(RANK_7);
    printf("\n");

    printf("rank8: ");
    printf("\n");
    print_bitboard(RANK_8);
    printf("\n");

    printf("file a: ");
    printf("\n");
    print_bitboard(FILE_A);
    printf("\n");

    printf("file b: ");
    printf("\n");
    print_bitboard(FILE_B);
    printf("\n");

    printf("file c: ");
    printf("\n");
    print_bitboard(FILE_C);
    printf("\n");

    printf("file d: ");
    printf("\n");
    print_bitboard(FILE_D);
    printf("\n");

    printf("file e: ");
    printf("\n");
    print_bitboard(FILE_E);
    printf("\n");

    printf("file f: ");
    printf("\n");
    print_bitboard(FILE_F);
    printf("\n");

    printf("file g: ");
    printf("\n");
    print_bitboard(FILE_G);
    printf("\n");

    printf("file h: ");
    printf("\n");
    print_bitboard(FILE_H);
    printf("\n");

    printf("kingside: ");
    printf("\n");
    print_bitboard(KINGSIDE);
    printf("\n");

    printf("queenside: ");
    printf("\n");
    print_bitboard(QUEENSIDE);
    printf("\n");

    printf("center: ");
    printf("\n");
    print_bitboard(CENTER);
    printf("\n");

    printf("extended center: ");
    printf("\n");
    print_bitboard(EXTENDED_CENTER);
    printf("\n");
    */

    move_list* test2 = generate_moves(b2);
    print_moves(test2);
}
