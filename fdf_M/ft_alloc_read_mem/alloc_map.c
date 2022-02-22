/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:07:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 08:33:46 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_alloc(t_fdf *m_size)
{
	int	col;

	col = m_size->column_num;
	m_size->map = (t_data **)malloc((m_size->line_num + 1) * sizeof(t_data *));
	if (!m_size->map)
		return ;
	m_size->i = 0;
	while (m_size->i < m_size->line_num)
	{
		m_size->map[m_size->i] = (t_data *)malloc((col) * sizeof(t_data));
		if (!m_size->map[m_size->i])
		{
			while (m_size->i)
			{
				free (m_size->map[m_size->i]);
				m_size->i--;
			}
			return ;
		}
		m_size->i++;
	}
}

int	if_check(char line0, char line1)
{
	if ((line0 != ' ' && line1 == ' ')
		|| (line0 != ' ' && line1 == '\n'))
		return (1);
	else
		return (0);
}

int	count_coul(char *file)
{
	char	*line;
	int		count_coul;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_file(file);
	if (ft_strstr(file, "fdf"))
		err_data();
	line = get_next_line(fd);
	if (line[0] == '\n')
		err_data();
	i = 0;
	count_coul = 0;
	while (line[i])
	{
		if (if_check(line[i], line[i + 1]))
			count_coul++;
		i++;
	}
	free (line);
	close(fd);
	return (count_coul);
}
