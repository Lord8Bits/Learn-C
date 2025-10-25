//
// Created by lorend on 10/19/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float money;

    printf("Enter the dollar-cents amount: ");
    if (scanf("%f", &money) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }

    printf("With tax added: $%.3f\n", money * 1.05);

    return EXIT_SUCCESS;
}
