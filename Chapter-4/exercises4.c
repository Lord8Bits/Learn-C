//
// Created by lorend on 11/3/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j,k;
    i = 5; j = 3;
    printf("%d %d\n", i / j, i % j); // 1 2
    i = 2; j = 3;
    printf("%d\n", (i+10) % j); // 0
    i = 7; j = 8; k = 9;
    printf("%d\n", (i+10) % k / j); // 1 / % and * is read from left to right
    i = 1; j = 2; k = 3;
    printf("%d\n", (i+5) % (j+2) / k); // 0

    return EXIT_SUCCESS;
}
