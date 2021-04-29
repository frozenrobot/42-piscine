#include <stdio.h>

// void	ft_ft(int *nbr);

// int main(void)
// {
// 	int n;
// 	int *nbr = &n;

// 	ft_ft(nbr);
// 	printf("%i\n", *nbr);
// }

// void	ft_ultimate_ft(int *********nbr);

// int main(void)
// {
// 	int n = 0;
// 	int *nbr1 = &n;
// 	int **nbr2 = &nbr1;
// 	int ***nbr3 = &nbr2;
// 	int ****nbr4 = &nbr3;
// 	int *****nbr5 = &nbr4;
// 	int ******nbr6 = &nbr5;
// 	int *******nbr7 = &nbr6;
// 	int ********nbr8 = &nbr7;
// 	int *********nbr9 = &nbr8;

// 	ft_ultimate_ft(nbr9);
// 	printf("%i\n", *********nbr9);
// }

// void	ft_swap(int *a, int *b);

// int main(void)
// {
// 	int a0 = 4;
// 	int b0 = 2;
// 	int *a = &a0;
// 	int *b = &b0;

// 	ft_swap(a, b);
// 	printf("%i\n", *a);
// 	printf("%i\n", *b);
// }

// void	ft_div_mod(int a, int b, int *div, int *mod);

// int main(void)
// {
// 	int a = -13;
// 	int b = 5;
// 	int d = 2;
// 	int m = 2;
// 	int *div = &d;
// 	int *mod = &m;

// 	ft_div_mod(a, b, div, mod);
// 	printf("%i\n", a);
// 	printf("%i\n", b);
// 	printf("%i\n", *div);
// 	printf("%i\n", *mod);
// }

// void	ft_ultimate_div_mod(int *a, int *b);

// int main(void)
// {
// 	int a0 = 13;
// 	int b0 = 5;
// 	int *a = &a0;
// 	int *b = &b0;

// 	ft_ultimate_div_mod(a, b);
// 	printf("%i\n", *a);
// 	printf("%i\n", *b);
// }

// void	ft_putstr(char *str);

// int main(void)
// {
// 	char str[] = "Hello, world";
// 	ft_putstr(str);
// }

// int	ft_strlen(char *str);

// int main(void)
// {
// 	char str[] = "Hello, world";
// 	int length = ft_strlen(str);
// 	printf("%i\n", length);
// }

// void	ft_rev_int_tab(int *tab, int size);

// int main(void)
// {
// 	int tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	ft_rev_int_tab(tab, 9);
	
// 	int i = 0;
// 	while (i < 9)
// 	{
// 		printf("%i\n", tab[i]);
// 		i++;
// 	}
// }

void	ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int tab[5] = {5, 100, -3000, 4, -2};
	ft_sort_int_tab(tab, 5);
	
	int i = 0;
	while (i < 5)
	{
		printf("%i\n", tab[i]);
		i++;
	}
}