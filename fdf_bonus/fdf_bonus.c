/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:55:09 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/11 08:47:45 by aboulhaj         ###   ########.fr       */
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
	float i , j;
	m->d_size = 0;
	m->endian = 0;
	m->hieght = 1080;
	m->lenght = 1700;
	m->alpha = 0.523599;
	m->key_i = 0;
	//m->key_j = 0;
	m->z_zoom = 1;
	m->zoom = 7;
	i = (sin(0.523599) * (m->line_num)) + (cos(0.523599) * (m->column_num));
	//i = (0.018276023712653 * ((float)m->line_num * m->zoom)) + (0.999832979530709 * ((float)m->column_num * m->zoom));
	//i = (sin(0.523599) * m->column_num) * m->zoom;
	//j = (sin(0.523599) * m->line_num) * m->zoom;
	//j = cos(90 - 30.000012857);
	//m->key_j = ((1080 - i) * 0.5);
	m->key_j = 300;
	m->key_i = 300;
	//m->key_i = ((1700 - j) / 2);
	//m->key_j = ((1080 - (i * m->zoom)) / 2);
	//printf("%f\n",i);
	//m->key_i = ((m->line_num * m->zoom) / (220 / 170));
	//m->key_j = m->hieght * 0.35;
}

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char	*adr;

	if ((x >= 0 && x < m_size->lenght) && (y >= 0 && y < m_size->hieght))
	{
		adr = m_size->addr + (y * m_size->d_size) + (x * 4);
		*((unsigned int *)adr) = color;
	}
}
int mouse_mov(int x, int y, t_fdf *m)
{
	if (m->key_mo == 1 && m->key_lac != 1)
	{
		m->key_i += (x - m->i_sav);
		m->key_j += (y - m->j_sav);
		m->i_sav = x;
		m->j_sav = y;
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		mlx_destroy_image(m->mlx_ptr, m->image);
		m->image = mlx_new_image(m->mlx_ptr, m->lenght, m->hieght);
		m->addr = mlx_get_data_addr(m->image, &m->bit_img, &m->d_size, &m->endian);
		draw(m);
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
		return (0);
	}
	//printf("%d -- %d \n",x, y);
}
int mouse_pres(int mouse, int x, int y, t_fdf *m)
{
	if (mouse == 1)
	{
		m->key_mo = 1;
		m->key_lac = 0;
		m->i_sav = x;
		m->j_sav = y;
	}
	// if (m->key_lac == 1)
	// 	m->key_mo = 0;
	//printf("%d -- %d -- %d \n",x, y, mouse);
}
int mouse_lach(int mouse, int x, int y, t_fdf *m)
{
	if (mouse == 1)
	{
		m->key_lac = 1;
		m->key_mo = 0;
	}
	// if (m->key_mo == 1)
	// 	m->key_lac = 0;
	//printf("%d -- %d -- %d \n",x, y, mouse);
}

int	main(int ac, char **av)
{
	t_fdf	*m;

	if (ac == 2)
	{
		m = (t_fdf *)malloc(sizeof(t_fdf));
		m->column_num = count_coul(av[1]);
		m->line_num = count_line(av[1]);
	}
	else
		return (0);
	ft_initial_bonus(m);
	ft_alloc(m);
	ft_fdf(av[1], m);
	m->zoom = calc_zoom(MAX_VAL(m->column_num, m->line_num));
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, m->lenght, m->hieght, "FDF");
	m->image = mlx_new_image(m->mlx_ptr, m->lenght, m->hieght);
	m->addr = mlx_get_data_addr(m->image, &m->bit_img, &m->d_size, &m->endian);
	draw(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	mlx_hook(m->win_ptr, 2, 1L << 0, ft_movekey, m);
	//mlx_hook(m->win_ptr, 4, 1L << 0, ft_zoom, m);
	mlx_hook(m->win_ptr, 6, 1L << 0, mouse_mov, m);
	mlx_hook(m->win_ptr, 4, 1L << 0, mouse_pres, m);
	mlx_hook(m->win_ptr, 5, 1L << 0, mouse_lach, m);
	mlx_loop(m->mlx_ptr);
}
