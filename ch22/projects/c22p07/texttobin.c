#include <stdio.h>

int main(void)
{
	unsigned char ch;
	
	while (scanf("%hhX", &ch) != EOF)
		putchar(ch);
	
	return 0;
}
