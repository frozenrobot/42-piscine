#include<stdio.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_negative(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	nb = check_negative(nb);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

int main(void)
{
    int input[5] = {1, 2, 3, 4, 5};
	ft_foreach(input, 5, &ft_putnbr);
    return 0;
}





#include<stdio.h>

int ft_double(int n)
{
	n = 2 * n;
	return (n);
}

int main(void)
{
    int input[5] = {1, 2, 3, 4, 5};
	int *output = ft_map(input, 5, &ft_double);
	for (int i = 0; i < 5; i++)
		printf("%i", output[i]);
    return 0;
}