//
// Created by lorend on 11/4/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, digit1, digit2, digit3;
    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    digit1 = num % 10; num /= 10;
    digit2 = num % 10; num /= 10;
    digit3 = num % 10; num /= 10;

    printf("The reversal is: %d%d%d", digit1, digit2, digit3);

    return EXIT_SUCCESS;
}
