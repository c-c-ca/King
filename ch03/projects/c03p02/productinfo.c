#include <stdio.h>

int main(void)
{
	float price;
	int item, month, day, year;

	printf("Enter item number: ");
	scanf("%d", &item);

	printf("Enter unit price: ");
	scanf("%f", &price);

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &month, &day, &year);

	printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%d\t\t$% 7.2f\t%d/%d/%d\n", item, price, month, day, year);

	return 0;
}
