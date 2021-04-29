/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 05:48:00 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/22 06:30:44 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>

#define DIM 10

int check_invalid(int grid[DIM][DIM], int i, int j, int counter)
{
	while (counter <= i)
    {
        if (grid[counter][j + 1] == 1)
            return 1;
        counter++;
    }
	counter = 1;
    while (i >= 0 && i < DIM && j >= 0 && j < DIM)
    {
        if (grid[i][j] == 1)
            return 1;
        i--;
        j--;
		counter++;
    }
	i = i + counter - 1;
	j = j + counter + 1;
	while (i >= 0 && i < DIM && j >= 0 && j < DIM)
    {
        if (grid[i][j] == 1)
            return 1;
        i--;
        j++;
    }
    return 0;
}

void print_solution(int grid[DIM][DIM], int i, int j, char *sol_grid[724])
{
	int index;

	index = 0;
	while (index <= 723)
	{
		if (sol_grid[index][0] == '0' && sol_grid[index][1] == '0')
			break ;
		index++;
	}
    while (j < DIM)
    {
        while (i < DIM)
        {
            if (grid[i][j] == 1)
            {
				sol_grid[index][j] = i + '0';
            }
            i++;
        }
        j++;
        i = 0;
    }
}

int place_queens(int grid[DIM][DIM], int i, int *solutions, char *sol_grid[724]);

int get_column(int grid[DIM][DIM], int i, int *solutions, char *sol_grid[724])
{
	int j;

	j = 0;
	while (j >= 0)
	{
		if (grid[i][j] == 1)
		{
			grid[i][j] = 0;
			break;
		}
		j--;
	}
	j++;
	while (j < DIM)
	{
		if (!check_invalid(grid, i - 1, j - 1, 0))
		{
			grid[i][j] = 1;
			return place_queens(grid, i+1, solutions, sol_grid);
			break;
		}
		else
			j++;
	}
	return (j);
}

int place_queens(int grid[DIM][DIM], int i, int *solutions, char *sol_grid[724])
{
    if (i >= 0 && i < DIM)
    {
		int j;

		j = get_column(grid, i, solutions, sol_grid);
        if (j == DIM) // if no possible placement in current row, reiterate over previous row
            return place_queens(grid, i-1, solutions, sol_grid);
    }
    if (i == DIM) // if placements successful, increase counter and look for another possible solution
    {
		(*solutions)++;
        print_solution(grid, 0, 0, sol_grid);
        return place_queens(grid, i-1, solutions, sol_grid);
    }
    return (*solutions);
}

int fourqueens(void)
{
    int grid[DIM][DIM] = {0};
	char *sol_grid[724] = {"0000000000"};
	int solutions = 0;
	solutions = place_queens(grid, 0, &solutions, sol_grid);
	int i = 0;
	int j = 0;
	while (i < 724)
	{
		while (j < 10)
		{
			write(1, &sol_grid[i][j], 1);
			j++;
		}
		i++;
	}
    return (solutions);
}

int main(void)
{
    printf("%i\n", fourqueens());
}