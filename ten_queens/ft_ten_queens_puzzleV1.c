/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:25:47 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/21 15:39:42 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#define DIM 8

void ftpc(char c)
{
    write(1, &c, 1);
}

// int check_column(int grid[DIM][DIM], int i, int j)
// {
//     int k = 0;
//     while (k < i)
//     {
//         if (grid[k][j] == 1)
//             return 1;
//         k++;
//     }
//     return 0;
// }

// int check_left_diag(int grid[DIM][DIM], int i, int j)
// {
//     i--;
//     j--;
//     while (i >= 0 && i < DIM && j >= 0 && j < DIM)
//     {
//         if (grid[i][j] == 1)
//             return 1;
//         i--;
//         j--;
//     }
//     return 0;
// }

int check_valid(int grid[DIM][DIM], int i, int j, int counter)
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
    int i = 0;
    int j = 0;
    while (j < DIM)
    {
        while (i < DIM)
        {
            if (grid[i][j] == 1)
            {
                ftpc(i+'1');
            }
            i++;
        }
        j++;
        i = 0;
    }
    ftpc('\n');
}

void place_queens_row(int grid[DIM][DIM], int i);

int place_queens_column(int grid[DIM][DIM], int i)
{
	int j;

	j = DIM - 1;
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
		if (!check_valid(grid, i - 1, j - 1, 0))
		{
			grid[i][j] = 1;
			place_queens_row(grid, i+1);
		}
		else
			j++;
	}
	return (j);
}

void place_queens_row(int grid[DIM][DIM], int i)
{
	int j;

    if (i >= 0 && i < DIM)
    {
		j = place_queens_column(grid, i);
        if (j == DIM) // if no possible placement in current row, reiterate over previous row
            return place_queens_row(grid, i-1);
    }
    if (i == DIM) // if placements successful, increase counter and look for another possible solution
    {
        print_solution(grid);
        return place_queens_row(grid, i-1);
    }
    return;
}

int fourqueens(void)
{
    int grid[DIM][DIM] = {0};
    place_queens_row(grid, 0);
    return 0;
}

int main(void)
{
    fourqueens();
}