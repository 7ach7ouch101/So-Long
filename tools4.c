/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:01:11 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/26 22:01:18 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	negatif(int n)
{
	write (1, "-", 1);
	n = n * (-1);
	return (n);
}

int	countlen(int a, int count)
{
	while (a)
	{
		a = a / 10;
		count = count * 10;
	}
	return (count);
}

void	zero(int n)
{
	if (n == 0)
		write(1, "0", 1);
}

void	ft_putnbr(int n)
{
	unsigned int	count;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	if (n < 0)
		n = negatif(n);
	if (n == 0)
	{
		zero(n);
		return ;
	}
	c = n;
	a = c;
	b = c;
	count = 1;
	a = a / 10;
	count = countlen(a, count);
	while (count)
	{
		c = (c / count) + 48;
		write(1, &c, 1);
		c = b % count;
		count = count / 10;
	}
}
