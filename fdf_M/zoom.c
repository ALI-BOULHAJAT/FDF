/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:07:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/11 17:51:45 by aboulhaj         ###   ########.fr       */
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
