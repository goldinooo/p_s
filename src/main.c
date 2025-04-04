#include "../includes/push_swap.h"

void	skip(char **av)
{
    int	i;
    int	j;

    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            check_ev(av, i, j);
            j++;
        }
        i++;
    }
}

int	main(int ac, char **av)
{
    char	**array;
    t_list	*a;
    t_list	*b;
    int		i;
    t_list	*new_node;

    skip(av);
    array = NULL;
    b = NULL;
    array = args_handler(&ac, av);
    i = 0;
    a = ft_lstnew(ft_atoi(array[i++]));
    while (array[i])
    {
        new_node = ft_lstnew(ft_atoi(array[i++]));
        check_for_dup(a, new_node);
        ft_lstadd_back(&a, new_node);
    }
    is_sorted(a, 1);
    index_init(&a);
    ft_free_array(array);
    all_sortings(&a, &b);
    ft_lstclear(&a);
    ft_lstclear(&b);
    return (0);
}