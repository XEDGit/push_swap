/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:55:25 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:55:25 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*copy;
	char			*dest;

	copy = src;
	dest = dst;
	if (!dst && !src)
		return (0);
	if (dest < copy)
		while (len--)
			*dest++ = *copy++;
	else
	{
		copy += len - 1;
		dest += len - 1;
		while (len--)
			*dest-- = *copy--;
	}
	return (dst);
}
