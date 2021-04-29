/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 08:51:20 by emohrdie          #+#    #+#             */
/*   Updated: 2021/04/25 08:34:31 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_row_column(int grid[4][4], int i, int j)
{
	int k;
	int n;

	n = 1;
	k = 0;
	while (k < j)
	{
		if (grid[i][k] == n)
		{
			n++;
			k = -1;
		}
		k++;
	}

	k = 0;
	while (k < i)
	{
		if (grid[k][j] == n)
		{
			n++;
			k = -1;
		}
		k++;
	}
	return (n);
}
