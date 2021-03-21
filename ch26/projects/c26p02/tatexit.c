#include <stdio.h>
#include <stdlib.h>

void f(void);
void g(void);

int main(void)
{
	atexit(g);
	atexit(f);
	return 0;
}

void f(void)
{
	printf("That's all, ");
}

void g(void)
{
	printf("folks!\n");
}
