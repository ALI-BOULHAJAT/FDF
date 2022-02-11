/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_M.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/10 16:10:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char	*adr;

	if ((x >= 0 && x < m_size->lenght) && (y >= 0 && y < m_size->hieght))
	{
		adr = m_size->addr + (y * m_size->d_size) + (x * 4);
		*((unsigned int *)adr) = color;
	}
}

int	ft_close(int key, t_fdf *m_size)
{
	if (key == 53)
	{
		mlx_destroy_window(m_size->mlx_ptr, m_size->win_ptr);
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
	float i;
	m_size->d_size = 0;
	m_size->endian = 0;
	m_size->hieght = 1080;
	m_size->lenght = 1700;
	m_size->alpha = 0.523599;
	m_size->key_i = 700;
	m_size->key_j = 700;
	m_size->z_zoom = 1;
	m_size->zoom = 1;
	i = (sin(90 - 30.000012857) * m_size->line_num) + (cos(90 - 30.000012857) * m_size->column_num);
	m_size->key_j = ((float)1080 - (i * m_size->zoom) / 2);
	//printf("%f")
	//m_size->key_i = ((m_size->line_num * m_size->zoom) / (220 / 170));
	//m_size->key_j = m_size->hieght * 0.35;
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
	ft_initial(m);
	printf("%d   - %d\n", m->key_i, m->key_j);
	ft_alloc(m);
	ft_fdf(av[1], m);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, m->lenght, m->hieght, "FDF");
	m->image = mlx_new_image(m->mlx_ptr, m->lenght, m->hieght);
	m->addr = mlx_get_data_addr(m->image, &m->bit_img, &m->d_size, &m->endian);
	draw(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	mlx_hook(m->win_ptr, 2, 1L << 0, ft_close, m);
	mlx_loop(m->mlx_ptr);
}
