/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:07:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/19 15:22:36 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
