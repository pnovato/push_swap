#include "../includes/push_swap.h"

void	sort_2(t_stack **list)
{
	if (!check(list))
		do_swap(list, NULL, 0);
	else
		return;
}

void	sort_3(t_stack **list)
{
	int	a;
	int	b;
	int	c;

	while (!check(list))
	{
		a = (*list)->index;
		b = (*list)->next->index;
		c = (*list)->next->next->index;
		if ((a > b && b > c) || (a > b && b < c && a < c)
			|| (a < b && b > c && a < c))
			do_swap(list, NULL, 0);
		else if (a > b && b < c)
			do_rotate(list, NULL, 0);
		else if (a < b && b > c)
			do_reverse(list, NULL, 0);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	if (check(a))
		return ;
	if ((*a)->index == 0)
	{
		do_push(a, b, 1);
		sort_3(a);
		do_push(a, b, 0);
	}
	else if (show_last_index(a) == 0)
	{
		do_rotate(a, b, 0);
		do_push(a, b, 1);
		sort_3(a);
		do_push(a, b, 0);
	}
	else
	{
		while ((*a)->index != 0)
			do_rotate(a, b, 0);
		do_push(a, b, 1);
		sort_3(a);
		do_push(a, b, 0);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	if (check(a))
		return ;
	while (list_len(b) != 2)
	{
		if (show_last_index(a) == 0 || show_last_index(a) == 1)
		{
			do_rotate(a, b, 0);
			do_push(a, b, 1);
		}
		else if ((*a)->index == 0 || (*a)->index == 1)
			do_push(a, b, 1);
		else
			do_rotate(a, b, 0);
	}
	sort_3(a);
	if ((*b)->index < (*b)->next->index)
		do_rotate(a, b, 1);
	do_push(a, b, 0);
	do_push(a, b, 0);
}

void	radix(t_stack **a, t_stack **b, int a_len)
{
	int	bit;
	int	i;
	t_stack	*aux;

	bit = 0;
	while (!check(a))
	{
		i = 0;
		while (a && list_len(a) > 0 && i++ < a_len)
		{
			aux = (*a)->next;
			if ((((*a)->index >> bit) & 1) == 0)
				do_push(a, b, 1);
			else
				do_rotate(a, b, 0);
			*a = aux;
		}
		bit++;
		while (*b)
		{
			aux = (*b)->next;
			do_push(a, b, 0);
			*b = aux;
		}
	}
}
