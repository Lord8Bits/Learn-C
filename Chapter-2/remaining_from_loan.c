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
    scanf("%f", &loan);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    interest_rate /= 12; // Converted to monthly interest rate so divided by 12 months

    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after first payment: %.2f", loan);
    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after second payment: %.2f", loan);
    loan = loan + (loan * interest_rate / 100) - monthly_payment;
    printf("\nBalance remaining after third payment: %.2f", loan);

    return EXIT_SUCCESS;
}
