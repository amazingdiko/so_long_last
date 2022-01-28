/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:58:22 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/28 20:43:32 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i ++;
	}
	free(vars->map);
}

int	ft_exit(t_vars *vars)
{
	ft_free_map(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_frame(t_vars *vars)
{
	mlx_clear_window (vars->mlx, vars->win);
	ft_find(vars);
	if (vars->ok == 1 && vars->count_c == 0)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_win,
			50, 50);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_vars	vars;

	if (argc == 2)
	{
		vars.mlx = mlx_init();
		vars.fd = open(argv[1], O_RDONLY);
		if (vars.fd < 1)
			exit (EXIT_FAILURE);
		line = get_next_line(vars.fd);
		vars.map = ft_split(line, '\n', &vars);
		ft_check(&vars);
		vars.size = 40;
		vars.win = mlx_new_window(vars.mlx, (vars.size * vars.length),
				(vars.size * vars.width), "wmozella");
		vars.steps = 0;
		ft_inizialization(&vars);
		mlx_hook(vars.win, 02, 0, ft_move, &vars);
		mlx_hook(vars.win, 17, 0, ft_exit, &vars);
		mlx_loop_hook(vars.mlx, ft_frame, &vars);
		mlx_loop(vars.mlx);
	}
}
