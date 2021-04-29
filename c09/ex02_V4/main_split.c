#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(void)
{
	char str[] = "PwHz7\nHPAK\nLDvxbqWJ6oXnva  peP7Bne";
	char charset[] = "Q\n";
	char **split = ft_split(str, charset);
	int i = 0;
	while (split[i] != '\0')
	{
		printf("%s\n", split[i]);
		i++;
	}
}
