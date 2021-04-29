/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:33:12 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:52:48 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*now;
	t_list	*before;

	before = 0;
	now = *begin_list;
	while (now)
	{
		if ((*cmp)((*cmp)(now->data, data_ref)) == 0)
		{
			if (before == 0)
				*begin_list = now->next;
			else
				before->next = now->next;
			(*free_fct)(now->data);
			free(now);
		}
		before = now;
		now = now->next;
	}
}
