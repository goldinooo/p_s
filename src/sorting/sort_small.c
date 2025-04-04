#include "../../includes/push_swap.h"

static int	case_check(t_list *stack)
{
    int	a;
    int	b;
    int	c;

    a = stack->content;
    b = stack->next->content;
    c = stack->next->next->content;
    if (a < b && b < c)
        return (1);
    if (a > b && b < c && c > a)
        return (2);
    if (a > b && b > c)
        return (3);
    if (a > b && b < c && c < a)
        return (4);
    if (a < b && b > c && c > a)
        return (5);
    return (6);
}

void	sort_3(t_list **a)
{
    int	check;

    if (ft_lstsize(*a) == 2 && (*a)->content > (*a)->next->content)
    {
        sa(a, 1);
        return ;
    }
    check = case_check(*a);
    if (check == 1)
        return ;
    else if (check == 2)
        sa(a, 1);
    else if (check == 3)
    {
        ra(a, 1);
        sa(a, 1);
    }
    else if (check == 4)
        ra(a, 1);
    else if (check == 5)
    {
        sa(a, 1);
        ra(a, 1);
    }
    else
        rra(a, 1);
}

static void	sort_4(t_list **a, t_list **b)
{
    int	i;

    i = getindex(a, 0);
    if (i == 1)
        sa(a, 1);
    else if (i == 2)
    {
        ra(a, 1);
        ra(a, 1);
    }
    else if (i == 3)
        rra(a, 1);
    pb(a, b, 1);
    sort_3(a);
    pa(a, b, 1);
}

static void	push_smallest_to_b(t_list **a, t_list **b, int index)
{
    int	i;

    i = getindex(a, index);
    if (i == 0)
        pb(a, b, 1);
    else if (i == 1)
    {
        sa(a, 1);
        pb(a, b, 1);
    }
    else if (i == 2)
    {
        ra(a, 1);
        ra(a, 1);
        pb(a, b, 1);
    }
    else if (i == 3)
    {
        rra(a, 1);
        rra(a, 1);
        pb(a, b, 1);
    }
    else if (i == 4)
    {
        rra(a, 1);
        pb(a, b, 1);
    }
}

void	sort_5(t_list **a, t_list **b)
{
    if (ft_lstsize(*a) == 4)
        sort_4(a, b);
    else
    {
        push_smallest_to_b(a, b, 0);
        push_smallest_to_b(a, b, 1);
        sort_3(a);
        pa(a, b, 1);
        pa(a, b, 1);
    }
    if (*a && (*a)->next && (*a)->content > (*a)->next->content)
        sa(a, 1);
}