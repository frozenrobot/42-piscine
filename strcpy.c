#include<stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	char *a;

	a = dest;
	while(*src)
	{
		(*dest) = (*src);
		src++;
		dest++;
	}
	*dest = '\0';
	return (a);
}

int main(void)
{
	char dest[] = "hello";
	char src[] = "apple";
	printf("%s\n", ft_strcpy(dest, src));
}
