/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sploot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:30 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/27 16:43:53 by kgulati          ###   ########.fr       */
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

int		is_sep(char c, char *sep)
{
	int j;

	j = 0;
	if (ft_strlen(sep) == 0)
		return (0);
	while (j < ft_strlen(sep))
	{
		if (c == sep[j])
			return (1);
		j++;
	}
	return (0);
}

int		count_words(char *str, char *sep)
{
	int i;
	int count;
	int sep_len;

	i = 0;
	count = 0;
	sep_len = ft_strlen(sep);
	if (sep_len == 0)
		return (1);
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		if (!is_sep(str[i], sep))
			count++;
		while (!is_sep(str[i], sep) && str[i] != '\0')
			i++;
		while (is_sep(str[i], sep) && str[i] != '\0')
			i++;
	}
	return (count);
}

char	*ft_strcpy(char *str, int i, char *tab, char *sep)
{
	int size;
	int k;

	size = 0;
	while (is_sep(str[i + size], sep) == 0 && str[i + size] != '\0')
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
	tab = malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count && i < len)
	{
		while (is_sep(str[i], charset) && i < len)
			i++;
		tab[j] = ft_strcpy(str, i, tab[j], charset);
		i += ft_strlen(tab[j]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
