/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:27 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/26 22:09:49 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_pictures(t_vars *vars)
{
	int	x;
	int	y;

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
	if (vars->count_e == 0 || vars->count_e > 1 || vars->count_c == 0
		|| vars->count_char > 1 || vars->count_char == 0)
		printf ("Error! Too much set of chars!\n"), exit (EXIT_FAILURE);
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

// void	ft_check_wall(t_vars *vars)
// {
// 	int	i;
// 	int	b;
// }

void	ft_check(t_vars *vars)
{
	ft_check_pictures(vars);
	ft_check_lines(vars);
}
