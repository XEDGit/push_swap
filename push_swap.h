/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:54:27 by lmuzio            #+#    #+#             */
/*   Updated: 2022/03/24 16:07:14 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"

# ifndef PA
#  define PA 5
# endif
# ifndef PB
#  define PB 6
# endif
# ifndef SA
#  define SA 7
# endif
# ifndef SB
#  define SB 8
# endif
# ifndef SS
#  define SS 9
# endif
# ifndef RA
#  define RA 10
# endif
# ifndef RB
#  define RB 11
# endif
# ifndef RR
#  define RR 12
# endif
# ifndef RRA
#  define RRA 13
# endif
# ifndef RRB
#  define RRB 14
# endif
# ifndef RRR
#  define RRR 15
# endif

int				check_duplicates(t_list *a, int value);
int				check_digits(const char *str);
int				find_max_bit(t_list *stack);
t_list			*parse_arguments(int argc, char *argv[], t_list *a);
void			error_handler(void);
void			sort(t_list *a, t_list *b, t_list *instructions);
void			add_instruction(t_list *instructions, int to_add);
void			normalize_list(t_list *stack);
void			push(t_list **from, t_list **to);
void			swap(t_list *stack);
void			rotate(t_list **stack);
void			reverse_rotate(t_list **stack);
int				check_sort(t_list *stack);
int				find_max_bit(t_list *stack);

#endif