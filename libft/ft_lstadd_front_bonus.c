/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:23 by lmuzio            #+#    #+#             */
/*   Updated: 2022/05/25 19:20:55 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	if (!lst)
	{
		*lst = new;
		return (0);
	}
	new->next = *lst;
	*lst = new;
	return (0);
}
