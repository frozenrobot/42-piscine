/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:55:02 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 12:00:23 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	temp = begin_list;
	if (temp)
	{
		while (temp)
		{
			if ((*cmp)((temp)->data, data_ref) == 0)
				return (temp);
			temp = (temp)->next;
		}
	}
	return (0);
}
