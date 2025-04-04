#include "../../includes/push_swap.h"

void	sa(t_list **a, int print)
{
    t_list	*head;
    t_list	*tmp;

    if (!a || !*a || ft_lstsize(*a) < 2)
        return ;
    head = *a;
    *a = (*a)->next;
    tmp = (*a)->next;
    (*a)->next = head;
    head->next = tmp;
    if (print)
        write(1, "sa\n", 3);
}

void	sb(t_list **b, int print)
{
    sa(b, 0);
    if (print)
        write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int print)
{
    sa(a, 0);
    sb(b, 0);
    if (print)
        write(1, "ss\n", 3);
}