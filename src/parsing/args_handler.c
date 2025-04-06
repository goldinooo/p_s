/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:44:32 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:59:39 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	test_one_arg(char *str, char **array)
{
	int	i;

	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		ft_free_array(array);
		error();
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
	{
		ft_free_array(array);
		error();
	}
	i = 0;
	while (str[++i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			ft_free_array(array);
			error();
		}
	}
	ft_atoi(str);
	ft_free_array(array);
	exit(0);
}

char	**args_handler(int *ac, char **av)
{
	char	**array;
	int		i;

	if (*ac < 2)
		exit(0);
	if (*ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array)
			(ft_free_array(array), exit(1));
		else if (!array[1])
			test_one_arg(array[0], array);
		*ac = ft_array_len(array);
	}
	else
	{
		i = 0;
		array = malloc(sizeof(char *) * (*ac));
		while (++i < *ac)
			array[i - 1] = ft_strdup(av[i]);
		array[i - 1] = NULL;
		(*ac)--;
	}
	return (array);
}

void	check_for_dup(t_list *stack, t_list *node)
{
	t_list	*head;

	head = stack;
	while (head)
	{
		if (head->content == node->content)
			error();
		head = head->next;
	}
}

void	check_ev(char **av, int i, int j)
{
	if (av[i][j] == '-' || av[i][j] == '+')
	{
		if (j == 0 || av[i][j - 1] == ' ')
		{
			if (!av[i][j + 1] || av[i][j + 1] < '0' || av[i][j + 1] > '9')
				error();
			j++;
		}
		else
			error();
	}
	if (!av[i][j] || (av[i][j] != ' ' && (av[i][j] < 48 || av[i][j] > 57)))
		error();
}
