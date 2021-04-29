/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzleV2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:41:06 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/22 06:30:34 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

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

void place_queens(int grid[DIM][DIM], int i);

int get_column(int grid[DIM][DIM], int i, int j)
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
			place_queens(grid, i+1);
			break;
		}
		else
			j++;
	}
	return (j);
}

void place_queens(int grid[DIM][DIM], int i)
{
    if (i >= 0 && i < DIM)
    {
        int j;

		j = DIM - 1;
		j = get_column(grid, i, j);
        if (j == DIM) // if no possible placement in current row, reiterate over previous row
            return place_queens(grid, i-1);
    }
    if (i == DIM) // if placements successful, increase counter and look for another possible solution
    {
        print_solution(grid);
        return place_queens(grid, i-1);
    }
    return ;
}

int fourqueens(void)
{
    int grid[DIM][DIM] = {0};
    place_queens(grid, 0);
    return 0;
}

int main(void)
{
    fourqueens();

}