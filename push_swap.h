/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:23:46 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/05 13:33:55 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <stdlib.h>

long int	ft_atoilong(const char *str);
int			check_args(char **argv, int flag);
int			check_dublicates(char **argv, int flag);
char		**split_arguments(char *argv, int *flag);
void		swap(t_stack **stack_a);
void		push(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack_a);
void		reverserotate(t_stack **stack_a);
void 		update_index(t_stack **stack_a);
void		ops_sort(t_stack **stack_a, t_stack **stack_b, int ticket);
void		ops_sort2(t_stack **stack_a, t_stack **stack_b, int ticket);
void		ops_sort3(t_stack **stack_a, t_stack **stack_b, int ticket);
void		algo_for_three(t_stack **stack_a, t_stack **stack_b);
int			check_correct(t_stack **stack_a);
void		algo_for_five(t_stack **stack_a, t_stack **stack_b);
int			get_median(t_stack **stack_a);
void		order_list(t_stack **stack_a);
t_stack		*get_lowest(t_stack **stack_a);
t_stack		*get_highest(t_stack **stack_a);
void		algorithm(t_stack **stack_a, t_stack **stack_b);
void		to_stack(t_stack **a, t_stack **b);
#endif
