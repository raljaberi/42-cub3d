/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:44:58 by raljaber          #+#    #+#             */
/*   Updated: 2025/01/12 11:01:11 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		if (str[j] == NULL)
		{
			while (i >= 0)
			{
				if (str[i] != NULL)
					free(str[i]);
				i--;
			}
			free(str);
			return (NULL);
		}
		j--;
	}
	return (str);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int			i;
	size_t		lettercounter;
	char		**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			lettercounter = 0;
			while (*s && *s != c && ++lettercounter)
				s++;
			split[i] = ft_substr(s - lettercounter, 0, lettercounter);
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (ft_free(split, i - 1));
}
