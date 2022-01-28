/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:27 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/28 22:27:47 by wmozella         ###   ########.fr       */
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
			printf ("Wrong set tree!\n");
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
			printf ("Wrong set tree!\n");
			exit (EXIT_FAILURE);
		}
		x ++;
		y ++;
	}
}

// void	check_map_name(char *argv_1, t_vars *vars)
// {
// 	char	*str;

// 	vars->check->d = 0;
// 	vars->check->k = 0;
// 	vars->check->q = 0;
// 	vars->check->i = ft_strlen(argv_1);
// 	str = malloc(sizeof(char *) * 5);
// 	while (argv_1[vars->check->d])
// 	{
// 		if (argv_1[vars->check->d] == '.')
// 			vars->check->q += 1;
// 		vars->check->d ++;
// 	}
// 	vars->check->d = 0;
// 	while (vars->check->d < 4)
// 	{
// 		str[vars->check->k] = argv_1[vars->check->i - 1];
// 		vars->check->d ++;
// 		vars->check->k --;
// 		vars->check->i --;
// 	}
// 	if (str[0] != '.' && str[1] != 'b' && str[2] != 'e'
// 		&& str[3] != 'r' && vars->check->q != 1)
// 	{
// 		printf("Error! Wrong map name!\n");
// 		exit (EXIT_FAILURE);
// 	}
// 	free(str);
// }

void	check_map_name(char *argv_1, int d, int q, int k)
{
	int i;
	char *str;

	i = ft_strlen(argv_1);
	str = malloc(sizeof(char *) * 5);
	if (str == NULL)
		return ;
	while (argv_1[d])
	{
		if (argv_1[d] == '.')
			q += 1;
		d++;
	}
	d = 0;
	while (d < 4)
	{
		str[k] = argv_1[i - 1];
		d++;
		k--; 
		i--;
	}
	if (str[0] != '.' && str[1] != 'b' && str[2] != 'e' && str[3] != 'r' && q != 1)
		printf("Error\nWrong extension\n"), exit(EXIT_FAILURE);
	free(str);
}