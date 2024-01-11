/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:17:04 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/05 13:17:07 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ops_sort(t_stack **stack_a, t_stack **stack_b, int ticket)
{
	if (ticket == 1)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	if (ticket == 2)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	if (ticket == 3)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	if (ticket == 4)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	ops_sort2(t_stack **stack_a, t_stack **stack_b, int ticket)
{
	if (ticket == 5)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	if (ticket == 6)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	if (ticket == 7)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	if (ticket == 8)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}

void	ops_sort3(t_stack **stack_a, t_stack **stack_b, int ticket)
{
	if (ticket == 9)
	{
		reverserotate(stack_a);
		ft_printf("rra\n");
	}
	if (ticket == 10)
	{
		reverserotate(stack_b);
		ft_printf("rrb\n");
	}
	if (ticket == 11)
	{
		reverserotate(stack_a);
		reverserotate(stack_b);
		ft_printf("rrr\n");
	}
}
