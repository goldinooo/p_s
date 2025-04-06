/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:44:56 by retahri           #+#    #+#             */
/*   Updated: 2025/04/06 13:21:14 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	inword;

	count = 0;
	inword = 0;
	while (*s)
	{
		if (*s == c)
			inword = 0;
		else if (!inword)
		{
			count += 1;
			inword = 1;
		}
		s++;
	}
	return (count);
}

static char	*split_words(char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	*ft_free(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		len;

	len = count_words(s, c);
	split = malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		split[i] = split_words(s, c);
		if (!split[i])
			return (ft_free(split, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
