/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:30 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:58:31 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copystr(const char *first, const char *last, int reslen)
{
	char	*res;
	int		c;

	c = 0;
	res = malloc(reslen + 1);
	if (!res)
		return (0);
	while (first != last + 1)
	{
		res[c++] = *first++;
	}
	res[c] = 0;
	return (res);
}

const char	*check(const char *set, const char *s1, const char *end, int d)
{
	const char	*cur;

	cur = set;
	while (s1 != end)
	{
		while (*cur != *s1 && *cur)
			cur++;
		if (!*cur)
			return (s1);
		cur = set;
		s1 += d;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char		*first;
	const char		*last;
	const char		*end;
	char			*res;

	if (!s1 || !set)
		return (0);
	end = ft_strchr(s1, 0);
	first = check(set, s1, end, 1);
	if (first == end)
		end++;
	last = check(set, --end, first, -1);
	res = copystr(first, last, ft_strplen(first, last));
	if (!res)
		return (0);
	return (res);
}
