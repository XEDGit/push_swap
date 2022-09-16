/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:35 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:57:35 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*res;

	c = 0;
	if (!s || !f)
		return (0);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (*s)
	{
		res[c] = f(c, *s++);
		c++;
	}
	res[c] = 0;
	return (res);
}
