/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:27 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 19:14:09 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_pictures(t_vars *vars, int x, int y)
{
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
			if (vars->map[x][y] == 'A')
				vars->count_enemy += 1;
			if (vars->map[x][y] == 'E')
				vars->count_e += 1;
			y ++;
		}
		x ++;
	}
	if (vars->count_enemy == 0 || vars->count_enemy < 1 || vars->count_c == 0
		|| vars->count_char > 1 || vars->count_char == 0 || vars->count_e < 1)
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
					&& vars->map[x][y] != 'P' && vars->map[x][y] != 'A')
			{
				printf ("Wrong number of charecters!\n");
				exit (EXIT_FAILURE);
			}
			y ++;
		}
		x ++;
	}
}

void	check_map_name(char *argv_1)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = ft_strlen(argv_1) - 1;
	k = 4;
	str = malloc(sizeof(char *) * 5);
	if (str == NULL)
		return ;
	while (i < k)
	{
		str[i] = argv_1[j];
		i++;
		j--;
	}
	if (str[3] != '.' || str[2] != 'b' || str[1] != 'e'
		|| str[0] != 'r')
	{
		printf("Error\nWRONG EXT\n");
		exit(EXIT_FAILURE);
	}
	free (str);
}

void	ft_check(char *argv_1, t_vars *vars)
{
	vars->count_char = 0;
	vars->count_enemy = 0;
	vars->count_c = 0;
	ft_check_pictures(vars, 0, 0);
	ft_check_lines(vars);
	ft_check_names(vars);
	ft_check_wall_1(vars);
	ft_check_wall_2(vars);
	check_map_name(argv_1);
}
