//
// Created by lorend on 11/2/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %d%.2d%.2d", year, month, day);

    return EXIT_SUCCESS;
}
