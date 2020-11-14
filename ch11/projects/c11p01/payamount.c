#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens,
                int *fives, int *ones);
int main(void)
{
    int dollars, twenties, tens, fives, ones;

    printf("Enter number of dollars: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens,
               &fives, &ones);

    printf("Twenties: %d\n", twenties);
    printf("Tens: %d\n", tens);
    printf("Fives: %d\n", fives);
    printf("Ones: %d\n", ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens,
                int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;
    
    *ones = dollars;
}
