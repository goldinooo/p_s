/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:45:42 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 14:00:34 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	getmaxpos(t_list *stack, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	getmaxval(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	getindex(t_list **a, int index)
{
	t_list	*copy;
	int		i;

	i = 0;
	copy = *a;
	while (copy)
	{
		if (copy->index == index)
			break ;
		i++;
		copy = copy->next;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*copy;
	t_list	*next;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		next = copy->next;
		free(copy);
		copy = next;
	}
	*lst = NULL;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
