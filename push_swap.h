#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <limits.h>
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/libft.h"
#include <stdlib.h>

long int	ft_atoilong(const char *str);
int			check_args(char **argv, int flag);
int			check_dublicates(char **argv, int flag);
char		**split_arguments(char *argv, int *flag);
void		sa(t_stack **stack_a);
void	pushb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack_a);
#endif