/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:28:23 by wmozella          #+#    #+#             */
/*   Updated: 2022/01/29 20:17:52 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	b;
	size_t	nb;
	size_t	j;
	char	*str;

	b = 0;
	nb = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[nb++] = s1[j++];
	while (s2[b] != '\0')
		str[nb++] = s2[b++];
	str[nb] = '\0';
	return (str);
}

static char	*ft_result(int nb, int negative, char	*str)
{
	int	i;

	i = 0;
	while (nb / 10 * negative > 0)
	{
		str[i] = nb % 10 * negative + '0';
		nb = nb / 10;
		i ++;
	}
	str[i] = nb % 10 * negative + '0';
	if (negative == -1)
	{
		i ++;
		str[i] = '-';
	}
	str[i + 1] = '\0';
	return (str);
}

static char	*return_string(char *str)
{
	int		i;
	char	buffer;
	int		size_str;

	size_str = ft_strlen(str) - 1;
	i = 0;
	while (i <= size_str)
	{
		buffer = str[i];
		str[i] = str[size_str];
		str[size_str] = buffer;
		i ++;
		size_str --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			negative;
	long long	nb;
	int			count;

	nb = (long long)n;
	negative = 1;
	count = 1;
	if (0 > n)
	{
		count ++;
		negative = -1;
	}
	while ((nb / 10) * negative != 0)
	{
		nb = nb / 10;
		count ++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str = ft_result(n, negative, str);
	str = return_string(str);
	return (str);
}

void	ft_print_moves(t_vars *vars)
{
	char	*step;
	char	*all_steps;

	step = ft_itoa(vars->steps);
	all_steps = ft_strjoin("Moves: ", step);
	mlx_string_put(vars->mlx, vars->win, 0,
		(vars->width - 2) * 40 + 10, 0xFFFFFF, all_steps);
	free (step);
	free (all_steps);
}
