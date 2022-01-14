/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/14 22:08:40 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_fdf(char *file, t_fdf *m_size)
{
    //int **map;
    int fd;
    
    fd = open(file, O_RDONLY);
    print_map(fd, m_size);
    close(fd);
}
int main ()
{
    int i;
    int j;
    t_fdf   *m_size;
    m_size = (t_fdf *)malloc(sizeof(t_fdf));
    i = 0;
    
    m_size->column_num = count_coul("test_maps/10-2.fdf");
    m_size->line_num = count_line("test_maps/10-2.fdf");
    m_size->i = 0;
    m_size->j = 0;
    
    ft_alloc(m_size);
    m_size->i = 0;
    m_size->j = 0;
    ft_fdf("test_maps/10-2.fdf",m_size);

    m_size->i = 0;
    m_size->j = 0;
    while (m_size->map[i] != NULL)
    {
            j = 0;
            while (j < m_size->column_num)
            {
                if ((m_size->map[m_size->i][m_size->j].check) == 1)
                {
                    printf("%d, %d", m_size->map[m_size->i][m_size->j].z, m_size->map[m_size->i][m_size->j].color);
                    m_size->j++;
                }
                else
                {
                    printf("%3d", m_size->map[m_size->i][m_size->j].z);
                    m_size->j++;
                }
                
                j++;
            }
            printf("\n");
            m_size->i++;
    }
}

// int main (int ac, char **av)
// {
//     int i;
//     int j;
//     int f;
//     t_fdf   *m_size;
//      f = ac;
//     m_size = (t_fdf *)malloc(sizeof(t_fdf));
//     i = 0;
    
//     m_size->column_num = count_coul(av[1]);
//     m_size->line_num = count_line(av[1]);
//     ft_alloc(m_size);
//     ft_fdf(av[1],m_size);

//     if (m_size->color)
//     {
//         while (m_size->map[i] != NULL)
//         {
//             j = 0;
//             while (j < m_size->column_num)
//             {
//                 printf("%d,%d", m_size->map[i][j].z, m_size->map[i][j].color);
//                 j++;
//             }
//             printf("\n");
//             i++;
//         }
//     }
//     else
//     {
//         while (m_size->map[i] != NULL)
//         {
//             j = 0;
//             while (j < m_size->column_num)
//             {
//                 printf("%3d", m_size->map[i][j].z);
//                 j++;
//             }
//             printf("\n");
//             i++;
//         }
//     }
// }