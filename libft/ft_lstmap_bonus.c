/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:01 by lmuzio            #+#    #+#             */
/*   Updated: 2022/02/16 16:56:32 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, long (*f)(long))
{
	t_list	*res;
	t_list	*todel;
	t_list	*temp;

	res = 0;
	if (!f)
		return (0);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&res);
			return (0);
		}
		ft_lstadd_back(&res, temp);
		todel = lst;
		lst = lst->next;
	}
	return (res);
}
