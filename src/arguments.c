/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:54:09 by lmuzio            #+#    #+#             */
/*   Updated: 2022/10/21 17:02:58 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list *a, long value)
{
	if (value > INT32_MAX \
	|| value < INT32_MIN)
		return (1);
	while (a)
	{
		if (a->content == value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_digits(const char *str)
{
	if ((*str == '+' || *str == '-'))
		str++;
	if ((*str == '+' || *str == '-') || !*str)
		return (1);
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		return (0);
	return (1);
}

void	multivalue_error(t_list *a, char **values)
{
	free2d(values, -1);
	error_handler(a, 0, 0);
}

int	workout_multivalue(char *argv, t_list **a)
{
	char	**values;
	int		i;
	long	temp;

	if (ft_strchr(argv, ' ') == NULL)
		return (0);
	values = ft_split(argv, ' ');
	if (!values)
		error_handler((*a), 0, 0);
	i = 0;
	while (values[i])
		i++;
	i -= 1;
	while (i != -1)
	{
		if (check_digits(values[i]))
			multivalue_error((*a), values);
		temp = ft_atoi(values[i--]);
		if (check_duplicates((*a), temp))
			multivalue_error((*a), values);
		if (ft_lstadd_front(&(*a), ft_lstnew(temp)))
			multivalue_error((*a), values);
	}
	free2d(values, -1);
	return (1);
}

t_list	*parse_arguments(int argc, char *argv[], t_list *a)
{
	long	temp;
	t_list	*to_free;

	to_free = 0;
	while (--argc)
	{
		if (workout_multivalue(argv[argc], &a))
			continue ;
		if (check_digits(argv[argc]))
			error_handler(to_free, 0, 0);
		temp = ft_atoi(argv[argc]);
		if (check_duplicates(a, temp))
			error_handler(to_free, 0, 0);
		if (ft_lstadd_front(&a, ft_lstnew(temp)))
			error_handler(a, 0, 0);
		to_free = a;
	}
	return (a);
}
