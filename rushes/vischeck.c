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