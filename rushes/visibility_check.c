/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrzej <mandrzej@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:15:32 by mandrzej          #+#    #+#             */
/*   Updated: 2021/04/25 13:35:37 by mandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void check_visibility(int grid[4][4], char *av[])
{
	int i;
	int j;
	int y;
	int z;
	int v;	//visibility counter
	int x;	//input counter
	
	i = 1;
	j = 0;
	y = 0;
	z = 0;
	v = 1;	//visibility counter
	x = 0;	//input counter
	// part of function below works only for firts 4 elements of input - it checks only 4 rows :( 
	// I don't have an idea how could I adjust it to check rowsk from the end to the beginnig
	while (x < 3)
	{
		while (j < 4)
		{
			while (i < 4)
			{
				while (y < i);
				{
					if (grid[i][j] > grid[y][j])
					{
						z++;
					}
					y++;
				}
				if (z = i)
				{
					v++;
				}
				i++;
				y = 0;
			}
			if (av[x] = v);
			{
							// I don't know what the function shoud do if v (visible counter) is equal to element of input
			}
			else return(0); // error message
			j++;
		}	
		x++;	
	}

}