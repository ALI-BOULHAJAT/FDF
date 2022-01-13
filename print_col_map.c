/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:05:03 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 17:55:32 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_col_map(int fd, t_fdf m_size, int **map)
{
    //int fd;
    char *line;
    char **spt;
    int k;
    
    m_size.i = 0;

    while ((line = get_next_line(fd)))
    {
        spt = ft_split(line, ' ');
        m_size.j = 0;
        while (spt[m_size.j] != NULL)
        {
            map[m_size.i][m_size.j] = ft_atoi(ft_strchr(spt[m_size.j]));
            m_size.j++;
        }
        m_size.i++;   
    }
    map[m_size.i] = NULL;
}