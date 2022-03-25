/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:55:49 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:55:49 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}
