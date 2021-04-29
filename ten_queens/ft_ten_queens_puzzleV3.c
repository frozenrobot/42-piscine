/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzleV3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:57:35 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/22 06:30:38 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>

#define DIM 8

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

void print_solution(int grid[DIM][DIM])
{
    int i;
	int j;
	char p;
	
	i = 0;
    j = 0;
	p = 0;
    while (j < DIM)
    {
        while (i < DIM)
        {
            if (grid[i][j] == 1)
            {
				p = i + '1';
                write(1, &p, 1);
            }
            i++;
        }
        j++;
        i = 0;
    }
    write(1, &("\n"), 1);
}

int place_queens(int grid[DIM][DIM], int i, int *solutions);

int get_column(int grid[DIM][DIM], int i, int j, int *solutions)
{
	while (j >= 0)
	{
		if (grid[i][j] == 1)
		{
			grid[i][j] = 0;
			break;
		}
		j--;
	}
	if (j == -1)
		j = 0;
	else
		j++;
	while (j < DIM)
	{
		if (!check_invalid(grid, i - 1, j - 1, 0))
		{
			grid[i][j] = 1;
			return place_queens(grid, i+1, solutions);
			break;
		}
		else
			j++;
	}
	return (j);
}

int place_queens(int grid[DIM][DIM], int i, int *solutions)
{
    if (i >= 0 && i < DIM)
    {
        int j;

		j = DIM - 1;
		j = get_column(grid, i, j, solutions);
        if (j == DIM) // if no possible placement in current row, reiterate over previous row
            return place_queens(grid, i-1, solutions);
    }
    if (i == DIM) // if placements successful, increase counter and look for another possible solution
    {
		(*solutions)++;
        print_solution(grid);
        return place_queens(grid, i-1, solutions);
    }
    return (*solutions);
}

int fourqueens(void)
{
    int grid[DIM][DIM] = {0};
	int solutions = 0;
	solutions = place_queens(grid, 0, &solutions);
    return (solutions);
}

int main(void)
{
    printf("%i\n", fourqueens());
}