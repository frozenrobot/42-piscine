/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:06:13 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:57:38 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*temp;

	i = 0;
	temp = begin_list;
	if (temp)
	{
		while ((temp)->next)
		{
			if (i == nbr)
				return (temp);
			temp = (temp)->next;
			i++;
		}
		if (i == nbr)
			return (temp);
		return (0);
	}
	else
		return (0);
}
