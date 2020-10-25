#include <stdio.h>

int main(void)
{
    int i, n;
    float balance, annual_interest_rate, monthly_interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);

    printf("Enter interest rate: ");
    scanf("%f", &annual_interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    printf("Enter number of payments: ");
    scanf("%d", &n);

    monthly_interest_rate = annual_interest_rate / 100.0f / 12.0f;

    for (i = 1; i <= n; i++) {
        balance = balance - monthly_payment + balance * monthly_interest_rate;
        printf("Balance remaining after payment %d: $%.2f\n", i, balance);
    }

    return 0;
}
