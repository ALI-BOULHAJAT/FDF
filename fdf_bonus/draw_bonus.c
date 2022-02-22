/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:08:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 17:59:26 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_3d(float *i, float *j, int z, t_fdf *m_size)
{
	if (m_size->key == 88 || m_size->key == 86)
		rotate_x(i, &z, m_size);
	else if (m_size->key == 91 || m_size->key == 84)
		rotate_y(j, &z, m_size);
	else if (m_size->key == 6 || m_size->key == 7)
		rotate_z(i, j, m_size);
	if ((m_size->key_3d == 1) && (m_size->key_2d == 0))
	{
		*i = (*i - *j) * cos(0.523599);
		*j = (*i + *j) * sin(0.523599) - z;
	}
}

int	ft_color(t_fdf *m)
{
	int	color;

	if ((m->map[m->i][m->j].check) == 1)
		color = m->map[m->i][m->j].color;
	else
		color = 0xffffff;
	return (color);
}

void	my_draw(t_fdf *m, float i1, float j1)
{
	int		tab_int[3];
	float	tab_flo[4];
	int		color;

	tab_int[1] = m->map[m->i][m->j].z * m->z_zoom;
	tab_int[2] = m->map[(int) j1][(int) i1].z * m->z_zoom;
	tab_flo[2] = (float)m->j;
	tab_flo[3] = (float)m->i;
	color = ft_color(m);
	zoom(m, tab_flo, &i1, &j1);
	ft_3d(&tab_flo[2], &tab_flo[3], tab_int[1], m);
	ft_3d(&i1, &j1, tab_int[2], m);
	tab_flo[0] = i1 - tab_flo[2];
	tab_flo[1] = j1 - tab_flo[3];
	tab_int[0] = fmax(fabs(tab_flo[0]), fabs(tab_flo[1]));
	tab_flo[0] /= tab_int[0];
	tab_flo[1] /= tab_int[0];
	while ((int)(tab_flo[2] - i1) || (int)(tab_flo[3] - j1))
	{
		my_new_window(tab_flo[2] + m->key_i, tab_flo[3] + m->key_j, m, color);
		tab_flo[2] += tab_flo[0];
		tab_flo[3] += tab_flo[1];
	}
}

void	drow_to_img(t_fdf *m)
{
	m->img->img = mlx_new_image(m->img->mlx, m->lenght, m->hieght);
	m->img->addr = mlx_get_data_addr(m->img->img, &m->img->bit_img, \
	&m->img->d_size, &m->img->endian);
	draw(m);
	mlx_put_image_to_window(m->img->mlx, m->img->win, m->img->img, 0, 0);
}

void	draw(t_fdf *m_size)
{
	m_size->i = 0;
	while (m_size->i < m_size->line_num)
	{
		m_size->j = 0;
		while (m_size->j < m_size->column_num)
		{
			if (m_size->j < m_size->column_num - 1)
				my_draw(m_size, m_size->j + 1, m_size->i);
			if (m_size->i < m_size->line_num - 1)
				my_draw(m_size, m_size->j, m_size->i + 1);
			m_size->j++;
		}
		m_size->i++;
	}
}
