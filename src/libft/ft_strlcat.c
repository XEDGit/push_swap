/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:24 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:57:24 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int			destlen;
	int			size;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	size = dstsize;
	while (*d && size--)
		d++;
	destlen = d - dst;
	size = dstsize - destlen;
	if (!size)
		return (destlen + ft_strlen(src));
	while (*s && size)
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = 0;
	return (destlen + (s - src));
}
