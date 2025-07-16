#include "../includes/push_swap.h"

void	do_reverse(t_stack **a, t_stack **b, int flag)
{
	if (flag == 0)
	{
		reverse(a);
		ft_printf("rra\n");
	}
	else if (flag == 1)
	{
		reverse(b);
		ft_printf("rrb\n");
	}
	else if (flag == 2)
	{
		reverse(a);
		reverse(b);
		ft_printf("rrr\n");
	}
}

void	reverse(t_stack **list)
{
	t_stack	*aux;
	t_stack	*last;
	
	aux = *list;
	while (aux)
	{
		last = aux->next;
		if (last->next == NULL)
			break;
		aux = aux->next;
	}
	aux->next = NULL;
	last->next = *list;
	*list = last;
}
