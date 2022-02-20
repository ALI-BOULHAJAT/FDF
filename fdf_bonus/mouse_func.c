/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:34:28 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/20 13:20:18 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_zoom(int mouse, int x, int y, t_fdf *m)
{
	if (mouse == 1)
	{
		m->key_mouvment = 1;
		m->key_release = 0;
		m->i_sav = x;
		m->j_sav = y;
	}
	if (mouse == 5)
		m->zoom += 1;
	if (mouse == 4)
		m->zoom -= 1;
	mlx_clear_window(m->img->mlx, m->img->win);
	mlx_destroy_image(m->img->mlx, m->img->img);
	drow_to_img(m);
	return (0);
}

int	mouse_mouvment(int x, int y, t_fdf *m)
{
	if (m->key_mouvment == 1 && m->key_release != 1)
	{
		m->key_i += (x - m->i_sav);
		m->key_j += (y - m->j_sav);
		m->i_sav = x;
		m->j_sav = y;
	}
	mlx_clear_window(m->img->mlx, m->img->win);
	mlx_destroy_image(m->img->mlx, m->img->img);
	drow_to_img(m);
	return (0);
}

int	mouse_release(int mouse, int x, int y, t_fdf *m)
{
	if (mouse == 1)
	{
		m->key_release = 1;
		m->key_mouvment = 0;
	}
	return (0);
}
