/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:27 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:57:28 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	srcsize;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	while (dstsize - 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (srcsize);
}
