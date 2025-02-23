/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:32:21 by raljaber          #+#    #+#             */
/*   Updated: 2025/01/12 11:07:33 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copied;
	size_t	len;

	len = ft_strlen(s1);
	copied = malloc(sizeof(char) * (len + 1));
	if (!copied)
		return (NULL);
	ft_strlcpy(copied, s1, len + 1);
	return (copied);
}
