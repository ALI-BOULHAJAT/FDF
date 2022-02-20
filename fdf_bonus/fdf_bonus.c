/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:55:09 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/20 14:26:51 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	map_to_mem(fd, m_size);
	close(fd);
}

void	ft_initial_bonus(t_fdf *m)
{
	m->img->d_size = 0;
	m->img->endian = 0;
	m->hieght = 1080;
	m->lenght = 1700;
	m->alpha = 0.523599;
	m->key_i = 300;
	m->key_j = 300;
	m->z_zoom = 1;
	m->zoom = 7;
}

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char	*adr;

	if ((x >= 0 && x < m_size->lenght) && (y >= 0 && y < m_size->hieght))
	{
		adr = m_size->img->addr + (y * m_size->img->d_size) + (x * 4);
		*((unsigned int *)adr) = color;
	}
}

int	main(int ac, char **av)
{
	t_fdf	*m;

	m = (t_fdf *)malloc(sizeof(t_fdf));
	m->img = (t_img *)malloc(sizeof(t_img));
	m->av = av;
	ft_argv(m, ac);
	ft_alloc(m);
	ft_initial(m);
	ft_fdf(m->av[1], m);
	m->img->mlx = mlx_init();
	m->img->win = mlx_new_window(m->img->mlx, m->lenght, m->hieght, "FDF");
	drow_to_img(m);
	mlx_hook(m->img->win, 2, 1L << 0, ft_movekey, m);
	mlx_hook(m->img->win, 4, 1L << 0, ft_zoom, m);
	mlx_hook(m->img->win, 5, 1L << 0, mouse_release, m);
	mlx_hook(m->img->win, 6, 1L << 0, mouse_mouvment, m);
	mlx_hook(m->img->win, 17, 1L << 0, ft_close_x, m);
	mlx_loop(m->img->mlx);
	return (0);
}
