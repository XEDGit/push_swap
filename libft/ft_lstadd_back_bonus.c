/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:56:26 by lmuzio            #+#    #+#             */
/*   Updated: 2022/05/25 19:24:26 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	return (0);
}
