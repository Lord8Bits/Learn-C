//
// Created by lorend on 10/19/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float money;

    printf("Enter the dollar-cents amount: ");
    scanf("%f", &money);

    printf("With tax added: $%.3f", money * 1.05);

    return EXIT_SUCCESS;
}
