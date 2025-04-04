#include "../../includes/push_swap.h"

void	ra(t_list **a, int print)
{
    t_list	*temp;
    t_list	*head;

    if (!a || !*a || ft_lstsize(*a) < 2)
        return ;
    head = (*a)->next;
    temp = ft_lstlast(*a);
    temp->next = *a;
    (*a)->next = NULL;
    *a = head;
    if (print)
        write(1, "ra\n", 3);
}

void	rb(t_list **b, int print)
{
    ra(b, 0);
    if (print)
        write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int print)
{
    ra(a, 0);
    rb(b, 0);
    if (print)
        write(1, "rr\n", 3);
}