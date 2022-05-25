/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algorythms.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:37:40 by lmuzio            #+#    #+#             */
/*   Updated: 2022/05/25 22:39:26 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *a, t_list *b, t_list *instructions)
{
	long	vals[3];
	int		err[2];

	vals[0] = a->content;
	vals[1] = a->next->content;
	vals[2] = a->next->next->content;
	err[1] = 0;
	if (vals[0] > vals[1] && vals[1] < vals[2] && vals[2] > vals[0])
		err[0] = ft_lstadd_back(&instructions, ft_lstnew(SA));
	else if (vals[0] > vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
	{
		err[0] = ft_lstadd_back(&instructions, ft_lstnew(SA));
		err[1] = ft_lstadd_back(&instructions, ft_lstnew(RRA));
	}
	else if (vals[0] > vals[1] && vals[1] < vals[2] && vals[2] < vals[0])
		err[0] = ft_lstadd_back(&instructions, ft_lstnew(RA));
	else if (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] > vals[0])
	{
		err[0] = ft_lstadd_back(&instructions, ft_lstnew(SA));
		err[1] = ft_lstadd_back(&instructions, ft_lstnew(RA));
	}
	else if (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
		err[0] = ft_lstadd_back(&instructions, ft_lstnew(RRA));
	if (err[0] || err[1])
		error_handler(a, b, instructions);
}

void	pre_sort_5(t_list **a, t_list **b, t_list **instructions)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content < 2)
		{
			if (ft_lstadd_back(instructions, ft_lstnew(PB)))
				error_handler(*a, *b, *instructions);
			push(a, b);
		}
		else
		{
			if (ft_lstadd_back(instructions, ft_lstnew(RA)))
				error_handler(*a, *b, *instructions);
			rotate(a);
		}
	}
}

void	sort_5(t_list **a, t_list **b, t_list *instructions)
{
	pre_sort_5(a, b, &instructions);
	sort_3(*a, *b, instructions);
	if ((*b)->content == 1)
	{
		if (!(!ft_lstadd_back(&instructions, ft_lstnew(PA)) && \
			!ft_lstadd_back(&instructions, ft_lstnew(PA))))
			error_handler(*a, *b, instructions);
	}
	else
	{
		if (!(!ft_lstadd_back(&instructions, ft_lstnew(PA)) && \
			!ft_lstadd_back(&instructions, ft_lstnew(PA)) && \
			!ft_lstadd_back(&instructions, ft_lstnew(SA))))
			error_handler(*a, *b, instructions);
	}
}
