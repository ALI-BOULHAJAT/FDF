/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/19 18:52:03 by aboulhaj         ###   ########.fr       */
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
	m_size->mlx_ptr = mlx_init();
	m_size->win_ptr = mlx_new_window(m_size->mlx_ptr, 1000, 1000, "FDF");
	m_size->zoom = 20;
	//mlx_pixel_put(m_size->mlx_put, m_size->win_put, x, y, z);
	//ft_bresenham(m_size, 10, 10, 600, 300); 
	draw(m_size);
	mlx_key_hook(m_size->win_ptr, mlx_hook, NULL);
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
