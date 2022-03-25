/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:54:14 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:54:23 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(const char *s, char c)
{
	int	cont;

	cont = 0;
	if (!*s)
		return (1);
	if (*s != c)
		cont++;
	while (*s)
	{
		if (*s++ == c)
		{	
			cont++;
			while (*s == c && *s)
				s++;
		}
	}
	if (*(s - 1) == c)
		cont--;
	return (cont);
}

char	**free2d(char **tofree, int len)
{
	while (len--)
		free(tofree[len]);
	free(tofree);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		cont;
	int		resc;

	resc = 0;
	if (!s)
		return (0);
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		cont = ft_strclen(s, c);
		if (!cont)
			continue ;
		res[resc] = malloc(cont + 1);
		if (!res[resc])
			return (free2d(res, resc + 1));
		ft_strlcpy(res[resc++], s, cont + 1);
		s += cont;
	}
	res[resc] = 0;
	return (res);
}
