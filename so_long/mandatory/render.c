/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/26 20:25:27 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inizialization(t_vars *vars)
{
	vars->img = malloc(sizeof(t_img));
	vars->img->img_wall = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img->img_width, &vars->img->img_height);
	vars->img->img_free = mlx_xpm_file_to_image(vars->mlx, FREE,
			&vars->img->img_width, &vars->img->img_height);
	vars->img->img_coin = mlx_xpm_file_to_image(vars->mlx, COIN,
			&vars->img->img_width, &vars->img->img_height);
	vars->img->img_player = mlx_xpm_file_to_image(vars->mlx, PLAYER,
			&vars->img->img_width, &vars->img->img_height);
	vars->img->img_exit = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->img->img_width, &vars->img->img_height);
	vars->img->img_win = mlx_xpm_file_to_image(vars->mlx, WIN,
			&vars->img->img_width, &vars->img->img_height);
}

void	ft_img_render(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_wall,
			y * vars->size, x * vars->size);
	else if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_free,
			y * vars->size, x * vars->size);
	else if (vars->map[x][y] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_player,
			y * vars->size, x * vars->size);
		vars->player_x = x;
		vars->player_y = y;
	}
	else if (vars->map[x][y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_coin,
			y * vars->size, x * vars->size);
	else if (vars->map[x][y] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_exit,
			y * vars->size, x * vars->size);
}

int	ft_find(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			ft_img_render(vars, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
