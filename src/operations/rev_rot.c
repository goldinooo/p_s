/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:44:18 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:54:11 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_list **a, int print)
{
	t_list	*last;
	t_list	*tail;

	if (!a || !*a || ft_lstsize(*a) < 2)
		return ;
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	tail = last->next;
	last->next = NULL;
	tail->next = (*a);
	(*a) = tail;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int print)
{
	rra(b, 0);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int print)
{
	rra(a, 0);
	rra(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
