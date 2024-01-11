/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:06:00 by esalmela          #+#    #+#             */
/*   Updated: 2023/12/19 11:44:08 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		index;
	int		flag;
	t_stack	*stack_a;
	t_stack	*stack_b;

	int i;

	flag = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = split_arguments(argv[1], &flag);
	if (check_args(argv, flag) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	index = 1;
	while (argv[flag] != '\0')
		ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(argv[flag++]), index++)));
	if (check_correct(&stack_a) == 1)
	{
		ft_printf("allready in correct order\n");
		return (0);
	}
	//if (index <= 4)
	//algo_for_three(&stack_a, &stack_b);
//	else if (index > 4 && index < 7)
//		algo_for_five(&stack_a, &stack_b);
//	else
//	t_stack *median = get_median(&stack_a);
//	ft_printf("%d\n", median->value);
 	algorithm(&stack_a, &stack_b);
	
 	while (stack_a != NULL)
	{
    ft_printf("value: %d, index:%d sequence:%d\n", stack_a->value, stack_a->index, stack_a->seque);
		free(stack_a);
		stack_a = stack_a->next;
	} 
	ft_printf("STACKB\n");
 	while (stack_b != NULL)
	{
    ft_printf("value: %d, index:%d sequence:%d\n", stack_b->value, stack_b->index, stack_b->seque);
		free(stack_b);
		stack_b = stack_b->next;
	}  
}


	/* i = get_median(&stack_a);
	ft_printf("%d\n", i); */


 /* 	while (stack_a != NULL)
	{
        ft_printf("ft_lstnew: %d, index:%d\n", stack_a->value, stack_a->index);
		free(stack_a);
		stack_a = stack_a->next;
	} 
	//sa(&stack_a);
	rotate(&stack_a);
	while (stack_a != NULL)
	{
        ft_printf("ft_lstnew: %d, index:%d\n", stack_a->value, stack_a->index);
		free(stack_a);
		stack_a = stack_a->next;
	}
	//ft_printf("ft_lstnew: %d, index:%d\n", stack_a->value, stack_a->index);
	//stack_a = stack_a->next;
	//ft_printf("ft_lstnew: %d, index:%d\n", stack_a->value, stack_a->index);
} */

