/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:27:40 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/27 13:43:02 by kgulati          ###   ########.fr       */
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

int		is_sep(char *str, int i, char *sep)
{
	int j;

	j = 0;
	if (ft_strlen(sep) == 0)
		return (0);
	while (j < ft_strlen(sep) && str[i + j] != '\0')
	{
		if (str[i + j] == sep[j])
			j++;
		else
			break ;
	}
	if (j == (ft_strlen(sep)))
		return (1);
	return (0);
}

int		count_words(char *str, char *sep)
{
	int i;
	int sep_count;
	int sep_len;

	i = 0;
	sep_count = 0;
	sep_len = ft_strlen(sep);
	if (sep_len == 0)
		return (1);
	while (str[i] != '\0')
	{
		while (!is_sep(str, i, sep) && str[i] != '\0')
			i++;
		if (is_sep(str, i, sep) && str[i] != '\0')
		{
			sep_count++;
			while (is_sep(str, i, sep) && str[i] != '\0')
				i += sep_len;
		}
	}
	if (sep_count != 0)
		return (sep_count - 1);
	return (sep_count);
}

char	*ft_strcpy(char *str, int i, char *tab, char *sep)
{
	int size;
	int k;

	size = 0;
	while (is_sep(str, i + size, sep) == 0 && str[i + size] != '\0')
	{
		size++;
	}
	tab = malloc((size + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	k = 0;
	while (k < size && str[i + k] != '\0')
	{
		tab[k] = str[i + k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**tab;
	int		i;
	int		j;
	int		len;

	count = count_words(str, charset);
	len = ft_strlen(str);
	if (!(tab = malloc((count + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (!is_sep(str, i, charset) && str[i] != '\0')
		i++;
	while (j < count && i < len)
	{
		while (is_sep(str, i, charset) && i < len)
			i += ft_strlen(charset);
		tab[j] = ft_strcpy(str, i, tab[j], charset);
		while (is_sep(str, i, charset) == 0 && str[i] != '\0')
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
