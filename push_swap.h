/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:54:27 by lmuzio            #+#    #+#             */
/*   Updated: 2022/09/15 19:03:09 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"


# define PA 5
# define PB 6
# define SA 7
# define SB 8
# define SS 9
# define RA 10
# define RB 11
# define RR 12
# define RRA 13
# define RRB 14
# define RRR 15

int				check_duplicates(t_list *a, int value);
int				check_digits(const char *str);
int				find_max_bit(t_list *stack);
t_list			*parse_arguments(int argc, char *argv[], t_list *a);
void			error_handler(t_list *a, t_list *b, t_list *instructions);
void			sort(t_list **a, t_list **b, t_list *instructions);
void			sort_2(t_list *a, t_list *b, t_list *instructions);
void			sort_3(t_list *a, t_list *b, t_list *instructions);
void			sort_4(t_list **a, t_list **b, t_list *instructions);
void			pre_sort_5(t_list **a, t_list **b, t_list **instructions);
void			sort_5(t_list **a, t_list **b, t_list *instructions);
void			add_instruction(t_list *instructions, int to_add);
void			normalize_list(t_list *stack);
void			push(t_list **from, t_list **to);
void			swap(t_list *stack);
void			rotate(t_list **stack);
void			reverse_rotate(t_list **stack);
int				check_sort(t_list *stack);
int				find_max_bit(t_list *stack);

#endif