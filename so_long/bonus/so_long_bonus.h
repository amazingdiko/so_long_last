/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 22:34:34 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BUFFER_SIZE 100000
# define WALL "pictures/wall.xpm"
# define FREE "pictures/empty.xpm"
# define COIN "pictures/coin.xpm"
# define PLAYER "pictures/player.xpm"
# define EXIT "pictures/exit.xpm"
# define OPEN_EXIT "pictures/open_exit.xpm"
# define WIN "pictures/win.xpm"
# define LOSE "pictures/lose.xpm"
# define ENEMY "pictures/enemy.xpm"
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
	void	*img_open_exit;
	void	*img_enemy;
	void	*img_win;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	void	*img_free;
	void	*img_lose;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_check{
	int	i;
	int	d;
	int	q;
	int	k;
}	t_check;

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
	int		lose;
	int		count_char;
	int		count_e;
	int		count_c;
	int		count_enemy;
	t_img	*img;
	t_check	*check;
}	t_vars;

char			*get_next_line(int fd);
void			ft_read(int fd, int *ret, char *buf, int x);
int				ft_strlen(const char *s);
char			*ft_substr(char *s, int start, size_t len);
char			**ft_split(char const *s, char c, t_vars *vars);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
int				ft_find(t_vars *vars);
void			ft_img_render(t_vars *vars, int x, int y);
void			ft_inizialization(t_vars *vars);
int				ft_move(int keyhook, t_vars *vars);
int				ft_frame(t_vars *vars);
int				ft_exit(t_vars *vars);
void			ft_free_map(t_vars *vars);
void			ft_check_pictures(t_vars *vars, int x, int y);
void			ft_check_lines(t_vars *vars);
void			ft_check(char *argv_1, t_vars *vars);
void			ft_check_names(t_vars *vars);
void			ft_check_wall_1(t_vars *vars);
void			ft_check_wall_2(t_vars *vars);
void			check_map_name(char *argv_1);
void			ft_print_moves(t_vars *vars);

#endif 