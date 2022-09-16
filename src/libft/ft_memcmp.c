/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:55:29 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:55:29 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*f;
	const unsigned char	*s;

	f = s1;
	s = s2;
	while (n--)
		if (*f++ != *s++)
			return (*--f - *--s);
	return (0);
}
