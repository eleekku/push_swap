/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:06:00 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/29 18:00:48 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear(*stack_a);
	if (stack_b)
		ft_lstclear(*stack_b);
}

void	smallesttob(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	t_stack	*current;

	current = *a;
	i = get_lowestint(a);
	while (current->seque != i)
		current = current->next;
	if (current->index > 3)
	{
		j = (ft_lstsize(*a) - current->index);
		while (j-- >= 0)
			ops_sort3(a, b, 9);
		ops_sort2(a, b, 5);
	}
	else
	{
		j = current->index;
		while (j-- > 1)
			ops_sort2(a, b, 6);
		ops_sort2(a, b, 5);
	}
}

void	algorithmsort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 4)
	{
		algo_for_three(a, b);
		ops_sort(a, b, 4);
		ops_sort(a, b, 4);
		sorting(a, b);
		free_all(a, b);
		return ;
	}
	else if (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 6)
		smallesttob(a, b);
	else
		find_number(a, b);
	algorithmsort(a, b);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		i;

	i = ft_lstsize(*stack_b) + 1;
	while (i-- > 0)
	{
		current_b = *stack_b;
		current_a = *stack_a;
		if (*stack_a && current_b && current_a->seque - 1 != current_b->seque)
			rotation(stack_a, stack_b, i);
		ops_sort(stack_a, stack_b, 4);
	}
}

int	main(int argc, char **argv)
{
	int			flag;
	t_stack		*stack_a;
	t_stack		*stack_b;
	static char	**arg;

	flag = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
		arg = split_arguments(argv[1], &flag);
	else
		arg = argv;
	if (check_args(arg, flag) == 0)
	{
		ft_putendl_fd("Error", 2);
		exit (0);
	}
	args_to_list(&stack_a, arg, flag);
	if (check_correct(&stack_a) == 1)
	{
		free_all(&stack_a, &stack_b);
		return (0);
	}
	algorithmsort(&stack_a, &stack_b);
	return (0);
}
