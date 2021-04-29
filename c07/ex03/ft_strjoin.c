/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:14 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/23 09:19:26 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		find_length(int size, char **strs, char *sep)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += (size - 1) * ft_strlen(sep);
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < ft_strlen(src))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*zero(char *big_str, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		big_str[i] = '\0';
		i++;
	}
	return (big_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*big_str;
	int		length;

	i = 0;
	if (size <= 0)
	{
		big_str = (char *)malloc(sizeof(char));
		*big_str = '\0';
		return (big_str);
	}
	length = find_length(size, strs, sep);
	big_str = malloc(length * sizeof(char));
	if (big_str == NULL)
		return (NULL);
	big_str = zero(big_str, length);
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(big_str, strs[i]);
		ft_strcat(big_str, sep);
		i++;
	}
	ft_strcat(big_str, strs[i]);
	return (big_str);
}
