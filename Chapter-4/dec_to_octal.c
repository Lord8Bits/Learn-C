//
// Created by lorend on 11/6/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);

    int max_digits = 5;
    int octal[max_digits];
    for (int i = max_digits - 1; i >= 0; i--)
    {
        octal[i] = num % 8; num = (num - num%8)/8;
    }

    printf("In octal (base 8), your number is: ");
    for (int i = 0; i < max_digits; i++)
        printf("%o", octal[i]);

    return EXIT_SUCCESS;
}
