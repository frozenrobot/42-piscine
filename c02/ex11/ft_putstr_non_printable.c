/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:25:38 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/19 19:21:30 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr_hex(int nbr)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar(base[nbr / 16]);
	ft_putchar(base[nbr % 16]);
	return ;
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			putnbr_hex(str[i]);
		}
		i++;
	}
}
