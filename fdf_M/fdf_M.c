/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_M.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/15 15:01:40 by aboulhaj         ###   ########.fr       */
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

void	ft_initial(t_fdf *m_size)
{
	float j1 , j2, i;
	m_size->img->d_size = 0;
	m_size->img->endian = 0;
	m_size->hieght = 1080;
	m_size->lenght = 1700;
	m_size->alpha = 0.523599;
	if (m_size->z_zoom == 0 || m_size->zoom == 0)
	{
		m_size->z_zoom = 1;
		m_size->zoom = calc_zoom(fmax(m_size->column_num, m_size->line_num));
	}
	m_size->key_i = 700;
	//m_size->key_j = 700;
	//i = (sin(0.523599) * m_size->line_num * m_size->zoom) + 
	j1 = (sin(m_size->alpha) * m_size->column_num);
	j2 = ((m_size->alpha) *  m_size->line_num );
	m_size->key_j = (((float)m_size->hieght - ((j1 + j2) * m_size->zoom))) + ((sin(0.523599) * m_size->column_num * m_size->zoom) * 0.5);
}

void ft_argv(t_fdf *m, int ac,char *av1, char *av2)
{
	if (ac == 4)
	{
		m->zoom = ft_atoi(av1);
		m->z_zoom = ft_atoi(av2);
	}
	else if (ac == 2)
	{
		m->z_zoom = 1;
		m->zoom = calc_zoom(fmax(m->column_num, m->line_num));
	}
	else if (ac > 2)
		{
			ft_printf("Usage : ./fdf1 <filename> [ case_size z_size ]");
			exit (0);
		}
	else
		exit (0);
	
}

int	main(int ac, char **av)
{
	t_fdf	*m;
	int zom;
	int altu;

	m = (t_fdf *)malloc(sizeof(t_fdf));
	m->img = (t_img *)malloc(sizeof(t_img));
	m->column_num = count_coul(av[1]);
	m->line_num = count_line(av[1]);
	ft_alloc(m);
	ft_argv(m, ac, av[2], av[3]);
	ft_initial(m);
	ft_fdf(av[1], m);
	//m->zoom = calc_zoom(fmax(m->column_num, m->line_num));
	m->img->mlx = mlx_init();
	m->img->win = mlx_new_window(m->img->mlx, m->lenght, m->hieght, "FDF");
	drow_to_img(m);
	mlx_hook(m->img->win, 2, 1L << 0, ft_close, m);
	mlx_loop(m->img->mlx);
}
