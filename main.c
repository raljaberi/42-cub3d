/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:50:27 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/03 12:45:18 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_all		all;
	t_mlx		mlx;
	t_ray		ray;
	t_player	player;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments!\n", 2);
		ft_putstr_fd("Usage: ./cub3D <map_file_location>.cub\n", 2);
		exit(0);
	}
	all_struct_init(&all, &mlx, &ray, &player);
	ft_get_map(&all, argv[1]);
	all.mlx->mlx = mlx_init();
	all.mlx->mlx_win = mlx_new_window(all.mlx->mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	init_imgs(&all);
	ray_cast(&all, all.map);
	mlx_hook(all.mlx->mlx_win, 2, 1L << 0, key, &all);
	mlx_hook(all.mlx->mlx_win, 17, 1L << 5, ft_destroy_free, &all);
	mlx_loop(all.mlx->mlx);
}
