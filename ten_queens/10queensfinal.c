/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10queensfinal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 05:32:31 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/22 07:13:51 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>

int		check_invalid(int grid[10][10], int i, int j, int counter)
{
	while (counter <= i)
	{
		if (grid[counter][j + 1] == 1)
			return (1);
		counter++;
	}
	counter = 1;
	while (i >= 0 && i < 10 && j >= 0 && j < 10)
	{
		if (grid[i][j] == 1)
			return (1);
		i--;
		j--;
		counter++;
	}
	i = i + counter - 1;
	j = j + counter + 1;
	while (i >= 0 && i < 10 && j >= 0 && j < 10)
	{
		if (grid[i][j] == 1)
			return (1);
		i--;
		j++;
	}
	return (0);
}

void	print_solution(int grid[10][10])
{
	int		i;
	int		j;
	char	p;

	i = 0;
	j = 0;
	p = 0;
	while (j < 10)
	{
		while (i < 10)
		{
			if (grid[i][j] == 1)
			{
				p = i + '0';
				write(1, &p, 1);
			}
			i++;
		}
		j++;
		i = 0;
	}
	write(1, &("\n"), 1);
}

int		place_queens(int grid[10][10], int i, int *solutions);

int		get_column(int grid[10][10], int i, int j, int *solutions)
{
	while (j >= 0)
	{
		if (grid[i][j] == 1)
		{
			grid[i][j] = 0;
			break ;
		}
		j--;
	}
	if (j == -1)
		j = 0;
	else
		j++;
	while (j < 10)
	{
		if (!check_invalid(grid, i - 1, j - 1, 0))
		{
			grid[i][j] = 1;
			return (place_queens(grid, i + 1, solutions));
			break ;
		}
		else
			j++;
	}
	return (j);
}

int		place_queens(int grid[10][10], int i, int *solutions)
{
	int j;

	if (i >= 0 && i < 10)
	{
		j = 10 - 1;
		j = get_column(grid, i, j, solutions);
		if (j == 10)
			return (place_queens(grid, i - 1, solutions));
	}
	if (i == 10)
	{
		(*solutions)++;
		print_solution(grid);
		return (place_queens(grid, i - 1, solutions));
	}
	return (*solutions);
}

int		ft_ten_queens_puzzle(void)
{
	int grid[10][10];
	int solutions;
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	solutions = 0;
	solutions = place_queens(grid, 0, &solutions);
	return (solutions);
}
