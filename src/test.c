#include <test.h>
#include <stdio.h>
#include <board.h>

// function prototypes
void assert(int, int, int);
void test_is_king_checked(void);

void run_tests()
{
    printf("\n");
    printf("//////////////////////\n");
    printf("//////////////////////\n");
    printf("////////TESTER////////\n");
    printf("//////////////////////\n");
    printf("//////////////////////\n");
    printf("\n");

    test_is_king_checked();
}

void test_is_king_checked()
{
    printf("Test: is_king_checked\n");
    char* fen;
    board* b;
    int count = 1;

    fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "rnbqkbnr/pppp1ppp/8/4p3/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 2";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "rnb1kbnr/pppp1ppp/8/4p3/4PP1q/8/PPPP2PP/RNBQKBNR b KQkq - 1 3";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/4q3/8/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/4q3/8/4P3/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/1q2K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/1q1PK3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/8/4q3 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/4P3/8/4q3 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K2q/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4KP1q/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/4r3/8/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/4r3/8/4P3/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/1r2K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/1j1PK3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/8/4r3 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/4P3/8/4r3 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K2r/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4KP1r/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/2q5/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/2q5/3P4/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/7q/8/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/7q/6P1/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/6q1/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/5P2/6q1/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/2q5/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/3P4/2q5/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/2b5/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/2b5/3P4/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/7b/8/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/7b/6P1/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/6b1/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/5P2/6b1/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/8/2b5/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/3P4/2b5/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/5p2/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/3p4/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/3p4/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/8/8/4K3/5p2/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 0, count++);

    fen = "8/8/3n4/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/5n2/8/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/6n1/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/6n1/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/8/5n2/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/8/3n4/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/8/4K3/2n5/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);

    fen = "8/8/8/2n5/4K3/8/8/8 b - -";
    b = parse_fen(fen);
    assert(is_king_checked(b), 1, count++);
}

void assert(int actual, int expected, int count)
{
    if(actual == expected)
    {
        printf("Test %d: PASS\n", count);
    }
    else 
    {
        printf("Test %d: FAIL\n", count);
    }
}
