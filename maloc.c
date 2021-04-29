#include <stdlib.h>
# include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char **return_mat(void)
{
	char **mat = (char **)malloc(sizeof(char **));
	int i = 0;
	int j = 0;
	while (i < 4)
	{
		mat[i] = (char *)malloc(sizeof(char *));
	}
	while (i < 4)
	{
		while(j < 4)
		{
			mat[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	return(mat);
}

int main(void)
{
	int i;
	int j;
	char **mat = return_mat();

	i = 0;
	j = 0;
	while (i < 4)
	{
		while(j < 4)
		{
			ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}