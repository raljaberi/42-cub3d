/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doqahtan <doqahtan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:36 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/10 08:35:08 by doqahtan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_map_valid_structure(t_all *all, int *i, size_t *nl)
{
	while (all->mapl[++(*i)] && *nl < 7)
	{
		if (all->mapl[*i] == '\n')
			*i += 1;
		else if (all->mapl[*i] != '\n')
		{
			*nl += 1;
			while (all->mapl[*i] != '\n')
				*i += 1;
		}
	}
}

void	ft_map_valid_char(t_all *all, int i, size_t nl)
{
	ft_map_valid_structure(all, &i, &nl);
	while (all->mapl[i])
	{
		if (all->mapl[i] == '1' || all->mapl[i] == '0' || all->mapl[i] == 'N'
			|| all->mapl[i] == 'S' || all->mapl[i] == 'E' || all->mapl[i] == 'W'
			|| all->mapl[i] == ' ' || all->mapl[i] == '\n')
		{
			check_pos(all->mapl[i], all);
			if (all->mapl[i] == '\n'
				&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
				ft_error(all, 8);
		}
		else
			ft_error(all, 7);
		i++;
	}
}

void	ft_color_parse(t_all *all)
{
	char	*fc;
	char	*cc;

	ft_color_chars_checker(all, 2, 0, 0);
	fc = ft_convert_base(ft_rgb_to_hex(all, all->colors[0], 2), HEX, DEC);
	cc = ft_convert_base(ft_rgb_to_hex(all, all->colors[1], 2), HEX, DEC);
	all->mlx->fcolor = ft_atoi_index(all, fc, 0, 6);
	all->mlx->ccolor = ft_atoi_index(all, cc, 0, 6);
	free(fc);
	free(cc);
}

char	**ft_split_all(char *str, t_all *all)
{
	char	**ret;
	size_t	wordc;
	size_t	i;

	wordc = ft_linecount(str);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		ft_error(all, 4);
	i = 0;
	while (i < wordc)
	{
		ret[i] = extract_line(&str, all);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_find_index(t_all *all, char **arr, char *s, size_t size)
{
	int	i;

	i = 0;
	ft_arr_trim(arr);
	if (!arr)
		ft_error(all, 5);
	while (arr[i] && i < 6)
	{
		if (!ft_strncmp(arr[i], s, size))
			return (i);
		i++;
	}
	ft_error(all, 5);
	return (i);
}
