/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 11:27:07 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	map_to_mem(fd, m_size);
	close(fd);
}

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char	*adr;

	if ((x >= 0 && x < m_size->hieght) && (y >= 0 && y < m_size->lenght))
	{
		adr = m_size->img->addr + (y * m_size->img->d_size) + (x * 4);
		*((unsigned int *)adr) = color;
	}
}
