/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doqahtan <doqahtan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:45:41 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/10 08:37:33 by doqahtan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	extra_imgs(t_all *all)
{
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
}

size_t	ft_linecount(char *str)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
			nb++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (nb);
}

char	*extract_line(char **str, t_all *all)
{
	size_t	x;
	char	*line;

	x = 0;
	while (**str && **str == '\n')
		(*str)++;
	while ((*str)[x] && (*str)[x] != '\n')
		x++;
	line = (char *)malloc(x + 1);
	if (!line)
		ft_error(all, 4);
	x = 0;
	while (**str && **str != '\n')
		line[x++] = *(*str)++;
	line[x] = '\0';
	return (line);
}
