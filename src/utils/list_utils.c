#include "../../includes/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    if (*lst)
        ft_lstlast(*lst)->next = new;
    else
        *lst = new;
}

t_list	*ft_lstnew(long long content)
{
    t_list	*newnode;

    newnode = malloc(sizeof(t_list));
    if (!newnode)
        return (NULL);
    newnode->content = content;
    newnode->next = NULL;
    return (newnode);
}

int	ft_lstsize(t_list *lst)
{
    int	i;

    if (!lst)
        return (0);
    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}