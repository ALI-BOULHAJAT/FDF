/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:51:51 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 20:56:42 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **ft_fdf(char *file, t_fdf m_size)
{
    int **map;
    int fd;
    
    fd = open(file, O_RDONLY);
    map = (int **)malloc((m_size.line_num + 1) * sizeof(int *));
    if (!map)
        return NULL;
    m_size.i = 0;
    while (m_size.i <= m_size.line_num)
    {
        map[m_size.i] = (int *)malloc(m_size.column_num * sizeof(int));
        if (!map[m_size.i])
        {
            while (m_size.i)
            {
                free (map[m_size.i]);
                m_size.i--;
            }
            return NULL;
        }
        m_size.i++;
    }