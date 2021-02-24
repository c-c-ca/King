/* Capitalizes the first letter in each word */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool in_word = false;
	int ch;

	while ((ch = getchar()) != EOF)
		if ((isspace(ch) != 0) == in_word) {
			in_word = !in_word;
			putchar(toupper(ch));
		} else
			putchar(ch);

	return 0;
}
