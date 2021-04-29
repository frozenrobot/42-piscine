/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:37:27 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/19 10:26:17 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	while (str[i] != '\0' && i <= (ft_strlen(str) - ft_strlen(to_find)))
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (j < ft_strlen(to_find))
			{
				if (str[i + j] == to_find[j])
					j++;
				else
					break ;
			}
			if (j == (ft_strlen(to_find)))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
