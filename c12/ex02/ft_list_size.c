/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:15:09 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:57:23 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = begin_list;
	if (temp)
		i = 1;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
