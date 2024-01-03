# include "push_swap.h"
# include "Libft/libft.h"
#include <limits.h>

long int	ft_atoilong(const char *str)
{
	int			sign;
	long int	result;
	int			count;

	sign = 1;
	result = 0;
	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		count++;
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str == ' ' || (*str >= 9 && *str <= 13) || (count > 1))
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
int check_dublicates(char **argv, int flag)
{
	int i;
	int j;

	i = flag;
	j = flag + 1;
	while (argv[i] != '\0')
	{
		while (argv[j] != '\0')
		{
			if ((ft_strncmp(argv[i], argv[j], 11)) == 0)
			return (0);
			else
			j++;
		}
	i++;
	j = i + 1;	
	}
	return (1);
}

int check_args(char **argv, int flag)
{
	int i;
	int j;
	i = flag;
	while(argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((ft_isdigit(argv[i][j]) == 0 && j != 0) || (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'))
				return (0);
			j++;
		}

	//if ((argv[i][0] != '0' || argv[i][1] != '\0') && ft_atoilong(argv[i]) == 0)
	//	return (0);
	if ((ft_atoilong(argv[i]) > INT_MAX) || (ft_atoilong(argv[i]) < INT_MIN))
		return (0);
	i++;
	}
	if (check_dublicates(argv, flag) == 0)
		return (0);
	return (1);
}

char	**split_arguments(char *argv, int *flag)
{
	*flag = 0;
	char **args;

	return (args = ft_split(argv, ' '));
}

