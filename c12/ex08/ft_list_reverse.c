/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:15:57 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:54:11 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *now;
	t_list *before;
	t_list *temp;

	now = (*begin_list);
	before = 0;
	while (now)
	{
		temp = now->next;
		now->next = before;
		before = now;
		now = temp;
	}
	(*begin_list) = now;
}
