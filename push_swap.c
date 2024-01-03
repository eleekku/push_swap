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
	int j;
	int flag;
	t_stack *stack_a;
	t_stack *stack_b;

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
	j = 0;
	while (argv[flag] != '\0')
	ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(argv[flag++]), j++)));
/* 	while (stack_a != NULL)
	{
        ft_printf("ft_lstnew: %d, index:%d\n", stack_a->value, stack_a->index);
		free(stack_a);
		stack_a = stack_a->next;
	} */
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
}

