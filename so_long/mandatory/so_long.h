/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 22:39:42 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100000
# define WALL "pictures/wall.xpm"
# define FREE "pictures/empty.xpm"
# define COIN "pictures/coin.xpm"
# define PLAYER "pictures/player.xpm"
# define EXIT "pictures/exit.xpm"
# define WIN "pictures/win.xpm"
# define ESC 53
# define D 2
# define W 13
# define A 0
# define S 1
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data {
	void	*img_win;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	void	*img_free;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		fd;
	int		width;
	int		length;
	int		size;
	int		player_x;
	int		player_y;
	int		steps;
	int		coins;
	int		ok;
	int		count_char;
	int		count_e;
	int		count_c;
	t_img	*img;
}	t_vars;

char			*get_next_line(int fd);
void			ft_read(int fd, int *ret, char *buf, int x);
int				ft_strlen(const char *s);
char			*ft_substr(char *s, int start, size_t len);
char			**ft_split(char const *s, char c, t_vars *vars);
int				ft_find(t_vars *vars);
void			ft_img_render(t_vars *vars, int x, int y);
void			ft_inizialization(t_vars *vars);
int				ft_move(int keyhook, t_vars *vars);
int				ft_frame(t_vars *vars);
int				ft_exit(t_vars *vars);
void			ft_free_map(t_vars *vars);
void			ft_win(t_vars *vars);
void			ft_check_pictures(t_vars *vars, int x, int y);
void			ft_check_lines(t_vars *vars);
void			ft_check(char *argv_1, t_vars *vars);
void			ft_check_names(t_vars *vars);
void			ft_check_wall_1(t_vars *vars);
void			ft_check_wall_2(t_vars *vars);
void			check_map_name(char *argv_1);

#endif 