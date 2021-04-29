/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:22:19 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/27 21:46:25 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *output;
	int i;

	output = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		output[i] = f(tab[i]);
		i++;
	}
	return (output);
}
