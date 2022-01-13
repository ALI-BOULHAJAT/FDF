/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 23:47:05 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_fdf(char *file, t_fdf *m_size)
{
    //int **map;
    int fd;
    
    fd = open(file, O_RDONLY);
    // map = (int **)malloc((m_size.line_num + 1) * sizeof(int *));
    // if (!map)
    //     return NULL;
    // m_size.i = 0;
    // while (m_size.i <= m_size.line_num)
    // {
    //     map[m_size.i] = (int *)malloc(m_size.column_num * sizeof(int));
    //     if (!map[m_size.i])
    //     {
    //         while (m_size.i)
    //         {
    //             free (map[m_size.i]);
    //             m_size.i--;
    //         }
    //         return NULL;
    //     }
    //     m_size.i++;
    // }
    print_map(fd, m_size);
    close(fd);
    //return (m_size.map);
}
int main (int ac, char **av)
{
    int i;
    int j;
    int fd;
    t_fdf   *m_size;
    
    m_size = (t_fdf *)malloc(sizeof(t_fdf));
    i = 0;
    
    m_size->column_num = count_coul(av[1]);
    m_size->line_num = count_line(av[1]);
    ft_alloc(av[1], m_size);
    ft_fdf(av[1],m_size);
    while (m_size->map[i] != NULL)
    {
        j = 0;
        while (j < m_size->column_num)
        {
            printf("%3d", m_size->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}