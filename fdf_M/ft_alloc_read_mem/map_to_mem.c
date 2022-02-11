/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:00:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/10 08:29:29 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	map_to_mem(int fd, t_fdf *m_size)
{
	char	*line;
	char	**spt;

	m_size->i = 0;
	line = get_next_line(fd);
	while (line)
	{
		spt = ft_split(line, ' ');
		m_size->j = 0;
		while (spt[m_size->j] != NULL)
		{
			stock_map(spt[m_size->j], m_size);
			m_size->j++;
		}
		m_size->i++;
		free (spt);
		free (line);
		line = get_next_line(fd);
	}
	m_size->map[m_size->i] = NULL;
}
