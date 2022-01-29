/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:27 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 20:10:51 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_pictures(t_vars *vars, int x, int y)
{
	vars->count_char = 0;
	vars->count_e = 0;
	vars->count_c = 0;
	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'C')
				vars->count_c += 1;
			if (vars->map[x][y] == 'P')
				vars->count_char += 1;
			if (vars->map[x][y] == 'E')
				vars->count_e += 1;
			y ++;
		}
		x ++;
	}
	if (vars->count_e == 0 || vars->count_e < 1 || vars->count_c == 0
		|| vars->count_char > 1 || vars->count_char == 0)
	{
		printf ("Error! Too much set of chars!\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_check_lines(t_vars *vars)
{
	int	x;
	int	len;

	x = 0;
	len = (int)ft_strlen(vars->map[0]);
	while (vars->map[x])
	{
		if (len != (int)ft_strlen(vars->map[x]))
		{
			printf ("Error! Wrong set lines!\n");
			exit (EXIT_FAILURE);
		}
		x ++;
	}
}

void	ft_check_names(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] != '1' && vars->map[x][y] != '0'
				&& vars->map[x][y] != 'C' && vars->map[x][y] != 'E'
					&& vars->map[x][y] != 'P')
			{
				printf ("Wrong number of charecters!\n");
				exit (EXIT_FAILURE);
			}
			y ++;
		}
		x ++;
	}
}

void	ft_check(char *argv_1, t_vars *vars)
{
	int	x;
	int	y;

	ft_check_pictures(vars, x, y);
	ft_check_lines(vars);
	ft_check_names(vars);
	ft_check_wall_1(vars);
	ft_check_wall_2(vars);
	check_map_name(argv_1);
}
