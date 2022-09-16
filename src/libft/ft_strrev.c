/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:22 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:58:25 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_strrev(char *s)
{
	unsigned char	temp;
	size_t			half;
	size_t			len;
	size_t			c;

	len = ft_strlen(s);
	half = len-- / 2;
	c = 0;
	while (c != half)
	{
		temp = s[len];
		s[len--] = s[c];
		s[c++] = temp;
	}
}
