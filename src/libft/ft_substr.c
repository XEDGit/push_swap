/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:35 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:58:35 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		c;
	char				*res;

	if (!s)
		return (0);
	c = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (0);
	if (start >= c)
		len = 0;
	c = 0;
	while (len--)
		res[c++] = s[start++];
	res[c] = 0;
	return (res);
}
