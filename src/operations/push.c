/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:44:14 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:54:05 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_list **stack_b, t_list **stack_a, int print)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	pa(stack_b, stack_a, 0);
	if (print)
		write(1, "pb\n", 3);
}
