/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:34:28 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/11 07:48:38 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

int	ft_zoom(int mouse, int x, int y, t_fdf *m)
{
	if (mouse == 5)
		m->zoom += 1;
	if (mouse == 4)
		m->zoom -= 1;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_destroy_image(m->mlx_ptr, m->image);
	m->image = mlx_new_image(m->mlx_ptr, m->lenght, m->hieght);
	m->addr = mlx_get_data_addr(m->image, &m->bit_img, &m->d_size, &m->endian);
	draw(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	return (0);
}
