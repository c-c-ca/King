#include <stdio.h>

int main(void)
{
    int n;
    const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    printf("Enter a two digit number: ");
    scanf("%2d", &n);

    printf("You entered the number: ");
    if (n / 10 == 1)
        printf("%s", teens[n % 10]); 
    else
        printf("%s%s%s",
                tens[n / 10],
                n / 10 != 0 && n % 10 != 0 ? "-" : "",
                ones[n % 10]);
    printf(".\n");

    return 0;
}
