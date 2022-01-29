/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:27 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 22:15:01 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_wall_1(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < vars->length)
	{
		if (vars->map[0][y] != '1' || vars->map[vars->width - 1][y] != '1')
		{
			printf ("Error!\nWrong set tree!\n");
			exit (EXIT_FAILURE);
		}
		y ++;
		x ++;
	}
}

void	ft_check_wall_2(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < vars->width)
	{
		if (vars->map[x][0] != '1' || vars->map[x][vars->length - 1] != '1')
		{
			printf ("Error!\nWrong set tree!\n");
			exit (EXIT_FAILURE);
		}
		x ++;
		y ++;
	}
}
