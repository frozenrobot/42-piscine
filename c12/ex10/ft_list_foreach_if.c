/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:42:32 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:55:57 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)())
{
	t_list	*temp;

	temp = begin_list;
	if (temp)
	{
		while (temp)
		{
			if ((*cmp)((temp)->data, data_ref) == 0)
				(*f)((temp)->data);
			temp = (temp)->next;
		}
	}
}
