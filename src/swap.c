#include "../includes/push_swap.h"

void	do_swap(t_stack **a, t_stack **b, int flag)
{
	if (flag == 0)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (flag == 1)
	{
		swap(b);
		ft_printf("sb\n");
	}
	else if (flag == 2)
	{
		swap(a);
		swap(b);
		ft_printf("ss\n");
	}	
}

void	swap(t_stack **list)
{
	t_stack *aux;
	t_stack *next_aux;

	aux = *list;
	*list = (*list)->next;
	next_aux = (*list)->next;
	(*list)->next = aux;
	aux->next = next_aux;
}
