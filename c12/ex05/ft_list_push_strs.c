/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:34:01 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/28 11:52:31 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(char *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void	ft_list_push_front(t_list **begin_list, char *data)
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*newlist;

	i = 1;
	newlist = ft_create_elem(strs[0]);
	while (i < size)
	{
		ft_list_push_front(&newlist, strs[i]);
		i++;
	}
	return (newlist);
}
