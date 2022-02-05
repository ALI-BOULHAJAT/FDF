/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:08:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/05 17:55:58 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

#define MAX_VAL(a, b) (a > b ? a : b)
#define POSIT(a) (a > 0 ? a : -a)

void ft_triD(float *i, float *j, int z, t_fdf *m_size)
{
    m_size->alpha =0.8;
     *i = (*i - *j) * cos(m_size->alpha);
     *j = (*i + *j) * sin(m_size->alpha) - z;
}

void    ft_bresenham(t_fdf *m_size, float i, float j, float i1, float j1)
{
    float di;
    float dj;
    int Val;
    int z;
    int z1;
    int a;
    int b;
    int h = 1;
    int color;

    
    z = m_size->map[(int) j][(int) i].z * 1;
    z1 = m_size->map[(int) j1][(int) i1].z * 1;
    if ((m_size->map[(int)j][(int)i].check) == 1)
        color = m_size->map[(int) j][(int) i].color;
    else
        color = 0xffffff;
    //printf("%d(c) - %d -%d\n", m_size->map[(int)j][(int)i].check, (int)i, (int)j);
    
    //zoom
    i *= m_size->zoom;
    j *= m_size->zoom;
    i1 *= m_size->zoom;
    j1 *= m_size->zoom;
    
    
    m_size->color = (z) ? 0xe80c0c : 0xffffff; 
    
    
    ft_triD(&i, &j, z, m_size);
    ft_triD(&i1, &j1, z1, m_size);
    i += m_size->key_i;
    j += m_size->key_j;
    i1 += m_size->key_i;
    j1 += m_size->key_j;
    
    
    di = i1 - i;
    dj = j1 - j;



    Val = MAX_VAL(POSIT(di), POSIT(dj));
    
    di /= Val;
    dj /= Val;
    //printf("%f - %f\n", di, dj);
    // m_size->map[i1][j1]->color;
    
    while ((int)(i - i1) || (int)(j - j1))
    {
        //m_size->color = (( m_size ) == 1) ? 0xe80c0c : 0xffffff;
        //mlx_pixel_put(m_size->mlx_ptr, m_size->win_ptr, i, j, color);
        my_new_window(i, j, m_size, color);
        i += di;
        j += dj;
        //printf("%d - %d\n", i , j);
    }
    //printf("%d - %d(colon)\n", m_size->line_num, m_size->column_num);
    //printf("%d(j) - %d(i) - %d\n", a, b, m_size->map[a][b].z);
}

void    draw(t_fdf  *m_size)
{
    m_size->i = 0;
    while (m_size->i < m_size->line_num)
    {
        m_size->j = 0;
        while (m_size->j <= m_size->column_num)
        {
            if (m_size->j < m_size->column_num)
                ft_bresenham(m_size, m_size->j, m_size->i, m_size->j + 1, m_size->i); 
            if (m_size->i < m_size->line_num - 1)
                ft_bresenham(m_size, m_size->j, m_size->i, m_size->j, m_size->i + 1);
            m_size->j++;   
        }
        m_size->i++;
    }
    //mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, m_size->key_i, m_size->key_j);
}