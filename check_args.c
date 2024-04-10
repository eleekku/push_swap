/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:17:21 by esalmela          #+#    #+#             */
/*   Updated: 2024/01/05 13:16:35 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include <limits.h>

long int	ft_atoilong(const char *str)
{
	int			sign;
	long int	result;
	int			count;

	sign = 1;
	result = 0;
	count = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483648)
			return (2147483648);
		str++;
	}
	return (result * sign);
}

int	check_dublicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_atoi(argv[0]) == 0 && argv[0][0] != 0)
	{
		i++;
		j++;
	}
	while (argv[i] != '\0')
	{
		while (argv[j] != '\0')
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	check_args(char **argv, int flag)
{
	int	j;

	if (!*argv)
		return (0);
	while (*argv && argv[flag] != '\0')
	{
		if (!argv || !argv[flag][0])
			return (0);
		j = 0;
		while (argv[flag][j] != '\0')
		{
			if ((ft_isdigit(argv[flag][j]) == 0 && j != 0) ||
					(ft_isdigit(argv[flag][j]) == 0 && argv[flag][j] != '-') ||
					(argv[flag][j] == '-' && !argv[flag][j + 1]))
				return (0);
			j++;
		}
		if ((ft_atoilong(argv[flag]) > 2147483647)
			|| (ft_atoilong(argv[flag]) < -2147483648))
			return (0);
		flag++;
	}
	if (check_dublicates(argv) == 0)
		return (0);
	return (1);
}

char	**split_arguments(char *argv, int *flag)
{
	char	**newargs;

	*flag = 0;
	newargs = ft_split(argv, ' ');
	return (newargs);
}

void	args_to_list(t_stack **stack_a, char **argv, int flag)
{
	int		index;
	t_stack	*new;

	index = 1;
	while (argv[flag] != '\0')
	{
		new = ft_lstnew(ft_atoi(argv[flag++]), index++);
		if (!new)
			free_all(stack_a, NULL);
		ft_lstadd_back(stack_a, new);
	}
	order_list(stack_a);
}
