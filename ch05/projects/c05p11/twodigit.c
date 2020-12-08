#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a two digit number: ");
    scanf("%2d", &n);

    printf("You entered the number: ");
    if (n / 10 == 1)
        switch(n % 10) {
            case 0: printf("ten");       break;
            case 1: printf("eleven");    break;
            case 2: printf("twelve");    break;
            case 3: printf("thirteen");  break;
            case 4: printf("fourteen");  break;
            case 5: printf("fifteen");   break;
            case 6: printf("sixteen");   break;
            case 7: printf("seventeen"); break;
            case 8: printf("eighteen");  break;
            case 9: printf("nineteen");  break;
        }
    else {
        switch (n / 10) {
            case 2: printf("twenty");  break;
            case 3: printf("thirty");  break;
            case 4: printf("forty");   break;
            case 5: printf("fifty");   break;
            case 6: printf("sixty");   break;
            case 7: printf("seventy"); break;
            case 8: printf("eighty");  break;
            case 9: printf("ninety");  break;
        }

        if (n / 10 != 0 && n % 10 != 0)
            printf("-");

        switch (n % 10) {
            case 1: printf("one");   break;
            case 2: printf("two");   break;
            case 3: printf("three"); break;
            case 4: printf("four");  break;
            case 5: printf("five");  break;
            case 6: printf("six");   break;
            case 7: printf("seven"); break;
            case 8: printf("eight"); break;
            case 9: printf("nine");  break;
        }
    }

    printf(".\n");
    return 0;
}
