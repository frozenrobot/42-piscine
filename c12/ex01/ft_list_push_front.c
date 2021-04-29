/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 06:01:23 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:56:19 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;

	if (*begin_list)
	{
		temp = ft_create_elem(data);
		temp->next = (*begin_list);
		(*begin_list) = temp;
	}
	else
		*begin_list = ft_create_elem(data);
}
