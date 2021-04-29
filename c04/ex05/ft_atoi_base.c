/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:28:37 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/20 18:29:36 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_valid(char *base, int len_base)
{
	int i;
	int j;

	if (len_base < 2)
		return (0);
	i = 0;
	while (i < len_base - 1)
	{
		j = i + 1;
		while (j < len_base)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len_base)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 33 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	check_size_ahead(char *str, int i, char *base, int len_base)
{
	int j;
	int b;
	int found;

	j = 0;
	while (str[i + j])
	{
		b = 0;
		found = 0;
		while (b < len_base)
		{
			if (str[i + j] == base[b])
			{
				j++;
				found = 1;
			}
			b++;
		}
		if (found != 1)
			return (j);
	}
	return (j);
}

int	power(int n, int exponent)
{
	if (exponent < 0)
		return (0);
	else if (exponent == 0)
		return (1);
	else
		return (n * power(n, exponent - 1));
}

int	convert_to_int(char *str, int i, int size, char *base)
{
	int result;
	int j;
	int base_index;
	int base_count;
	int len_base;

	len_base = 0;
	while (base[len_base] != '\0')
		len_base++;
	result = 0;
	j = 0;
	while (j <= size)
	{
		base_count = 0;
		while (base_count < len_base)
		{
			if (str[i + j] == base[base_count])
				base_index = base_count;
			base_count++;
		}
		result += (base_index * power(len_base, (size - 1 - j)));
		j++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int multiply;
	int size;
	int len_base;

	len_base = 0;
	while (base[len_base] != '\0')
		len_base++;
	if (!(check_valid(base, len_base)))
		return (0);
	i = 0;
	multiply = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multiply *= -1;
		i++;
	}
	size = check_size_ahead(str, i, base, len_base);
	return (multiply * convert_to_int(str, i, size, base));
}
