/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:45:16 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/19 13:55:21 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

int ten_power(int exp)
{
	int i;
	int value;

	i = 1;
	value = 10;
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		value *= 10;
		i++;
	}
	return (value);
}

int ft_atoi(char *str)
{
	int size;
	int i;
	int integer;
	int multiply;

	multiply = 1;
	size = ft_strlen(str);
	i = 1;
	integer = 0;
	while (str[i - 1] == ' ')
		i++;
	if (str[i - 1] == '-')
	{
		multiply *= -1;
		i++;
	}
	else if (str[i - 1] == '+')
		i++;
	while (i <= size && str[i - 1] <= '9' && str[i - 1] >= '0')
	{
		integer += (str[i - 1] - '0') * ten_power(size - 1);
		i++;
	}
	return (integer * multiply);
}