/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:56:20 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 18:04:18 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(float *i, int *z, t_fdf *m_size)
{
	int	previous_i;

	previous_i = *i;
	*i = previous_i * cos(m_size->alpha) + *z * sin(m_size->alpha);
	*z = -previous_i * sin(m_size->alpha) + *z * cos(m_size->alpha);
}

void	rotate_y(float *j, int *z, t_fdf *m_size)
{
	int	previous_j;

	previous_j = *j;
	*j = previous_j * cos(m_size->beta) + *z * sin(m_size->beta);
	*z = -previous_j * sin(m_size->beta) + *z * cos(m_size->beta);
}

void	rotate_z(float *i, float *j, t_fdf *m_size)
{
	int	previous_i;
	int	previous_j;

	previous_i = *i;
	previous_j = *j;
	*i = previous_i * cos(m_size->gamma) - previous_j * sin(m_size->gamma);
	*j = previous_i * sin(m_size->gamma) + previous_j * cos(m_size->gamma);
}

void	ft_retation_x_y(int key, t_fdf *m_size)
{
	if (key == 88)
	{
		m_size->key = 88;
		m_size->alpha += 0.05;
	}
	if (key == 86)
	{
		m_size->key = 86;
		m_size->alpha -= 0.05;
	}
	if (key == 91)
	{
		m_size->key = 91;
		m_size->beta += 0.05;
	}
	if (key == 84)
	{
		m_size->key = 84;
		m_size->beta -= 0.05;
	}
}

void	ft_retation_z(int key, t_fdf *m_size)
{
	if (key == 6)
	{
		m_size->key = 6;
		m_size->gamma += 0.05;
	}
	if (key == 7)
	{
		m_size->key = 7;
		m_size->gamma -= 0.05;
	}
}
