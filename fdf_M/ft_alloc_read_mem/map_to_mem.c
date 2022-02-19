/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:00:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/19 14:31:42 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	pre_stock(t_fdf *m_size, char *str, int coll)
{
	int	check;

	check = 0;
	if (str[0] >= '0' && str[0] <= '9')
	{
		stock_map(str, m_size);
		m_size->j++;
		coll--;
		check = 1;
	}
	return (check);
}

void	map_to_mem(int fd, t_fdf *m_size)
{
	char	*line;
	char	**spt;
	int		coll;
	int		check;

	m_size->i = 0;
	check = 1;
	line = get_next_line(fd);
	while (line)
	{
		spt = ft_split(line, ' ');
		m_size->j = 0;
		coll = m_size->column_num;
		while (spt[m_size->j] && (check == 1) && coll)
			check = pre_stock(m_size, spt[m_size->j], coll);
		if (m_size->j < m_size->column_num)
			err_line();
		m_size->i++;
		free (spt);
		free (line);
		line = get_next_line(fd);
	}
	m_size->map[m_size->i] = NULL;
}
