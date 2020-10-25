#include <stdio.h>

int main(void)
{
    float balance, annual_interest_rate, monthly_interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);

    printf("Enter interest rate: ");
    scanf("%f", &annual_interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    monthly_interest_rate = annual_interest_rate / 100.0f / 12.0f;

    balance = balance + balance * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", balance);

    balance = balance + balance * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", balance);

    balance = balance + balance * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", balance);

    return 0;
}