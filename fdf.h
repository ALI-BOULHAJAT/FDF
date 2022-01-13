/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:24:16 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 23:01:19 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define    FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_fdf
{
    int **map;
    int line_num;
    int column_num;
    int i;
    int j;
    //int color;
}   t_fdf;


int     ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
int     ft_atoi(const char *str);
void     ft_fdf(char *file, t_fdf *m_size);
int     count_word(char const *s, char c);
char	*write_word(char const *s, char c);
char	**ft_freestr(char **tab);
char	**ft_split(char const *s, char c);
int     ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
int     count_coul(char *file);
int	    ft_count_coul(char const *s, char c);
int     count_line(char *file);
void    print_map(int fd, t_fdf *m_size);
char	*ft_strchr(const char *s);
char    *pre_atoi(char *s);
int     check_color(char *s);
void    ft_alloc(char *file, t_fdf *m_size);

#endif

