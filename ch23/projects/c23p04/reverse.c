/* Prompts the user to enter a series of words and
   prints them in reverse order */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000], *words[20];
	int num_words = 0;

	printf("Enter words (separated by single spaces): ");
	gets(str);

	while ((words[num_words] = strtok(num_words > 0 ? NULL : str, " ")) != NULL)
		num_words++;

	while (--num_words >= 0)
		printf("%s%c", words[num_words], num_words > 0 ? ' ' : '\n');

	return 0;
}
