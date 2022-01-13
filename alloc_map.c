/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:07:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 23:47:33 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_alloc(char *file, t_fdf *m_size)
{
    m_size->map = (int **)malloc((m_size->line_num + 1) * sizeof(int *));
    if (!m_size->map)
        return ;
    m_size->i = 0;
    while (m_size->i < m_size->line_num)
    {
        m_size->map[m_size->i] = (int *)malloc((m_size->column_num) * sizeof(int));
        if (!m_size->map[m_size->i])
        {
            while (m_size->i)
            {
                free (m_size->map[m_size->i]);
                m_size->i--;
            }
            return ;
        }
        m_size->i++;
    }
}