/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/09 15:39:33 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <mlx.h>

// void	my_new_window(int x, int y, t_fdf *m_size, int color)
// {
// 	char *adr;
// 	if((x >= 0 && x < m_size->w) && (y >= 0 && y < m_size->c))
// 	{
// 		adr = m_size->addr + (y * m_size->d_size) + (x * 4);
// 		*((unsigned int *)adr) = color;
// 	}
// }

// /*float calc_zoom(int x)
// {
//     float val;
//     val = 20 - (((float)x - 20) / (180/14));
//     if (val < 0)
//     {
//         val = 20 - (((float)x - 20) / (480/18));
//     }
//     return (val);
// }*/

// void	ft_fdf(char *file, t_fdf *m_size)
// {
// 	int	fd;

// 	fd = open(file, O_RDONLY, 0);
// 	map_to_mem(fd, m_size);
// 	close(fd);
// }


// /*int	ft_movekey(int key, t_fdf *m_size)
// {
// 	if (key == 126)
// 		m_size->key_j -= 10;
// 	if (key == 125)
// 		m_size->key_j += 10;
// 	if (key == 124)
// 		m_size->key_i += 10;
// 	if (key == 123)
// 		m_size->key_i -= 10;
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(m_size->mlx_ptr, m_size->win_ptr);
// 		exit(0);
// 	}
// 	if (key == 69)
// 	{
// 		//m_size->key = 69;
// 		m_size->z_zoom += 2;
// 	}
// 	if (key == 78)
// 	{
// 		//m_size->key = 78;
// 		m_size->z_zoom -= 2;
// 	}
// 	if (key == 88)
// 	{
// 		m_size->key = 88;
// 		m_size->alpha += 0.1;
// 	}
// 	if (key == 86)
// 	{
// 		m_size->key = 86;
// 		m_size->alpha -= 0.1;
// 	}
// 	if (key == 91)
// 	{
// 		m_size->key = 91;
// 		m_size->alpha += 0.1;
// 	}
// 	if (key == 84)
// 	{
// 		m_size->key = 84;
// 		m_size->alpha -= 0.1;
// 	}
// 	if (key == 6)
// 	{
// 		m_size->key = 6;
// 		m_size->alpha += 0.1;
// 	}
// 	if (key == 7)
// 	{
// 		m_size->key = 7;
// 		m_size->alpha -= 0.1;
// 	}*/
	
// 	// mlx_clear_window(m_size->mlx_ptr, m_size->win_ptr);
// 	// mlx_destroy_image(m_size->mlx_ptr, m_size->image);
// 	// m_size->image = mlx_new_image(m_size->mlx_ptr, m_size->w, m_size->c);
// 	// m_size->addr = mlx_get_data_addr(m_size->image, &m_size->bit_img, &m_size->d_size, &m_size->endian);
// 	// draw(m_size);
// 	// mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, 0, 0);
// 	// printf("%d - %d \n", m_size->key_i, m_size->key_j);
// 	// return (0);
// //}



// int	main(int ac, char **av)
// {
	
// 	int h;
// 	//int		i;
// 	int		j;
// 	int i = 0;
// 	int c;
// 	t_fdf	*m_size;

// 	m_size = (t_fdf *)malloc(sizeof(t_fdf));
// 	m_size->column_num = count_coul(av[1]);
// 	m_size->line_num = count_line(av[1]);
// 	m_size->d_size = 0;
// 	m_size->endian = 0;
// 	// printf("%d\n", m_size->column_num);
// 	// printf("%d\n", m_size->line_num);
// 	h = ac;
// 	ft_alloc(m_size);
// 	ft_fdf(av[1], m_size);
// 	// while (i < m_size->line_num)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < m_size->column_num)
// 	// 	{
// 	// 		if ((m_size->map[i][j].check) == 1)
// 	// 			printf("%2d,%d", m_size->map[i][j].z, m_size->map[i][j].color);
// 	// 		else
// 	// 			printf("%3d,%d", m_size->map[i][j].z,m_size->map[i][j].check);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// 	printf("\n");
// 	// }
// 	// return (0);
	
// 	m_size->zoom = calc_zoom(MAX_VAL(m_size->column_num, m_size->line_num));
// 	//m_size->zoom = 6;
// 	printf("%f, %d  -   %d\n", m_size->zoom, m_size->column_num, m_size->line_num);
// 	//m_size->c = (m_size->column_num + (m_size->column_num * 0.25)) * m_size->zoom;
// 	//m_size->w = (m_size->column_num + (m_size->column_num * 1)) * m_size->zoom;
	
// 	m_size->c = 1080;
// 	m_size->w = 1700;
	
// 	//m_size->c = 1000;
// 	//m_size->w = 2000;
// 	printf("%d -- %d\n", m_size->c, m_size->w);
	
// 	m_size->mlx_ptr = mlx_init();
// 	m_size->win_ptr = mlx_new_window(m_size->mlx_ptr, m_size->w, m_size->c, "FDF");
// 	m_size->image = mlx_new_image(m_size->mlx_ptr, m_size->w, m_size->c);
// 	m_size->addr = mlx_get_data_addr(m_size->image, &m_size->bit_img, &m_size->d_size, &m_size->endian);
	
// 	m_size->alpha =0.523599;
// 	m_size->key_i = 0;
// 	m_size->key_j = 0;
// 	m_size->z_zoom = 1;
// 	// m_size->key_i = m_size->w / 2.5;
// 	//m_size->key_j = m_size->c / 3;
// 	m_size->key_i = ((m_size->line_num * m_size->zoom)/(220/170));
// 	m_size->key_j = m_size->c * 0.35;
// 	draw(m_size);
// 	mlx_put_image_to_window(m_size->mlx_ptr, m_size->win_ptr, m_size->image, 0, 0);
// 	mlx_hook(m_size->win_ptr , 2, 1L<<0, ft_movekey, m_size);
// 	//mlx_hook(m_size->win_ptr , 2, 1L<<0, ft_rotation, m_size);
// 	mlx_hook(m_size->win_ptr , 4, 1L<<0, ft_zoom, m_size);
// 	//printf("%d\n", m_size->map[m_size->line_num][0])
// 	mlx_loop(m_size->mlx_ptr);
// }

// 88 > 6 -- 91 > 8  --  86 > 4  -- 84 >> 2