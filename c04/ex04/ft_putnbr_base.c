/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:23:44 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/20 18:48:42 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_valid(char *base, int len)
{
	int i;
	int j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 33 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int		abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

int		is_negative(int nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

void	print_output(char *array, int negative, int i)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (negative)
		array[i] = '-';
	i = 31;
	while (array[i] == '\0')
		i--;
	while (i >= 0)
	{
		write(1, &array[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		i;
	char	reverse[32];
	int		negative;

	len = 0;
	i = 0;
	negative = is_negative(nbr);
	while (i < 32)
	{
		reverse[i] = '\0';
		i++;
	}
	while (base[len] != '\0')
		len++;
	if (!(check_valid(base, len)))
		return ;
	i = 0;
	while (nbr != 0)
	{
		reverse[i] = base[abs(nbr % len)];
		nbr /= len;
		i++;
	}
	print_output(reverse, negative, i);
}
