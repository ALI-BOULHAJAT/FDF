/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:24:16 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:44 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define    FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "printf/ft_printf.h"

typedef struct s_data
{
	int	z;
	int	color;
	int	check;
}	t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bit_img;
	int		d_size;
	int		endian;
	void	*mlx;
	void	*win;
}	t_img;

typedef struct s_fdf
{
	t_data	**map;
	t_img	*img;
	int		line_num;
	int		column_num;
	int		i;
	int		j;
	int		i1;
	int		j1;
	float	zoom;
	float	z_zoom;
	int		key_i;
	int		key_j;
	int		i_sav;
	int		j_sav;
	int		key_mouvment;
	int		key_release;
	float	alpha;
	int		key;
	int		hieght;
	int		lenght;
}	t_fdf;

///////Mandatory part ///////

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s);
//void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
int		ft_hexanum(char *s);
char	*pre_atoi(char *s);
int		ft_atoi(const char *str);
int		check_color(char *s);
int		count_word(char const *s, char c);
int		count_coul(char *file);
int		count_line(char *file);
char	*write_word(char const *s, char c);
void	ft_alloc(t_fdf *m_size);
void	map_to_mem(int fd, t_fdf *m_size);
void	stock_map(char *s, t_fdf *m_size);
char	**ft_freestr(char **tab);
void	ft_fdf(char *file, t_fdf *m_size);
void	draw(t_fdf *m_size);
void	my_draw(t_fdf *m_size, float i1, float j1);
void	my_new_window(int x, int y, t_fdf *m_size, int color);
float	calc_zoom(int x);
void	drow_to_img(t_fdf *m);
void	zoom(t_fdf *m, float *tab_flo, float *i1, float *j1);

///////Bonus part ///////
void	ft_ckeck_key(int key, t_fdf *m_size);
int		ft_movekey(int key, t_fdf *m);
void	ft_mouvment(int key, t_fdf *m_size);
int		mouse_mouvment(int x, int y, t_fdf *m);
int		mouse_release(int mouse, int x, int y, t_fdf *m);
void	ft_retation_x_y(int key, t_fdf *m_size);
void	ft_retation_z(int key, t_fdf *m_size);
int		ft_zoom(int mouse, int x, int y, t_fdf *m_size);

#endif