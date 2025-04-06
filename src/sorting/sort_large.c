/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:20:46 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:55:09 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_chunk_size(t_list *a)
{
	int	size;

	size = ft_lstsize(a);
	if (size > 6 && size <= 100)
		return (size / 6);
	else if (size > 100)
		return (size / 13);
	return (0);
}

static int	should_rev_rotate(t_list *a)
{
	int	i;
	int	first;
	int	second;

	i = 0;
	while (a->next)
	{
		first = a->content;
		second = a->next->content;
		if (first - second == 2 || first - second == 3 || first - second == 4)
			i++;
		a = a->next;
	}
	if ((i >= 50 && ft_lstsize(a) < 100) || i >= 250)
		return (1);
	return (0);
}

static void	push_to_b_by_chunks(t_list **a, t_list **b)
{
	int		chunk_size;
	t_list	*tmp;
	int		i;

	chunk_size = get_chunk_size(*a);
	i = 0;
	while (*a)
	{
		tmp = *a;
		if (tmp->index <= i)
		{
			pb(a, b, 1);
			i++;
		}
		else if (tmp->index <= i + chunk_size)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if (should_rev_rotate(*a))
			rra(a, 1);
		else
			ra(a, 1);
	}
}

static void	push_max_to_a(t_list **a, t_list **b)
{
	int	size;
	int	max;
	int	max_pos;

	size = ft_lstsize(*b);
	while (size)
	{
		max = getmaxval(*b);
		max_pos = getmaxpos(*b, max);
		if (max_pos <= size / 2)
			while (max_pos--)
				rb(b, 1);
		else
			while (max_pos++ < size)
				rrb(b, 1);
		pa(a, b, 1);
		size--;
	}
}

void	all_sortings(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 3 && ft_lstsize(*a) > 1)
		sort_3(a);
	else if ((ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4) && ft_lstsize(*a) > 1)
		sort_5(a, b);
	else if (ft_lstsize(*a) > 5)
	{
		push_to_b_by_chunks(a, b);
		push_max_to_a(a, b);
	}
}
