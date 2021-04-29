/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 05:35:46 by kgulati           #+#    #+#             */
/*   Updated: 2021/04/22 07:18:42 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int output;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	i = 1;
	output = 1;
	while (i <= nb)
	{
		output *= i;
		i++;
	}
	return (output);
}
