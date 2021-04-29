/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohrdie <emohrdie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 08:53:03 by emohrdie          #+#    #+#             */
/*   Updated: 2021/04/25 09:48:37 by emohrdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(grid[i][j])
{
	char c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = (grid[i][j] + '0');
			write(1, &c, 1);
			if (j < 3)
			{
				write(1, ' ', 1);
				j++;
			}
			else
			{
				write(1, '\n', 1);
				j++;
			}
		}
		i++;
	}
}
