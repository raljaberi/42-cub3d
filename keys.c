/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:52 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/03 12:39:25 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_w_s(t_all *all, int keycode)
{
	if (keycode == W)
	{
		if (check_wall_collision(all, 'x'))
			all->pl->posx += all->pl->dirx * all->pl->movespeed;
		if (check_wall_collision(all, 'y'))
			all->pl->posy += all->pl->diry * all->pl->movespeed;
	}
	else if (keycode == S)
	{
		if (all->map[(int)(all->pl->posx - all->pl->dirx
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx -= all->pl->dirx * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
			- all->pl->diry * all->pl->movespeed)] != '1')
			all->pl->posy -= all->pl->diry * all->pl->movespeed;
	}
}

void	key_a_d(t_all *all, int keycode)
{
	if (keycode == A)
	{
		if (all->map[(int)(all->pl->posx - all->pl->diry
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx -= all->pl->diry * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
				+ all->pl->dirx * all->pl->movespeed)] != '1')
			all->pl->posy += all->pl->dirx * all->pl->movespeed;
	}
	else if (keycode == D)
	{
		if (all->map[(int)(all->pl->posx + all->pl->diry
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx += all->pl->diry * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
				- all->pl->dirx * all->pl->movespeed)] != '1')
			all->pl->posy -= all->pl->dirx * all->pl->movespeed;
	}
}

void	key_r_l(t_all *a, int keycode)
{
	double	odx;
	double	opx;

	if (keycode == 124)
	{
		odx = a->pl->dirx;
		opx = a->pl->plnx;
		a->pl->dirx = a->pl->dirx * cos(-a->pl->rt_s)
			- a->pl->diry * sin(-a->pl->rt_s);
		a->pl->diry = odx * sin(-a->pl->rt_s) + a->pl->diry * cos(-a->pl->rt_s);
		a->pl->plnx = a->pl->plnx * cos(-a->pl->rt_s)
			- a->pl->plny * sin(-a->pl->rt_s);
		a->pl->plny = opx * sin(-a->pl->rt_s) + a->pl->plny * cos(-a->pl->rt_s);
	}
	else if (keycode == 123)
	{
		odx = a->pl->dirx;
		opx = a->pl->plnx;
		a->pl->dirx = a->pl->dirx * cos(a->pl->rt_s)
			- a->pl->diry * sin(a->pl->rt_s);
		a->pl->diry = odx * sin(a->pl->rt_s) + a->pl->diry * cos(a->pl->rt_s);
		a->pl->plnx = a->pl->plnx * cos(a->pl->rt_s)
			- a->pl->plny * sin(a->pl->rt_s);
		a->pl->plny = opx * sin(a->pl->rt_s) + a->pl->plny * cos(a->pl->rt_s);
	}
}

int	key(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_destroy_free(all);
	if (keycode == W || keycode == S)
		key_w_s(all, keycode);
	if (keycode == A || keycode == D)
		key_a_d(all, keycode);
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		key_r_l(all, keycode);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	ray_cast(all, all->map);
	return (0);
}
