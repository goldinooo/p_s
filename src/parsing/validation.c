/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:44:38 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:21:44 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	index_init(t_list **a)
{
	t_list	*high;
	t_list	*low;

	if (!a || !*a)
		error();
	high = *a;
	while (high)
	{
		high->index = 0;
		low = *a;
		while (low)
		{
			if (high->content > low->content)
				high->index++;
			low = low->next;
		}
		high = high->next;
	}
}

void	is_sorted(t_list *a, int print)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return ;
		a = a->next;
	}
	if (print == 1)
	{
		write(1, "sorted\n", 6);
		exit(0);
	}
	else if (print == 2)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
}
