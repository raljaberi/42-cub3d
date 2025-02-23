/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:27:00 by raljaber          #+#    #+#             */
/*   Updated: 2025/01/12 11:08:49 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_to_char(int size, int i, int n, char *result)
{
	while (size > i)
	{
		result[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	size = ft_get_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		result[0] = '-';
		i = 1;
		n = -n;
	}
	ft_to_char(size, i, n, result);
	result[size] = '\0';
	return (result);
}
