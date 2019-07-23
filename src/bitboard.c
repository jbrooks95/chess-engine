#include <stdio.h>
#include <bitboard.h>
#include <board.h>

//function prototypes
int is_vacant(bitboard b, int i, int j);

bitboard start = (bitboard) 1;

void print_bitboard(bitboard b)
{
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("[");
            if(is_vacant(b, i,j))
            {
                printf(" ");
            }
            else
            {
                printf("X");
            }
            printf("]");
        }
        printf("\n");
    }
}

/*
 * Checks if given square is 
 * vacant
 */
int is_vacant(bitboard b, int i, int j)
{
   if(get_bitboard(i, j) & b) return 0;
   return 1;
}
