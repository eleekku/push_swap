/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:34:11 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/29 18:23:43 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algo_for_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *stack_a;
	n2 = n1->next;
	n3 = n2->next;
	if (ft_lstsize(*stack_a) == 2 && check_correct(stack_a) != 1)
		ops_sort(stack_a, stack_b, 1);
	else if (n1->value < n2->value && n1->value > n3->value)
		ops_sort3(stack_a, stack_b, 9);
	else if (n1->value > n2->value && n2->value > n3->value)
	{
		ops_sort(stack_a, stack_b, 1);
		ops_sort3(stack_a, stack_b, 9);
	}
	else if (n1->value < n2->value && n2->value > n3->value)
	{
		ops_sort3(stack_a, stack_b, 9);
		ops_sort(stack_a, stack_b, 1);
	}
	else if (n1->value > n2->value && n1->value < n3->value)
		ops_sort(stack_a, stack_b, 1);
	else if (n1->value > n2->value && n1->value > n3->value)
		ops_sort2(stack_a, stack_b, 6);
}

void	find_number(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		buf;
	t_stack	*current;

	buf = 20;
	if (ft_lstsize(*stack_a) > 200)
		buf = (ft_lstsize(*stack_a) / 10);
	current = *stack_a;
	i = check_top(stack_a, buf);
	while (current->index != i)
		current = current->next;
	if (i > (ft_lstsize(*stack_a) / 2))
	{
		i = ft_lstsize(*stack_a) - i + 1;
		while (i-- > 0)
			ops_sort3(stack_a, stack_b, 9);
	}
	else
	{
		while (i-- > 1)
			ops_sort2(stack_a, stack_b, 6);
	}
	push_tob(stack_a, stack_b, buf);
}

void	push_tob(t_stack **stack_a, t_stack **stack_b, int buf)
{
	int		i;
	t_stack	*current;

	current = *stack_a;
	i = get_lowestint(stack_a);
	if (current->seque < i + (buf / 2))
	{
		ops_sort2(stack_a, stack_b, 5);
		ops_sort2(stack_a, stack_b, 7);
	}
	else
		ops_sort2(stack_a, stack_b, 5);
}

int	check_top(t_stack **stack_a, int buf)
{
	int		i;
	int		lowest;
	t_stack	*current;
	t_stack	*besthigh;
	t_stack	*highest;

	current = *stack_a;
	highest = get_highest(stack_a);
	lowest = get_lowestint(stack_a);
	besthigh = *stack_a;
	i = 0;
	while (current && i < ft_lstsize(*stack_a))
	{
		if (current->seque < lowest + buf
			&& current->seque < highest->seque - 4)
			return (current->index);
		else if (besthigh->seque > current->seque)
			besthigh = current;
		current = current->next;
		i++;
	}
	return (besthigh->index);
}

void	rotation(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*highest;
	int		j;

	highest = get_highest(stack_b);
	if (highest && highest->index > (i / 2))
	{
		j = i - (highest->index) + 1;
		while (j-- > 0)
			ops_sort3(stack_a, stack_b, 10);
	}
	else
	{
		j = highest->index;
		while (j-- > 1)
			ops_sort2(stack_a, stack_b, 7);
	}
}
