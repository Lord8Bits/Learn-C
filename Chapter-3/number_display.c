//
// Created by lorend on 11/2/25.
//

#include <stdio.h>
#include <stdlib.h>

#define M(r,c) (numbers[(r)*4 + (c)])

int main(void)
{
    int numbers[16];

    printf("Enter unique numbers between 1-16: " );
    for (int i = 0; i < 16; i++)
        scanf("%d", &numbers[i]);

    int col1 = 0, col2 = 0, col3 = 0, col4 = 0;
    for (int i = 0; i < 4; i++)
    {
        col1 += M(i, 0);
        col2 += M(i, 1);
        col3 += M(i, 2);
        col4 += M(i, 3);
    }

    int row1=0, row2=0, row3=0, row4=0;
    for (int i = 0; i < 4; i++)
    {
        row1 += M(0, i);
        row2 += M(1, i);
        row3 += M(2, i);
        row4 += M(3, i);
    }

    int diag1=0, diag2=0;
    for (int i = 0; i < 4; i++)
    {
        diag1 += M(i, i);
        diag2 += M(3 - i, i);
    }

    for (int i = 0; i < 4; i++)
        printf("%2d  %2d  %2d  %2d\n",
            M(i, 0), M(i, 1), M(i, 2), M(i, 3));

    printf("Row Sums: %d %d %d %d\n", row1, row2, row3, row4);
    printf("Column Sums: %d %d %d %d\n", col1, col2, col3, col4);
    printf("Diagonal Sums: %d %d", diag1, diag2);

    return EXIT_SUCCESS;
}
