//
// Created by lorend on 10/19/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <bits/posix2_lim.h>

int main(void)
{
    int x;

    printf("Enter the value of x for the polynomial"
            " ((((3x + 2) x - 5) x - 1) x + 7) x - 6: ");
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }

    int result = ((((3*x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}
