/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_charecter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/26 20:51:52 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_d(t_vars *vars)
{
	if (vars->map[vars->player_x][vars->player_y + 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y + 1] == '0')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x][vars->player_y + 1] = 'P';
		}
		else if (vars->map[vars->player_x][vars->player_y + 1] == 'C'
			&& vars->count_c --)
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x][vars->player_y + 1] = 'P';
		}
		else if (vars->map[vars->player_x][vars->player_y + 1] == 'E'
			&& vars->count_c == 0)
		{
			vars->ok = 1;
		}
		vars->steps ++;
		vars->player_y ++;
		printf ("Steps: %d\n", vars->steps);
	}
}

void	ft_move_a(t_vars *vars)
{
	if (vars->map[vars->player_x][vars->player_y - 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y - 1] == '0')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x][vars->player_y - 1] = 'P';
		}
		else if (vars->map[vars->player_x][vars->player_y - 1] == 'C'
			&& vars->count_c --)
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x][vars->player_y - 1] = 'P';
		}
		else if (vars->map[vars->player_x][vars->player_y - 1] == 'E'
			&& vars->count_c == 0)
		{
			vars->ok = 1;
		}
		vars->steps ++;
		vars->player_y --;
		printf ("Steps: %d\n", vars->steps);
	}
}

void	ft_move_w(t_vars *vars)
{
	if (vars->map[vars->player_x - 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x - 1][vars->player_y] == '0')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x - 1][vars->player_y] = 'P';
		}
		else if (vars->map[vars->player_x - 1][vars->player_y] == 'C'
			&& vars->count_c --)
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x - 1][vars->player_y] = 'P';
		}
		else if (vars->map[vars->player_x - 1][vars->player_y] == 'E'
			&& vars->count_c == 0)
		{
			vars->ok = 1;
		}
		vars->steps ++;
		vars->player_x--;
		printf ("Steps: %d\n", vars->steps);
	}
}

void	ft_move_s(t_vars *vars)
{
	if (vars->map[vars->player_x + 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x + 1][vars->player_y] == '0')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x + 1][vars->player_y] = 'P';
		}
		else if (vars->map[vars->player_x + 1][vars->player_y] == 'C'
			&& vars->count_c --)
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->map[vars->player_x + 1][vars->player_y] = 'P';
		}
		else if (vars->map[vars->player_x + 1][vars->player_y] == 'E'
			&& vars->count_c == 0)
		{
			vars->ok = 1;
		}
		vars->steps ++;
		vars->player_x++;
		printf ("Steps: %d\n", vars->steps);
	}
}

int	ft_move(int keyhook, t_vars *vars)
{
	if (keyhook == ESC)
		ft_exit(vars);
	else if (keyhook == D)
		ft_move_d(vars);
	else if (keyhook == A)
		ft_move_a(vars);
	else if (keyhook == W)
		ft_move_w(vars);
	else if (keyhook == S)
		ft_move_s(vars);
	return (0);
}
