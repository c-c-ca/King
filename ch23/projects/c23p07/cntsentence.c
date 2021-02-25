#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TERMINALS ".?!"

int main(void)
{
	bool terminal_seen = false;
	int ch, count = 0;

	while ((ch = getchar()) != EOF) {
		if (terminal_seen && isspace(ch))
			count++;
		terminal_seen = strchr(TERMINALS, ch) != NULL;
	}

	printf("There are %d sentences\n", count);

	return 0;
}
