/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:50:03 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:50:42 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*temp;

	if (begin_list1 && *begin_list1)
	{
		while (begin_list1 && *begin_list1)
		{
			temp = *begin_list1;
			while (temp->next)
				temp = temp->next;
			temp->next = begin_list2;
		}
	}
	else
		*begin_list1 = begin_list2;
}
