/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:04:09 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/29 18:14:40 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_highest(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*highest;

	if (!stack_a)
		return (NULL);
	current = *stack_a;
	highest = *stack_a;
	while (current != NULL)
	{
		if (highest->value < current->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_stack	*get_lowest(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*lowest;

	current = *stack_a;
	lowest = *stack_a;
	while (lowest->seque != 0)
		lowest = lowest->next;
	while (current != NULL)
	{
		if (current->seque == 0 && lowest->value > current->value)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	order_list(t_stack **stack_a)
{
	int		i;
	t_stack	*lowest;
	t_stack	*highest;
	t_stack	*current;

	current = *stack_a;
	while (current != NULL)
	{
		current->seque = 0;
		current = current->next;
	}
	lowest = NULL;
	i = 1;
	highest = get_highest(stack_a);
	while (i < ft_lstsize(*stack_a))
	{
		lowest = get_lowest(stack_a);
		lowest->seque = i;
		i++;
	}
	highest->seque = i;
}

int	get_lowestint(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*lowest;

	current = *stack_a;
	lowest = *stack_a;
	if (!current)
		return (0);
	while (current)
	{
		if (lowest->seque > current->seque)
			lowest = current;
		current = current->next;
	}
	return (lowest->seque);
}

int	check_correct(t_stack **stack_a)
{
	t_stack	*node1;

	node1 = *stack_a;
	while (node1->next && (node1->value < node1->next->value))
		node1 = node1->next;
	if (node1->next == NULL)
		return (1);
	return (0);
}
