#include "../includes/push_swap.h"

void	do_rotate(t_stack **a, t_stack **b, int flag)
{
	if (flag == 0)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else if (flag == 1)
	{
		rotate(b);
		ft_printf("rb\n");
	}
	else if (flag == 2)
	{
		rotate(a);	
		rotate(b);
		ft_printf("rr\n");
	}
}

void	rotate(t_stack **list)
{
	t_stack	*aux;
	t_stack	*last;

	aux = *list;
	*list = (*list)->next;
	last = *list;
	while (last->next != NULL)
		last = last->next;
	aux->next = NULL;
	last->next = aux;
}
