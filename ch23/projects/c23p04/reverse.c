/* Prompts the user to enter a series of words and
   prints them in reverse order */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000], *words[20];
	int i, num_words = 0;

	printf("Enter words (separated by single spaces): ");
	gets(str);

	while ((words[num_words] = strtok(num_words > 0 ? NULL : str, " ")) != NULL)
		num_words++;

	for (i = num_words - 1; i >= 0; i--)
		printf("%s%c", words[i], i > 0 ? ' ' : '\n');

	return 0;
}
