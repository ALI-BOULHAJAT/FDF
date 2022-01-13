/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:55:22 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/12 23:04:21 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **print_col_map(int fd, t_fdf m_size, int **map_col)
{
    int **map_col;
    //int fd;
    
    //fd = open(file, O_RDONLY);
    map_col = (int **)malloc((m_size.line_num + 1) * sizeof(int *));
    if (!map_col)
        return NULL;
    m_size.i = 0;
    while (m_size.i <= m_size.line_num)
    {
        map_col[m_size.i] = (int *)malloc(m_size.column_num * sizeof(int));
        if (!map_col[m_size.i])
        {
            while (m_size.i)
            {
                free (map_col[m_size.i]);
                m_size.i--;
            }
            return NULL;
        }
        m_size.i++;
    }
    print_col_map(fd, m_size, map_col);
    return (map_col);
}