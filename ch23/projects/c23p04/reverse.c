/* Prompts the user to enter a series of words and
   prints them in reverse order */

#include <stdio.h>
#include <string.h>

#define MAX_LEN   1000
#define MAX_WORDS 20

int main(void)
{
	char str[MAX_LEN], *words[MAX_WORDS];
	int num_words = 0;

	printf("Enter words (separated by single spaces): ");
	gets(str);

	while ((words[num_words] = strtok(num_words > 0 ? NULL : str, " ")) != NULL)
		num_words++;

	while (--num_words >= 0)
		printf("%s%c", words[num_words], num_words > 0 ? ' ' : '\n');

	return 0;
}
