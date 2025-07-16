#include "../includes/push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	free_args(char **args)
{
	int	i;
	
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	stack_free(t_stack **list, int iserror)
{
	t_stack	*node;
	t_stack	*n_node;

	if (!list)
		return ;
	node = *list;
	while (node != NULL)
	{
		n_node = node->next;
		free(node);
		node = n_node;
	}
	free(node);
	if (iserror != 0)
		error();
}

long	ft_atol(const char *nptr)
{
	int				i;
	long long int	n;
	int				sign;

	i = 0;
	sign = 1;
	n = 0;
	if (ft_strncmp(nptr, "-2147483648", 11) == 0)
		return (-2147483648);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

int	list_len(t_stack **list)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = *list;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
