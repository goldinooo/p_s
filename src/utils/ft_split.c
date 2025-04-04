/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:34:23 by hasbayou          #+#    #+#             */
/*   Updated: 2025/03/09 20:13:09 by hasbayou         ###   ########.fr       */
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

char	**ft_split(char	const *s, char c)
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
