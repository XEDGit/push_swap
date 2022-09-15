/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:57:01 by lmuzio            #+#    #+#             */
/*   Updated: 2022/09/15 18:52:57 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(t_list *a, t_list *b, t_list *instructions)
{
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	if (instructions)
		ft_lstclear(&instructions);
	write(2, "Error\n", 6);
	exit(0);
}

void	print_instructions(t_list *instructions)
{
	while (instructions)
	{
		if (instructions->content == PA)
			write(1, "pa\n", 3);
		else if (instructions->content == PB)
			write(1, "pb\n", 3);
		else if (instructions->content == SA)
			write(1, "sa\n", 3);
		else if (instructions->content == SB)
			write(1, "sb\n", 3);
		else if (instructions->content == SS)
			write(1, "ss\n", 3);
		else if (instructions->content == RA)
			write(1, "ra\n", 3);
		else if (instructions->content == RB)
			write(1, "rb\n", 3);
		else if (instructions->content == RR)
			write(1, "rr\n", 3);
		else if (instructions->content == RRA)
			write(1, "rra\n", 4);
		else if (instructions->content == RRB)
			write(1, "rrb\n", 4);
		instructions = instructions->next;
	}
}

void	simplify_loop(t_list **instr_buffer)
{
	if ((instr_buffer[1]->content == PB && instr_buffer[2]->content == PA) \
	|| (instr_buffer[1]->content == PA && instr_buffer[2]->content == PB))
	{
		instr_buffer[0]->next = instr_buffer[2]->next;
		free(instr_buffer[1]);
		instr_buffer[1] = instr_buffer[2]->next;
		free(instr_buffer[2]);
		if (instr_buffer[1] == 0)
			instr_buffer[2] = 0;
		else
			instr_buffer[2] = instr_buffer[1]->next;
	}
	else
	{
		instr_buffer[0] = instr_buffer[1];
		instr_buffer[1] = instr_buffer[2];
		instr_buffer[2] = instr_buffer[2]->next;
	}
}

void	simplify_instructions(t_list *instructions)
{
	int		size;
	t_list	*instr_buffer[3];

	size = INT32_MAX;
	while (size > ft_lstsize(instructions))
	{
		instr_buffer[0] = instructions;
		instr_buffer[1] = instructions->next;
		instr_buffer[2] = instructions->next->next;
		size = ft_lstsize(instructions);
		while (instr_buffer[2])
			simplify_loop(instr_buffer);
	}
}

int	main(int argc, char *argv[])
{
	t_list				*a;
	t_list				*b;
	t_list				*instructions;

	a = 0;
	b = 0;
	if (argc < 2)
		exit(0);
	a = parse_arguments(argc, argv, a);
	if (ft_lstsize(a) == 1)
		exit(0);
	normalize_list(a);
	instructions = ft_lstnew(0);
	if (!instructions)
		error_handler(a, 0, 0);
	sort(&a, &b, instructions);
	if (ft_lstsize(instructions) > 1)
		simplify_instructions(instructions);
	print_instructions(instructions->next);
	ft_lstclear(&instructions);
	ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	exit(0);
}
