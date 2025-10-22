//
// Created by lorend on 10/19/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int money;

    printf("Enter a dollar amount: ");
    scanf("%d", &money);

    int bills20 = money / 20; money -= 20 * bills20;
    int bills10 = money / 10; money -= 10 * bills10;
    int bills5 = money / 5; money -= 5 * bills5;
    int bills1 = money;

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d",
         bills20, bills10, bills5, bills1);
    return EXIT_SUCCESS;
}
