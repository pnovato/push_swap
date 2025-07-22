#include "../includes/push_swap.h"

t_stack	*newnode(char *str)
{
	t_stack		*new;
	long int	n;

	n = ft_atol(str);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = (int)n;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack	*initstack_a(char **args, int from_malloc)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	a = NULL;
	i = 0;
	while (args[i])
	{
		if (!a)
		{
			a = newnode(args[i]);
			temp = a;
		}
		else
		{
			temp->next = newnode(args[i]);
			temp = temp->next;
		}
		i++;
	}
	if (from_malloc)
		free_args(args);
	return (a);
}


char	**parse_args(int ac, char **av, int *from_malloc)
{
	char	**args;

	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		if (ac < 2)
			exit(0);
		else
			error();
	}
	if (ac == 2)
	{
		args = splitargs(av[1]);
		*from_malloc = 1;
	}
	else
	{
		if (checkvalidargs(av, 1) == 1)
			error();
		args = av + 1;
		*from_malloc = 0;
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**args;
	int		from_malloc;

	args = parse_args(ac, av, &from_malloc);
	a = initstack_a(args, from_malloc);
	check_equal(&a);
	sorting(&a);
	stack_free(&a, 0);
	return (0);
}
