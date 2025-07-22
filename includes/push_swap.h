#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//main.c
int     main(int ac, char **av);
t_stack	*newnode(char *str);
t_stack *initstack_a(char **args, int from_malloc);
char	**parse_args(int ac, char **av, int *from_malloc);

// void	printlst(t_stack **lst);

// sorting.c
int     show_last_index(t_stack **a);
bool    check_index(t_stack **a);
void    sort_index(t_stack **list);
bool    check(t_stack **list);
void    sorting(t_stack **a);

//swap.c
void    do_swap(t_stack **a, t_stack **b, int flag);
void    swap(t_stack **list);

//push.c
void    do_push(t_stack **a, t_stack **b, int flag);
void    push(t_stack **orig, t_stack **dest);

//rotate.c
void    do_rotate(t_stack **a, t_stack **b, int flag);
void    rotate(t_stack **list);

//reverse.c
void    do_reverse(t_stack **a, t_stack **b, int flag);
void    reverse(t_stack **list);
//radix.c
void    sort_2(t_stack **list);
void    sort_3(t_stack **list);
void    sort_4(t_stack **a, t_stack **b);
void    sort_5(t_stack **a, t_stack **b);
void    radix(t_stack **a, t_stack **b, int a_len);

//utils.c
void    error(void);
void    free_args(char **args);
void    stack_free(t_stack **list, int iserror);
long    ft_atol(const char *nptr);
int     list_len(t_stack **list);

//parsing.c
char    **splitargs(char *str);
int     checkdigit(char *str);
int     checkvalidargs(char **args, int i);
void    checkspace(char *str);
void    check_equal(t_stack **a);


#endif
