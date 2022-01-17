/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/17 10:41:36 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(char *file, t_fdf *m_size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	map_to_mem(fd, m_size);
	close(fd);
}

int	main(int ac, char **av)
{
	int		i;
	t_fdf	*m_size;

	m_size = (t_fdf *)malloc(sizeof(t_fdf));
	m_size->column_num = count_coul(av[1]);
	m_size->line_num = count_line(av[1]);
	i = ac;
	ft_alloc(m_size);
	ft_fdf(av[1], m_size);
	m_size->i = 0;
	while (m_size->i < m_size->line_num)
	{
		m_size->j = 0;
		while (m_size->j < m_size->column_num)
		{
			if ((m_size->map[m_size->i][m_size->j].check) == 1)
				printf("%2d,%d", m_size->map[m_size->i][m_size->j].z, m_size->map[m_size->i][m_size->j].color);
			else
				printf("%3d", m_size->map[m_size->i][m_size->j].z);
			m_size->j++;
		}
		m_size->i++;
		printf("\n");
	}
	return (0);
}
