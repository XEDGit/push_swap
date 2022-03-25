/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:53 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:56:53 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	declen(long n)
{
	size_t		c;

	c = 0;
	if (!n)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		c++;
	}
	return (c);
}

void	ft_revitoa(long n, char *res, int min)
{
	if (!n)
		*res++ = '0';
	while (n >= 1)
	{
		*res++ = (n % 10) + '0';
		n /= 10;
	}
	if (min)
		*res++ = '-';
	*res = 0;
}

char	*ft_itoa(int n)
{
	char		*res;
	long		nn;
	int			c;
	int			min;

	c = 0;
	nn = n;
	min = 0;
	if (nn < 0)
		min++;
	if (min)
		nn *= -1;
	c += declen(nn);
	res = malloc(min + c + 1);
	if (!res)
		return (0);
	ft_revitoa(nn, res, min);
	ft_strrev(res);
	return (res);
}
