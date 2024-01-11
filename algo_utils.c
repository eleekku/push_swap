#include "push_swap.h"

t_stack	*get_highest(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*highest;

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


int	get_median(t_stack **stack_a)
{
	int		median;
	t_stack	*highest;
	t_stack	*current;

	order_list(stack_a);
	current = *stack_a;
	highest = get_highest(stack_a);
	median = highest->seque / 2;
	while (current->seque != median)
		current = current->next;
	return (current->value);
}

void	order_list(t_stack **stack_a)
{
	int		i;
	t_stack	*lowest;
	t_stack	*highest;
	t_stack *current;

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