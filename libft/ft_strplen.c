/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:14 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:58:15 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strplen(const char *start, const char *end)
{
	int	cont;

	cont = 0;
	while (start != end && *start++)
		cont++;
	return (++cont);
}
