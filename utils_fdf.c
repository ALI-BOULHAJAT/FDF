/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:57 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/19 15:22:05 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	count_line(char *file)
{
	char	*line;
	int		count_line;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_line++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	ft_count_coul(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

int	count_coul(char *file)
{
	char	*line;
	int		count_coul;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count_coul = ft_count_coul(line, ' ');
	close(fd);
	return (count_coul);
}

void	stock_map(char *s, t_fdf *m_size)
{
	if (check_color(s))
	{
		m_size->map[m_size->i][m_size->j].z = ft_atoi(pre_atoi(s));
		m_size->map[m_size->i][m_size->j].color = ft_hexanum(ft_strchr(s));
		m_size->map[m_size->i][m_size->j].check = 1;
	}
	else
	{
		m_size->map[m_size->i][m_size->j].z = ft_atoi(s);
		m_size->map[m_size->i][m_size->j].check = 0;
	}
}
