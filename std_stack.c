/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:29:15 by lmuzio            #+#    #+#             */
/*   Updated: 2022/05/25 19:36:53 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}

void	swap(t_list *stack)
{
	long	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;

	temp = ft_lstlast(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = 0;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
		last = temp;
	}
	last->next = NULL;
	temp->next = *stack;
	*stack = temp;
}
