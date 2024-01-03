# include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack *node1;
	t_stack *node2;
	int temp;

	node1 = *stack_a;
	node2 = node1->next;
	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}

void	pushb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node1;

	if (*stack_a != NULL)
	{
		node1 = *stack_a;
		*stack_a = node1->next;
		node1->next = *stack_b;
		*stack_b = node1;
	}
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
}