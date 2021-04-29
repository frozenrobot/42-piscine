/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:46:40 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/18 18:00:58 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_row(int j, int x)
{
	while (j <= x)
	{
		if (j == 1)
			ft_putchar('/');
		else if (j == x)
			ft_putchar('\\');
		else
			ft_putchar('*');
		j++;
	}
}

void	last_row(int j, int x)
{
	while (j <= x)
	{
		if (j == 1)
			ft_putchar('\\');
		else if (j == x)
			ft_putchar('/');
		else
			ft_putchar('*');
		j++;
	}
}

void	middle_row(int j, int x)
{
	while (j <= x)
	{
		if (j == 1 || j == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		j++;
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		if (i == 1)
			first_row(j, x);
		else if (i == y)
			last_row(j, x);
		else
			middle_row(j, x);
		ft_putchar('\n');
		i++;
	}
}
