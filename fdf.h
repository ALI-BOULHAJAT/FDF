/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:24:16 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/11 08:32:53 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define    FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#define MAX_VAL(a, b) (a > b ? a : b)
#define MIN_VAL(a, b) (a > b ? b : a)
#define POSIT(a) (a > 0 ? a : -a)

typedef struct s_data
{
    int z;
    int color;
    int check;
} t_data;

typedef struct s_fdf
{
    t_data **map;
    int line_num;
    int column_num;
    int i;
    int j;
    int i1;
    int j1;
    float zoom;
    int color;
    float z_zoom;
    int key_i;
    int key_j;
    int i_sav;
    int j_sav;
    int key_mo;
    int key_lac;
    float alpha;
    int key;
    int hieght;
    int lenght;
    int how_much;

    void *mlx_ptr;
    void *win_ptr;
    void *image;
    char *addr;
    int bit_img;
    int d_size;
    int endian;
    
}   t_fdf;




int     ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
//char    *get_next_line(int fd);
int     ft_atoi(const char *str);
void    ft_fdf(char *file, t_fdf *m_size);
int     count_word(char const *s, char c);
char	*write_word(char const *s, char c);
char	**ft_freestr(char **tab);
char	**ft_split(char const *s, char c);
int     ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
//char    *get_next_line(int fd);
int     count_coul(char *file);
int	    ft_count_coul(char const *s, char c);
int     count_line(char *file);
void    map_to_mem(int fd, t_fdf *m_size);
char	*ft_strchr(const char *s);
char    *pre_atoi(char *s);
int     check_color(char *s);
void    ft_alloc(t_fdf *m_size);
int     ft_hexanum(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	stock_map(char *s, t_fdf *m_size);
void    draw(t_fdf  *m_size);
void    my_draw(t_fdf *m_size, float i1, float j1);
//void    my_draw(t_fdf *m_size, float i, float j, float i1, float j1);
void	my_new_window(int x, int y, t_fdf *m_size, int color);
float   calc_zoom(int x);
void	ft_mouvment(int key, t_fdf *m_size);
void	ft_retation_x_y(int key, t_fdf *m_size);
void	ft_retation_z(int key, t_fdf *m_size);
void	ft_ckeck_key(int key, t_fdf *m_size);
int     ft_movekey(int key, t_fdf *m);
float	calc_zoom(int x);
int ft_zoom(int mouse, int x, int y, t_fdf *m_size);
void	ft_initial_bonus(t_fdf *m_size);
int     mouse_mov(int x, int y, t_fdf *m);

//void    ft_triD(float *i, float *j, int z);
////////////////////////////////////
// int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
// int	mlx_int_get_good_color();

#endif

