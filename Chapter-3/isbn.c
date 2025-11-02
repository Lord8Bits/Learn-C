//
// Created by lorend on 11/2/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter ISBN: ");
    int GSL, grp_id, pub_code, item_id, check_digit;
    scanf("%d-%d-%d-%d-%d",
          &GSL, &grp_id, &pub_code, &item_id, &check_digit);
    printf("GSL prefix: %d\n", GSL);
    printf("Group identifier: %d\n", grp_id);
    printf("Publisher code: %d\n", pub_code);
    printf("Item number: %d\n", item_id);
    printf("Check digit: %d\n", check_digit);

    return EXIT_SUCCESS;
}
