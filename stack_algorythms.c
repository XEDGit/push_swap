/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorythms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:46:20 by lmuzio            #+#    #+#             */
/*   Updated: 2022/05/25 22:39:31 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*radix_loop(t_list *a, t_list *b, int bitshift, t_list *instructions)
{
	int	list_size;

	list_size = ft_lstsize(a);
	while (list_size--)
	{
		if (!((a->content >> bitshift) & 1))
		{
			push(&a, &b);
			if (ft_lstadd_back(&instructions, ft_lstnew(PB)))
				error_handler(a, b, instructions);
		}
		else
		{
			rotate(&a);
			if (ft_lstadd_back(&instructions, ft_lstnew(RA)))
				error_handler(a, b, instructions);
		}
	}
	while (b)
	{
		push(&b, &a);
		if (ft_lstadd_back(&instructions, ft_lstnew(PA)))
			error_handler(a, b, instructions);
	}
	return (a);
}

void	radix_sort(t_list **a, t_list **b, int max, t_list *instructions)
{
	int	bitshift;

	bitshift = 0;
	while (bitshift != max)
	{
		*a = radix_loop(*a, *b, bitshift, instructions);
		if (!check_sort(*a))
			break ;
		bitshift++;
	}
	return ;
}

void	sort(t_list **a, t_list **b, t_list *instructions)
{
	int	max_bit;

	if (!check_sort(*a))
		return ;
	max_bit = find_max_bit(*a);
	if (ft_lstsize(*a) == 3)
		sort_3(*a, 0, instructions);
	else if (ft_lstsize(*a) <= 5)
		sort_5(a, b, instructions);
	else
		radix_sort(a, b, max_bit, instructions);
	return ;
}
