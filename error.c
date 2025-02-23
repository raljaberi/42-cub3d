/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:50:04 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/03 14:00:27 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy_free(t_all *all)
{
	int	i;

	i = -1;
	if (all->mlx->mlx_win)
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	if (all->mlx->tex)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex);
	if (all->mlx->tex2)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex2);
	if (all->mlx->tex3)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex3);
	if (all->mlx->tex4)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex4);
	if (all->mlx->buffer)
		while (++i < WIN_HEIGHT)
			free(all->mlx->buffer[i]);
	free(all->mlx->buffer);
	ft_free_all(all);
	exit(0);
}

void	ft_error(t_all *all, int error)
{
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
	if (error == 2)
		ft_putstr_fd("Invalid map extension!\n", 2);
	else if (error == 3)
		ft_putstr_fd("File reading failed!\n", 2);
	else if (error == 4)
		ft_putstr_fd("Memory allocation failed!\n", 2);
	else if (error == 5)
		ft_putstr_fd("Invalid Map!\n", 2);
	else if (error == 6)
		ft_putstr_fd("Invalid color!\n", 2);
	else if (error == 7)
		ft_putstr_fd("Invalid chars in map!\n", 2);
	else if (error == 8)
		ft_putstr_fd("Unclosed map!\n", 2);
	else if (error == 9)
		ft_putstr_fd("Unclosed map (spaces)!\n", 2);
	ft_destroy_free(all);
}

void	ft_free_all(t_all *all)
{
	if (all->map_file)
		free(all->map_file);
	if (all->mapl)
		free(all->mapl);
	ft_free_arr(all->splmap);
	ft_free_arr(all->textures);
	ft_free_arr(all->colors);
	ft_free_arr(all->map);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
}
