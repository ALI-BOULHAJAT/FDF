/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:00:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/14 22:07:58 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        print_map(int fd, t_fdf *m_size)
{
    //int fd;
    char *line;
    char **spt;
    
    //m_size->i = 0;

    while ((line = get_next_line(fd)))
    {
        spt = ft_split(line, ' ');
        m_size->j = 0;
        while (spt[m_size->j] != NULL)
        {
            if (check_color(spt[m_size->j]))
            {
                m_size->map[m_size->i][m_size->j].z = ft_atoi(pre_atoi(spt[m_size->j]));
                m_size->map[m_size->i][m_size->j].color = ft_hexanum(ft_strchr(spt[m_size->j]));
                m_size->map[m_size->i][m_size->j].check = 1;
                m_size->j++;
            }
            else
            {
                //printf("%d",ft_atoi(spt[m_size->j]));
                m_size->map[m_size->i][m_size->j].z = ft_atoi(spt[m_size->j]);
                m_size->map[m_size->i][m_size->j].check = 0;
                m_size->j++;
            }
        }
        m_size->i++;
        free (spt);
        free (line);  
    }
    m_size->map[m_size->i] = NULL;
}