#include "../includes/push_swap.h"

void	do_push(t_stack **a, t_stack **b, int flag)
{
	if (flag == 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
	else if (flag == 1)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}

void	push(t_stack **orig, t_stack **dest)
{
	t_stack	*aux;
	
	if (!*orig)
		return;
	aux = *orig;
	*orig = (*orig)->next;
	if (!*dest)
	{
		*dest = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *dest;
		*dest = aux;
	}
}
