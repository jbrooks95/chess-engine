#include <stdio.h>
#include <board.h>
#include <static_bitboards.h>
#include <bitboard.h>
#include <evaluate.h>
#include <movegen.h>
#include <pickmove.h>
#include <movelist.h>
#include <test.h>
#include <stdlib.h>

//function prototypes
void tester(void);
void play(int);

#define MAX 1024

int main(int argc, char *argv[])
{
    int depth = 6;
    if(argc == 2)
    {
        if(argc == 2) depth = atoi(argv[1]);
        play(depth);
    }
    else
    {
        printf("Error. Please use: ./engine <depth>\n");
    }
    return 0;
}

void play(int depth)
{
    char buffer[MAX];
    board* b;
    move found_move;

    printf("Enter FEN: ");
    while(fgets(buffer, MAX, stdin))
    {
        b = parse_fen(buffer);
        found_move = pick_move(b, depth);
        if(found_move.piece == '#')
        {
            printf("No moves. It's checkmate.\n");
        }
        else
        {
            printf("Selected move: ");
            print_move(found_move);
            printf(", ");
            print_move_squares(found_move);
        }
        printf("\nEnter FEN: ");
    }
}

void tester()
{

    bitboard test = (bitboard) 16777216;
    printf(get_algebraic(test));
    printf("\n");
    printf("\n");
    printf("\n");

    //board* b = init_board();
    //print_board(b);
    //printf("\n");

    char* fen = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
    //char* fen2 = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
    //char* fen2 = "rnbqkbnr/pp2p1pp/2p5/3pPp2/2P5/8/PP1P1PPP/RNBQKBNR w KQkq f6 0 4";
    //char* fen2 = "rnbqkbnr/ppppp1P1/5p2/8/6p1/8/PPPPPP2/RNBQKBNR b KQkq - 0 5";
    //char* fen2 = "rnbqkbnr/pp1pp1P1/2p2p2/8/6p1/8/PPPPPP2/RNBQKBNR w KQkq - 0 6";
    //char* fen2 = "rnbqkbnr/pppp1ppp/8/4p3/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 2";
    //char* fen2 = "rnbqkb1r/pp1p1p1P/2p2n2/4p3/4P3/8/PPPP2PP/RNBQKBNR w KQkq - 0 6";
    //char* fen2 = "rnbqkbnr/pp1p1p1P/2p5/4p3/4P3/3P4/PPP3PP/RNBQKBNR w KQkq - 1 7";
    //char* fen2 = "rnbqkbnr/p2p1p1P/2p5/4p3/Pp1PP3/7P/1PP3P1/RNBQKBNR b KQkq a3 0 9";
    //char* fen2 = "rnbqkbnr/p2p1p1P/2p5/3Pp1B1/P3P3/7P/1Pp3P1/RN1QKBNR b KQkq - 1 11";
    //char* fen2 = "rnb1kbnr/pp1q1Q2/6pp/2ppP3/P3P3/2N5/1PPB2PP/R3KBNR b KQkq - 1 10";
    //char* fen2 = "rnbqkb1r/pppppppp/8/4N3/4n3/8/PPPPPPPP/RNBQKB1R b KQkq - 4 3";
    //char* fen2 = "2k5/2p5/1p1R1p1p/8/6K1/1P6/P4PP1/8 b - - 1 27";
    //char* fen2 = "rnbqkb1r/pp1p1ppp/2p2n2/4p2Q/2B1P3/8/PPPP1PPP/RNB1K1NR w KQkq - 0 4";
    char* fen2 = "r3r1k1/pppb1qbp/2np2p1/1N6/2PPp3/4BP2/PP1N2PP/R2Q1RK1 w - - 1 16";
    board* b2 = parse_fen(fen2);
    print_board(b2);
    printf("\n");


    move_list* test2 = generate_moves(b2);
    //print_moves(test2);

    //run_tests();

    int eval = evaluate(b2);
    printf("evaluation = %d", eval);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("white side: ");
    printf("\n");
    print_bitboard(WHITE_SIDE);
    printf("\n");

    printf("black side: ");
    printf("\n");
    print_bitboard(BLACK_SIDE);
    printf("\n");
    /*

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
}
