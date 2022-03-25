/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:54:09 by lmuzio            #+#    #+#             */
/*   Updated: 2022/03/24 19:35:58 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list *a, int value)
{
	while (a)
	{
		if (a->content == value \
		|| a->content > INT32_MAX \
		|| a->content < INT32_MIN)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_digits(const char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) \
			|| *str == '-' \
			|| *str == '+'))
			return (1);
		str++;
	}
	return (0);
}

t_list	*parse_arguments(int argc, char *argv[], t_list *a)
{
	long	temp;

	while (--argc)
	{
		if (check_digits(argv[argc]))
			error_handler();
		temp = ft_atoi(argv[argc]);
		if (check_duplicates(a, temp))
			error_handler();
		ft_lstadd_front(&a, ft_lstnew(temp));
	}
	return (a);
}
