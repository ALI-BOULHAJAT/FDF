/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/05 19:17:54 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <mlx.h>

void	my_new_window(int x, int y, t_fdf *m_size, int color)
{
	char *adr;
	adr = m_size->addr + (y * m_size->d_size) + (x * 4);
	*((unsigned int *)adr) = color;
}

void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	map_to_mem(fd, m_size);
	close(fd);
}

int	ft_rotation(int key, t_fdf *m_size)
{
	//printf("%d\n", key);
	if (key == 37)
	{
		
	}
	return (0);
}

int	ft_movekey(int key, t_fdf *m_size)
{
	if (key == 126)
		m_size->key_j -= 10;
	if (key == 125)
		m_size->key_j += 10;
	if (key == 124)
		m_size->key_i += 10;
	if (key == 123)
		m_size->key_i -= 10;
	//draw(m_size);
	mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
	mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, m_size->key_i, m_size->key_j);
	if (key == 12)
		mlx_destroy_window(m_size->mlx_ptr, m_size->win_ptr);
	return (0);
}

int ft_zoom(int mouse, int x, int y, t_fdf *m_size)
{
	if (mouse == 5)
		m_size->zoom += 15;
	if (mouse == 4)
		m_size->zoom -= 15;
	//mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
	//draw(m_size);
	mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
	mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, m_size->key_i, m_size->key_j);
	//mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	
	int h;
	//int		i;
	int		j;
	int i = 0;
	t_fdf	*m_size;

	m_size = (t_fdf *)malloc(sizeof(t_fdf));
	m_size->column_num = count_coul(av[1]);
	m_size->line_num = count_line(av[1]);
	m_size->d_size = 0;
	m_size->endian = 0;
	// printf("%d\n", m_size->column_num);
	// printf("%d\n", m_size->line_num);
	h = ac;
	ft_alloc(m_size);
	ft_fdf(av[1], m_size);
	// while (i < m_size->line_num)
	// {
	// 	j = 0;
	// 	while (j < m_size->column_num)
	// 	{
	// 		if ((m_size->map[i][j].check) == 1)
	// 			printf("%2d,%d", m_size->map[i][j].z, m_size->map[i][j].color);
	// 		else
	// 			printf("%3d", m_size->map[i][j].z);
	// 		j++;
	// 	}
	// 	i++;
	// 	printf("\n");
	// }
	// return (0);
	
	m_size->mlx_ptr = mlx_init();
	m_size->win_ptr = mlx_new_window(m_size->mlx_ptr, 3500, 3500, "FDF");
	m_size->image = mlx_new_image(m_size->mlx_ptr, 3000, 3000);
	m_size->addr = mlx_get_data_addr(m_size->image, &m_size->bit_img, &m_size->d_size, &m_size->endian);
	m_size->zoom = 2 ;
	m_size->key_i = 700;
	m_size->key_j = 10;
	draw(m_size);
	mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image,100, 100);
	mlx_hook(m_size->win_ptr , 2, 1L<<0, ft_movekey, m_size);
	//mlx_hook(m_size->win_ptr , 2, 1L<<0, ft_rotation, m_size);
	mlx_hook(m_size->win_ptr , 4, 1L<<0, ft_zoom, m_size);
	mlx_loop(m_size->mlx_ptr);
}