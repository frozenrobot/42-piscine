#include <stdio.h>


int main(void)
{
	int p;
	int q = 0;
	p = *&q;

	printf("%i\n", p);
}