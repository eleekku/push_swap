/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:23:46 by esalmela          #+#    #+#             */
/*   Updated: 2024/02/01 16:51:52 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

long int	ft_atoilong(const char *str);
int			check_args(char **argv, int flag);
int			check_dublicates(char **argv);
char		**split_arguments(char *argv, int *flag);
void		args_to_list(t_stack **stack_a, char **argv, int flag);
void		swap(t_stack **stack_a);
int			push(t_stack **stack_a, t_stack **stack_b);
int			rotate(t_stack **stack_a);
void		reverserotate(t_stack **stack_a);
void		update_index(t_stack **stack_a);
void		ops_sort(t_stack **stack_a, t_stack **stack_b, int ticket);
void		ops_sort2(t_stack **stack_a, t_stack **stack_b, int ticket);
void		ops_sort3(t_stack **stack_a, t_stack **stack_b, int ticket);
void		algo_for_three(t_stack **stack_a, t_stack **stack_b);
int			check_correct(t_stack **stack_a);
void		smallesttob(t_stack **stack_a, t_stack **stack_b);
void		order_list(t_stack **stack_a);
t_stack		*get_lowest(t_stack **stack_a);
t_stack		*get_highest(t_stack **stack_a);
int			get_lowestint(t_stack **stack_a);
void		find_number(t_stack **stack_a, t_stack **stack_b);
int			check_top(t_stack **stack_a, int buf);
void		sorting(t_stack **stack_a, t_stack **stack_b);
void		big_list(t_stack **stack_a, t_stack **stack_b, int buf);
void		algorithmsort(t_stack **a, t_stack **b);
void		push_tob(t_stack **stack_a, t_stack **stack_b, int buf);
void		rotation(t_stack **stack_a, t_stack **stack_b, int i);
void		free_all(t_stack **stack_a, t_stack **stack_b);
#endif
