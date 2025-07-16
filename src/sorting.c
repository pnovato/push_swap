#include "../includes/push_swap.h"

int	show_last_index(t_stack **a)
{
	t_stack *aux;

	aux = *a;
	while (aux->next)
		aux = aux->next;
	return (aux->index);
}

bool	check_index(t_stack **a)
{
	t_stack	*aux;
	
	aux = *a;
	while (aux)
	{
		if (aux->index == -1)
			break;
		else if (aux->next == NULL)
			return (true);
		aux = aux->next;
	}
	return (false);
}

void	sort_index(t_stack **list)
{
	t_stack	*aux;
	t_stack	*next_aux;
	int		i;

	i = 0;
	while (!check_index(list))
	{
		aux = *list;
		while (aux)
		{
			next_aux = *list;
			while (next_aux)
			{
				if (aux->value > next_aux->value && next_aux->index == -1)
					break ;
				else if (next_aux->next == NULL && aux->index == -1)
				{
					aux->index = i;
					i++;
				}
				next_aux = next_aux->next;
			}
			aux = aux->next;
		}
	}
}

bool	check(t_stack **list)
{
	t_stack	*aux;
	t_stack	*next_aux;
	int	small;
	
	aux = *list;
	while (aux)
	{
		small = aux->value;
		next_aux = aux->next;
		while (next_aux)
		{
			if (small > next_aux->value)
				return (false);
			next_aux = next_aux->next;
		}
		aux = aux->next;
	}
	return (true);
}

void	sorting(t_stack **a)
{
	t_stack	*b;
	
	b = NULL;
	sort_index(a);
	if (check(a))
		exit(0);
	else if (list_len(a) == 2)
		sort_2(a);
	else if (list_len(a) == 3)
		sort_3(a);
	else if (list_len(a) == 4)
		sort_4(a, &b);
	else if (list_len(a) == 5)
		sort_5(a, &b);
	else
		radix(a, &b, list_len(a));
}
