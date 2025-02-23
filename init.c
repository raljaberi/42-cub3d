/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:57 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/03 12:46:38 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	all_struct_init(t_all *all, t_mlx *mlx, t_ray *ray, t_player *player)
{
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(ray, sizeof(t_ray));
	ft_bzero(player, sizeof(t_player));
	ft_bzero(all, sizeof(t_all));
	player->posx = 0;
	player->posy = 0;
	all->pl = player;
	all->mlx = mlx;
	all->ray = ray;
}

void	direction_part1(t_player *player)
{
	if (player->compass == 3)
	{
		player->dirx = -1;
		player->diry = 0;
		player->plnx = 0;
		player->plny = 0.66;
	}
}

void	init_direction(t_player *player)
{
	direction_part1(player);
	if (player->compass == 2)
	{
		player->dirx = 0;
		player->diry = 1;
		player->plnx = 0.66;
		player->plny = 0;
	}
	else if (player->compass == 1)
	{
		player->dirx = 1;
		player->diry = 0;
		player->plnx = 0;
		player->plny = -0.66;
	}
	else if (player->compass == 0)
	{
		player->dirx = 0;
		player->diry = -1;
		player->plnx = -0.66;
		player->plny = 0;
	}
}

void	init_dist(t_all *all)
{
	if (all->ray->raydirx < 0)
	{
		all->pl->stepx = -1;
		all->ray->sidedistx = (all->pl->posx - \
		all->ray->mapx) * all->ray->deltadistx;
	}
	else
	{
		all->pl->stepx = 1;
		all->ray->sidedistx = (all->ray->mapx + 1.0 - \
		all->pl->posx) * all->ray->deltadistx;
	}
	if (all->ray->raydiry < 0)
	{
		all->pl->stepy = -1;
		all->ray->sidedisty = (all->pl->posy - \
		all->ray->mapy) * all->ray->deltadisty;
	}
	else
	{
		all->pl->stepy = 1;
		all->ray->sidedisty = (all->ray->mapy + 1.0 - \
		all->pl->posy) * all->ray->deltadisty;
	}
}

void	init_drawing(t_all *all, int x)
{
	all->ray->camerax = 2 * (x / (double)WIN_WIDTH) - 1;
	all->ray->raydirx = all->pl->dirx + all->pl->plnx * all->ray->camerax;
	all->ray->raydiry = all->pl->diry + all->pl->plny * all->ray->camerax;
	all->ray->mapx = (int)all->pl->posx;
	all->ray->mapy = (int)all->pl->posy;
	if (all->ray->raydirx == 0)
		all->ray->deltadistx = 1e30;
	else
		all->ray->deltadistx = fabs(1 / all->ray->raydirx);
	if (all->ray->raydiry == 0)
		all->ray->deltadisty = 1e30;
	else
		all->ray->deltadisty = fabs(1 / all->ray->raydiry);
	all->ray->hit = 0;
}
