/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:57 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/18 18:52:31 by aboulhaj         ###   ########.fr       */
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

int	count_coul(char *file)
{
	char	*line;
	int		count_coul;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (2, "No file ", 8);
		write (2, file, ft_strlen(file));
		exit(0);
	}
	line = get_next_line(fd);
	if ((line[0] == '\0') || (line[0] == '\n'))
	{
		write (2, "No data found.", 14);
		exit(0);
	}
	i = 0;
	count_coul = 0;
	while (line[i])
	{
		if ((line[i] != ' ' && line[i + 1] == ' ')
			|| (line[i] != ' ' && line[i + 1] == '\n'))
			count_coul++;
		i++;
	}
	close(fd);
	return (count_coul);
}

void	stock_map(char *s, t_fdf *m_size)
{
	//printf("%d\n", s[0]);
	// if (s[0] >= '0' && s[0] <= '9')
	// {
		if (check_color(s))
		{
			m_size->map[m_size->i][m_size->j].check = 1;
			m_size->map[m_size->i][m_size->j].z = ft_atoi(pre_atoi(s));
			m_size->map[m_size->i][m_size->j].color = ft_hexanum(ft_strchr(s));
		}
		else
		{
			m_size->map[m_size->i][m_size->j].check = 0;
			m_size->map[m_size->i][m_size->j].z = ft_atoi(s);
			//printf("%d\n", m_size->map[m_size->i][m_size->j].z);
		}
// 	}
// 	else
// 	{
// 		write (2, "No file ", 8);
// 		exit(0);
// 	}
}
