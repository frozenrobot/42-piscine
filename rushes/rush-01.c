
int vischeck_column(int *grid[4][4], int *tab[16], int i, int j) //we'll pass i = 0 and j = 0 as parameters to the function
{
	int n;

	n = 1;
	while (j < 4)
	{
		while (i < 3)
		{
			if (grid[i][j] < grid[i + 1][j])
				n++;
			i++;
		}
		if (n != tab[j])
			return (0);
		n = 1;
		while (i > 0)
		{
			if (grid[i][j] < grid[i - 1][j])
				n++;
			i--;
		}
		if (n != tab[4 + j])
			return (0);
		i++;
	}
	return (1);
}

int vischeck_row(int *grid[4][4], int *tab[16], int i, int j)
{
	int n;

	n = 1;
	while (i < 4)
	{
		while (j < 3)
		{
			if (grid[i][j] < grid[i][j + 1])
				n++;
			j++;
		}
		if (n != tab[8 + i])
			return (0);
		n = 1;
		while (j > 0)
		{
			if (grid[i][j] < grid[i][j - 1])
				n++;
			j--;
		}
		if (n != tab[12 + i])
			return (0);
		j++;
	}
	return (1);
}

int valid_input(int ac, char *av[])
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

int check_row_column(int grid[4][4], int i, int j) //scans the row i and column j, returns smallest possible valid number from 1-4 (if none valid, returns 0)
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

int get_column(int grid[4][4], int i)
{
	int j;

	j = 3;
	while (j >= 0)	//this loop scans the row i from the right, and sets j equal to the column index of the last occupied square (or 0 if the row is empty)
	{
		if (grid[i][j] != 0)
		{
			grid[i][j] = 0;
			break ;
		}
		j--;
	}
	j++;
	while (j < 4) //this loop sets the square at the coordinate [i][j] (i was input, j found from the previous loop) to the number returned from the check_row_column function)
	{
		if (check_row_column(grid, i, j) != 0)
		{
			grid[i][j] = check_row_column(grid, i, j);
			return (fill_numbers(grid, i + 1));
			break ;
		}
		else
			j++;
	}
	return (j);
}

int fill_numbers(int grid[4][4], int i)
{
	int j;

	j = get_column(grid, i);
}

int *input_str_to_array(char *av[])
{
	int x;
	int i;
	int *tab[16];

	x = 0;
	i = 0;
	while (x < 31)
	{
		tab[i] = (av[1][x] - '0');
		i++;
		x += 2;
	}
	return (tab);
}

int main(int argc, char *argv[])
{
	int *input_tab[16];
	int grid[4][4];   //declares grid as a 2D array
	int i;
	int j;

	if (!valid_input(argc, argv))  //validates input
	{
		write(1, "Error\n", 6);
		return (1);
	}
	input_tab = input_str_to_tab(argv);
	i = 0;
	while (i < 4)		//sets every element of the grid to 0
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	fill_numbers(grid, 0); //solution finding starts here
	print_solution(grid); //once a solution is found, this function prints it

	return (0);
}

