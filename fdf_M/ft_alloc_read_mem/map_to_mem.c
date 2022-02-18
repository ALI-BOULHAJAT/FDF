/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:00:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/18 16:43:28 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	map_to_mem(int fd, t_fdf *m_size)
{
	char	*line;
	char	**spt;
	int		coll;
	int check = 1;

	m_size->i = 0;
	line = get_next_line(fd);
	while (line)
	{
		spt = ft_split(line, ' ');
		m_size->j = 0;
		coll = m_size->column_num;
		while (spt[m_size->j] && (check == 1))
		{
			check = 0;
			if (spt[m_size->j][0] >= '0' && spt[m_size->j][0] <= '9')
			{
				stock_map(spt[m_size->j], m_size);
				m_size->j++;
				coll--;
				check = 1;
			}
		}
		if (m_size->j < m_size->column_num)
		{
			write (2, "Found wrong line length. Exiting.", 33);
			exit(0);
		}
		m_size->i++;
		free (spt);
		free (line);
		line = get_next_line(fd);
	}
	m_size->map[m_size->i] = NULL;
}
