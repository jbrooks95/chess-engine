#include <test.h>
#include <stdio.h>
#include <board.h>
#include <movelist.h>

// function prototypes
void assert(int, int, int);
void assert_board_equality(board* actual, board* expected, int count);
void test_is_king_checked(void);
void test_make_move(void);

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
    test_make_move();
}

void test_make_move()
{
    printf("Test: move\n");
    bitboard start = (bitboard) 1;
    char* before_fen;
    char* after_fen;
    board* before;
    board* after;
    int count = 1;

    before_fen = "rnb1kbnr/pppp1ppp/8/4p3/4PP1q/6P1/PPPP3P/RNBQKBNR b KQkq - 0 1";
    after_fen = "rnb1kbnr/pppp1ppp/8/4p3/4PP2/6q1/PPPP3P/RNBQKBNR w KQkq - 0 2";
    before = parse_fen(before_fen);
    after = parse_fen(after_fen);

    move m = 
    {
        .is_capture = 1,
        .is_en_passant = 0,
        .promotion = 0,
        .castling = 'x',
        .piece = 'q',
        .origin = start<<24,
        .target = start<<17
    };
    make_move(before, m);
    assert_board_equality(before, after, count++);
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

void assert_board_equality(board* actual, board* expected, int count)
{
    if(actual->to_move != expected->to_move ||
            actual->en_passant != expected->en_passant ||
            actual->castling != expected->castling ||
            actual->halfmove_clock != expected->halfmove_clock ||
            actual->fullmove_count != expected->fullmove_count ||
            actual->all_pieces != expected->all_pieces ||
            actual->white_pieces != expected->white_pieces ||
            actual->black_pieces != expected->black_pieces ||
            actual->empty_squares != expected->empty_squares ||
            actual->white_king != expected->white_king ||
            actual->white_queen != expected->white_queen ||
            actual->white_bishops != expected->white_bishops ||
            actual->white_knights != expected->white_knights ||
            actual->white_rooks != expected->white_rooks ||
            actual->white_pawns != expected->white_pawns ||
            actual->black_king != expected->black_king ||
            actual->black_queen != expected->black_queen ||
            actual->black_bishops != expected->black_bishops ||
            actual->black_knights != expected->black_knights ||
            actual->black_rooks != expected->black_rooks ||
            actual->black_pawns != expected->black_pawns)
    {
        printf("Test %d: FAIL\n", count);
    }
    else 
    {
        printf("Test %d: PASS\n", count);
    }
}





