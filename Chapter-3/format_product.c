//
// Created by lorend on 11/2/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int item_id, buy_month, buy_day, buy_year;
    float item_price;
    printf("Enter item number: ");
    scanf("%d", &item_id);

    printf("Enter unit price: ");
    scanf("%f", &item_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &buy_month, &buy_day, &buy_year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\t\tPrice\t\tDate\n");
    printf("%3d\t\t\t$%-7.2f\t\t%.2d/%.2d/%d",
                item_id, item_price, buy_month, buy_day, buy_year);

    return EXIT_SUCCESS;
}
