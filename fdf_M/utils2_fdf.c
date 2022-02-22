/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:07:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 19:05:04 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calc_zoom(int x)
{
	float	val;

	val = 20 - (((float)x - 20) / (180 / 14));
	if (val < 0)
	{
		val = 20 - (((float)x - 20) / (480 / 18));
	}
	return (val);
}

void	zoom(t_fdf *m, float *tab_flo, float *i1, float *j1)
{
	tab_flo[2] *= m->zoom;
	tab_flo[3] *= m->zoom;
	*i1 *= m->zoom;
	*j1 *= m->zoom;
}

void	ft_initial(t_fdf *m)
{
	float	p1;
	float	p2;
	float	zoom;

	m->img->d_size = 0;
	m->img->endian = 0;
	m->alpha = 0.523599;
	if (m->z_zoom == 0 || m->zoom == 0)
	{
		m->z_zoom = 1;
		m->zoom = calc_zoom(fmax(m->column_num, m->line_num));
	}
	zoom = m->zoom;
	m->hieght = (m->line_num * zoom) * 2;
	m->lenght = (m->column_num * zoom) * 2;
	p1 = (sin(m->alpha) * m->column_num);
	p2 = (cos(m->alpha) * m->line_num);
	m->key_j = (((float)m->hieght - ((p1 + p2) / zoom)) / 2);
	p1 = (cos(m->alpha) * m->column_num);
	p2 = (sin(m->alpha) * m->line_num);
	m->key_i = (((float)m->lenght - ((p1 + p2) / zoom)) / 2) + (p2 / zoom);
}

void	ft_argv(t_fdf *m, int ac)
{
	if (ac == 4 || ac == 2)
	{
		m->column_num = count_coul(m->av[1]);
		m->line_num = count_line(m->av[1]);
		if (ac == 4)
		{
			m->zoom = ft_atoi(m->av[2]);
			m->z_zoom = ft_atoi(m->av[3]);
		}
		else
		{
			m->z_zoom = 1;
			m->zoom = calc_zoom(fmax(m->column_num, m->line_num));
		}
	}
	else
		err_argv();
}

int	ft_close_x(t_fdf *m_size)
{
	mlx_destroy_window(m_size->img->mlx, m_size->img->win);
	exit(0);
	return (0);
}
