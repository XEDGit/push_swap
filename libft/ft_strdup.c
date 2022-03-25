/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:54:07 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:59:18 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*cur;

	dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	cur = dup;
	while (*s1)
		*cur++ = *s1++;
	*cur = 0;
	return (dup);
}
