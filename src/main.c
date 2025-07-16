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

t_stack	*initstack_a(char **args, int i)
{
	t_stack	*a;
	t_stack	*temp;
	int		is_split;

	a = NULL;
	if (i == 0)
		is_split = 0;
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
	if (is_split == 0)
		free_args(args);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		if (ac < 2)
			exit(0);
		else
			error();
	}
	else if (ac == 2)
	{
		a = initstack_a(splitargs(av[1]), 0);
	}
	else
	{
		if (checkvalidargs(av, 1) == 1)
			error();
		a = initstack_a(av, 1);
	}
	check_equal(&a);
	sorting(&a);
	stack_free(&a, 0);
}

// void	printlst(t_stack **lst)
// {
// 	t_stack	*print;

// 	print = *lst;
// 	while (print)
// 	{
// 		ft_printf("%i %i\n", print->value, print->index);
// 		print = print->next;
// 	}
// }
