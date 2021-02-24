/* Prompts the user to enter a series of words and prints them in reverse order */

#include <stdio.h>
#include <string.h>

#define MAX_LEN   1000
#define MAX_WORDS 20

int main(void)
{
	char str[MAX_LEN], *words[MAX_WORDS];
	int num_words = 0;

	printf("Enter words (separated by single spaces): ");
	fgets(str, MAX_LEN, stdin);

	for (; num_words < MAX_WORDS; num_words++) 
		if ((words[num_words] = strtok(num_words > 0 ? NULL : str, " \n")) == NULL)
			break;

	while (--num_words >= 0)
		printf(num_words > 0 ? "%s " : "%s", words[num_words]);
	printf("\n");

	return 0;
}
