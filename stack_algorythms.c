/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorythms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:46:20 by lmuzio            #+#    #+#             */
/*   Updated: 2022/03/24 19:20:31 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *a, t_list *instructions)
{
	long	vals[3];

	vals[0] = a->content;
	vals[1] = a->next->content;
	vals[2] = a->next->next->content;
	if (vals[0] > vals[1] && vals[1] < vals[2] && vals[2] > vals[0])
		ft_lstadd_back(&instructions, ft_lstnew(SA));
	else if (vals[0] > vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
	{
		ft_lstadd_back(&instructions, ft_lstnew(SA));
		ft_lstadd_back(&instructions, ft_lstnew(RRA));
	}
	else if (vals[0] > vals[1] && vals[1] < vals[2] && vals[2] < vals[0])
		ft_lstadd_back(&instructions, ft_lstnew(RA));
	else if (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] > vals[0])
	{
		ft_lstadd_back(&instructions, ft_lstnew(SA));
		ft_lstadd_back(&instructions, ft_lstnew(RA));
	}
	else if (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
		ft_lstadd_back(&instructions, ft_lstnew(RRA));
}

void	sort_5(t_list *a, t_list *b, t_list *instructions)
{
	while (ft_lstsize(a) > 3)
	{
		if (a->content < 2)
		{	
			ft_lstadd_back(&instructions, ft_lstnew(PB));
			push(&a, &b);
		}
		else
		{	
			rotate(&a);
			ft_lstadd_back(&instructions, ft_lstnew(RA));
		}
	}
	sort_3(a, instructions);
	if (b->content == 1)
	{	
		ft_lstadd_back(&instructions, ft_lstnew(PA));
		ft_lstadd_back(&instructions, ft_lstnew(PA));
	}
	else
	{
		ft_lstadd_back(&instructions, ft_lstnew(PA));
		ft_lstadd_back(&instructions, ft_lstnew(PA));
		ft_lstadd_back(&instructions, ft_lstnew(SA));
	}
}

t_list	*radix_loop(t_list *a, t_list *b, int bitshift, t_list *instructions)
{
	int	list_size;

	list_size = ft_lstsize(a);
	while (list_size--)
	{
		if (!((a->content >> bitshift) & 1))
		{
			push(&a, &b);
			ft_lstadd_back(&instructions, ft_lstnew(PB));
		}
		else
		{
			rotate(&a);
			ft_lstadd_back(&instructions, ft_lstnew(RA));
		}
	}
	while (b)
	{
		push(&b, &a);
		ft_lstadd_back(&instructions, ft_lstnew(PA));
	}
	return (a);
}

void	radix_sort(t_list *a, t_list *b, int max, t_list *instructions)
{
	int	counter;

	counter = 0;
	while (counter != max)
	{
		a = radix_loop(a, b, counter, instructions);
		if (!check_sort(a))
			break ;
		counter++;
	}
	return ;
}

void	sort(t_list *a, t_list *b, t_list *instructions)
{
	int	max_bit;

	if (!check_sort(a))
		return ;
	max_bit = find_max_bit(a);
	if (ft_lstsize(a) == 3)
		sort_3(a, instructions);
	else if (ft_lstsize(a) <= 5)
		sort_5(a, b, instructions);
	else
		radix_sort(a, b, max_bit, instructions);
	return ;
}
