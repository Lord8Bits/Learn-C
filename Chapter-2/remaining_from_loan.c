//
// Created by lorend on 10/19/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
    calculates the remaining balance on a loan after the first, second, and
    third monthly payments
     */
    float loan, interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    if (scanf("%f", &loan) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }
    printf("Enter the interest rate: ");
    if (scanf("%f", &interest_rate) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }
    printf("Enter monthly payment: ");
    if (scanf("%f", &monthly_payment) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }

    interest_rate /= 12; // Converted to monthly interest rate so divided by 12 months

    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after first payment: %.2f", loan);
    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after second payment: %.2f", loan);
    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after third payment: %.2f\n", loan);

    return EXIT_SUCCESS;
}
