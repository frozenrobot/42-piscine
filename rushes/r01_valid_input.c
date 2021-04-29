/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_valid_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrzej <mandrzej@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 08:29:20 by mandrzej          #+#    #+#             */
/*   Updated: 2021/04/24 13:42:52 by mandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void valid_input(int ac, char *av[])
{
	int x;

	x = 0;
	if (!(ac == 2));
	{
		return(0);	
	}
	while (!(av[x] == '\0'))
	{
		x++
	}
	if (!(x == 32))
	{
		return(0);
	}
	x = 0;
	while (x < 31)
	{
		if (!(0 < av[x] < 5);
		{
			return(0); 
		}
		if (!(av[++x] == ' '))
		{
			return(0);
		}
		x++;
	}
	return(1);
}