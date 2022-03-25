/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:43:45 by lmuzio            #+#    #+#             */
/*   Updated: 2022/03/24 16:06:59 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bit(t_list *stack)
{
	long	max;
	int		max_bit;

	max = 0;
	max_bit = 0;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit + 1);
}

int	check_sort(t_list *stack)
{
	long	temp;

	temp = -1;
	while (stack)
	{
		if (temp > stack->content)
			return (1);
		temp = stack->content;
		stack = stack->next;
	}
	return (0);
}

long	find_next_min(t_list *stack, long last, int size)
{
	long	*buffer;
	long	next_min;
	int		index;

	buffer = malloc(sizeof(long) * size);
	index = 0;
	next_min = 0;
	while (stack)
	{
		buffer[index++] = stack->content - last;
		stack = stack->next;
	}
	index = 0;
	while (next_min < 1 && index < size)
		next_min = buffer[index++];
	while (size--)
	{
		if (buffer[size] > 0 && buffer[size] < next_min)
			next_min = buffer[size];
	}
	free(buffer);
	return (next_min + last);
}

void	minimize_values(t_list *stack, long min)
{
	int			counter;
	int			size;
	t_list		*copy;

	counter = 0;
	size = ft_lstsize(stack);
	while (counter < size)
	{
		copy = stack;
		while (copy)
		{
			if (copy->content == min)
			{
				min = find_next_min(stack, copy->content, size);
				copy->content = counter++;
				break ;
			}
			copy = copy->next;
		}
	}
}

void	normalize_list(t_list *stack)
{
	t_list	*temp;
	long	min;

	temp = stack;
	min = INT32_MAX;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	temp = stack;
	if (min < 0)
	{
		while (temp)
		{
			temp->content -= min;
			temp = temp->next;
		}
		min = 0;
	}
	minimize_values(stack, min);
}
