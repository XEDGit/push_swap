/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:18 by lmuzio            #+#    #+#             */
/*   Updated: 2022/03/23 20:31:08 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;
	t_list	*todel;

	cur = *lst;
	todel = cur;
	while (cur)
	{
		cur = cur->next;
		free(todel);
		todel = cur;
	}
}
