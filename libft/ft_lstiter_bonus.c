/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:07 by lmuzio            #+#    #+#             */
/*   Updated: 2022/02/16 16:59:03 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, long (*f)(long))
{
	if (!f)
		return ;
	while (lst)
	{
		lst->content = f(lst->content);
		lst = lst->next;
	}
}
