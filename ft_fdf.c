/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/02 20:50:37 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <mlx.h>


void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	map_to_mem(fd, m_size);
	close(fd);
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
	else
		key = 0;
	//m_size->zom = key;
	// else
	// {
	// 	m_size->key_i = 50;
	// 	m_size->key_j = 50;
	// }
	//printf("%d\n", m_size->key_j);
	draw(m_size);
	mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
	return (key);
}

// int ft_zoom(int mouse, t_fdf *m_size)
// {
	
// 	int i = 0;
// 	// zoom = 0;
// 	//*(m_size->zoom) = i;
// 	if (mouse == 5)
// 		m_size->zoom += 15;
// 		//m_size->zom += 5;
// 		//m_size->zoom = 50;
// 	//*(m_size->zoom) = i;
// 	// if (mouse == 4)
// 	// 	m_size->zoom -= 50;
// 	printf("%d\n",mouse);
// 	draw(m_size);
// 	mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
// 	return (0);
// }

// int ft_zoom(int mouse, float zom)
// {
	
// 	int i = 0;
// 	// zoom = 0;
// 	//*(m_size->zoom) = i;
// 	if (mouse == 5)
// 		zom += 15;
// 		//m_size->zom += 5;
// 		//m_size->zoom = 50;
// 	//*(m_size->zoom) = i;
// 	// if (mouse == 4)
// 	// 	m_size->zoom -= 50;
// 	printf("%f\n",zom);
// 	//draw(m_size);
// 	//mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
// 	return (0);
// }

int	main(int ac, char **av)
{
	
	int h;
	//int		i;
	//int		j;
	t_fdf	*m_size;

	m_size = (t_fdf *)malloc(sizeof(t_fdf));
	m_size->column_num = count_coul(av[1]);
	m_size->line_num = count_line(av[1]);
	h = ac;
	ft_alloc(m_size);
	ft_fdf(av[1], m_size);
	printf("%d--i\n", m_size->i1);
	///////printf("%d--j\n", m_size->j);
	m_size->mlx_ptr = mlx_init();
	m_size->win_ptr = mlx_new_window(m_size->mlx_ptr, 1000, 1000, "FDF");
	m_size->zoom = 20 ;
	//m_size->zom = {20};
	//mlx_pixel_put(m_size->mlx_put, m_size->win_put, x, y, z);
	//ft_bresenham(m_size, 10, 10, 600, 300); 
	m_size->key_i = 200;
	m_size->key_j = 200;
	draw(m_size);
	//mlx_mouse_hook(m_size->win_ptr, ft_zoom, &m_size->zom);
	mlx_key_hook(m_size->win_ptr, ft_movekey, m_size);
	// if (()
	// {
	// 	draw(m_size);
	// 	mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
	// }
	mlx_loop(m_size->mlx_ptr);
}
	
	// i = 0;
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
//}
