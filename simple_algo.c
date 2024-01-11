/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:34:11 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/05 13:44:33 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* int	find_break(t_stack **stack_a)
{
	int		i;
	t_stack	*node1;

	i = 1;
	node1 = *stack_a;
	while (node1->next && (node1->value < node1->next->value))
	{
		i++;
		node1 = node1->next;
	}
	return (i);
} */

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

void	algo_for_four(t_stack **a, t_stack **b)
{
	algo_for_three(a, b);
	if ((*b)->value < (*a)->value)
		ops_sort(a, b, 4);
	else if ((*a)->value < (*b)->value && (*b)->value < (*a)->next->value)
	{
		ops_sort2(a, b, 6);
		ops_sort(a, b, 4);
		ops_sort3(a, b, 9);
	}
	else if ((*a)->next->value < (*b)->value
		&& (*b)->value < (*a)->next->next->value)
	{
		ops_sort3(a, b, 9);
		ops_sort(a, b, 4);
		ops_sort2(a, b, 6);
		ops_sort2(a, b, 6);
	}
	else
	{
		ops_sort(a, b, 4);
		ops_sort2(a, b, 6);
	}
}
void	algo_for_five(t_stack **a, t_stack **b)
{
	int i;

	i = ft_lstsize(*a);
	if (i <= 3)
	{
		algo_for_three(a, b);
		return;
	} 
	ops_sort2(a, b, 5);
	if (i == 4)
	{
		algo_for_four(a, b);
		return;
	}
	ops_sort2(a, b, 5);
	if ((*b)->value < (*b)->next->value)
		ops_sort(a, b, 2);
	algo_for_four(a, b);
	to_stack(a, b);
}
void	to_stack(t_stack **a, t_stack **b)
{
	if ((*b)->value < (*a)->value)
		ops_sort(a, b, 4);
	else if ((*b)->value > (*a)->value && (*b)->value < (*a)->next->value)
	{
		ops_sort(a, b, 4);
		ops_sort(a, b, 1);
	}
	else if (((*b)->value > (*a)->next->value && (*b)->value < (*a)->next->next->value))
	{
		ops_sort2(a, b, 6);
		ops_sort(a, b, 4);
		ops_sort(a, b, 1);
		ops_sort3(a, b, 9);
	}
	else
	{
		ops_sort3(a, b, 9);
		ops_sort(a, b, 4);
		ops_sort2(a, b, 6);
		ops_sort2(a, b, 6);
	}
}
 
void		algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int 	j;
	t_stack	*current;
	int		median;
	j = ft_lstsize(*stack_a);
	if (j <= 5)
	{
		algo_for_five(stack_a, stack_b);
		return ;
	}
	median = get_median(stack_a);
	i = 0;
	current = *stack_a;
	while (i < ((j / 2) - 1)&& current)
	{
		if (current->value < median)
		{
			ops_sort2(stack_a, stack_b, 5);
			i++;
		}
		else
			ops_sort2(stack_a, stack_b, 6);
		current = *stack_a;
	}
	algorithm(stack_a, stack_b);
	return ; 
}

	/* else
	{ 
		ft_printf("hello\n");
		ops_sort(a, b, 4);
		ops_sort2(a, b, 6);
	} */
/* 	if ((*b)->value > (*a)->next->value && (*b)->value < (*a)->next->next->value)

	else */

/* void	algo_for_five(t_stack **a, t_stack **b)
{
	t_stack *lastnode;
	int		median;

	if (ft_lstsize(*a) == 4)
	{
		algo_for_four(a, b);
		return ;
	}
	median = get_median(a);
	ops_sort2(a, b, 5);
	algo_for_four(a, b);
	if ((*b)->value > median)
	{
		if ((*b)->value > (*a)->next->next->value && (*b)->value < (*a)->next->next->next->value)
		{
			ops_sort3(a, b, 9);
			ops_sort(a, b, 4);
			ops_sort2(a, b, 6);
			ops_sort2(a, b, 6);
		}
		else if ((*b)->value > (*a)->next->value && (*b)->value < (*a)->next->next->value)
		{
			ft_printf("yo\n");
			ops_sort2(a, b, 6);
			ops_sort(a, b, 4);
			ops_sort(a, b, 1);
			ops_sort3(a, b, 9);
		}
		else
		{
			ops_sort(a, b, 4);
			ops_sort2(a, b, 6);
		}
	}
	else
	{
		if ((*b)->value < (*a)->value)
			ops_sort(a, b, 4);
		else
		{
			ops_sort(a, b, 4);
			ops_sort(a, b, 1);
		}
	}
} */
	/*
	lastnode = *a;
	while (lastnode->next->next)	
		lastnode = lastnode->next;
	if ((*b)->value > lastnode->value && (*b)->value < lastnode->next->value)
	{
		ops_sort3(a, b, 9);
		ops_sort(a, b, 4);
		ops_sort2(a, b, 6);
		ops_sort2(a, b, 6);
	}
	else
		{ 
			ft_printf("hello\n");
			ops_sort(a, b, 4);
			algo_for_four(a, b);
		} */
