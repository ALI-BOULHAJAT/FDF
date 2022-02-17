/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_M.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/17 16:36:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char	*adr;

	if ((x >= 0 && x < m_size->lenght) && (y >= 0 && y < m_size->hieght))
	{
		adr = m_size->img->addr + (y * m_size->img->d_size) + (x * 4);
		*((unsigned int *)adr) = color;
	}
}

int	ft_close(int key, t_fdf *m_size)
{
	if (key == 53)
	{
		mlx_destroy_window(m_size->img->mlx, m_size->img->win);
		exit(0);
	}
	return (0);
}

void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	map_to_mem(fd, m_size);
	close(fd);
}

int	main(int ac, char **av)
{
	t_fdf	*m;
	int		zom;
	int		altu;

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
	mlx_hook(m->img->win, 2, 1L << 0, ft_close, m);
	mlx_loop(m->img->mlx);
}
