/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_raw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:34:19 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/05 13:33:20 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_stack **stack_a)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = *stack_a;
		while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
		}
}

void	swap(t_stack **stack_a)
{
	t_stack	*node1;
	t_stack	*node2;
	int		temp;

	node1 = *stack_a;
	node2 = node1->next;
	temp = node1->value;
	node2->index = node1->index;
	node1->value = node2->value;
	node1->index = node2->index;
	node2->value = temp;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node1;

	if (*stack_a != NULL)
	{
		node1 = *stack_a;
		*stack_a = node1->next;
		node1->next = *stack_b;
		*stack_b = node1;
	}
	update_index(stack_a);
	update_index(stack_b);
}

void	rotate(t_stack **stack_a)
{
	t_stack	*firstnode;
	t_stack	*secondnode;
	t_stack	*lastnode;

	firstnode = *stack_a;
	secondnode = firstnode->next;
	lastnode = *stack_a;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	*stack_a = secondnode;
	lastnode->next = firstnode;
	firstnode->next = NULL;
	update_index(stack_a);
}

void	reverserotate(t_stack **stack_a)
{
	t_stack	*firstnode;
	t_stack	*secondlastnode;
	t_stack	*lastnode;

	lastnode = *stack_a;
	firstnode = *stack_a;
	while (lastnode->next != NULL)
	{
		secondlastnode = lastnode;
		lastnode = lastnode->next;
	}
	*stack_a = lastnode;
	lastnode->next = firstnode;
	secondlastnode->next = NULL;
	update_index(stack_a);
}