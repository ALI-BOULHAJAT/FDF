/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:57 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 11:27:13 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	ft_stock(t_fdf *m_size, char *s, int check)
{
	m_size->map[m_size->i][m_size->j].check = check;
	m_size->map[m_size->i][m_size->j].z = ft_atoi(s);
}

void	stock_map(char *s, t_fdf *m_size)
{
	char	*str;

	str = pre_atoi(s);
	if (check_color(s) == 1)
	{
		ft_stock(m_size, str, 1);
		m_size->map[m_size->i][m_size->j].color = \
		ft_hexanum(ft_strchr(s, 'x', 'X'));
	}
	else if (check_color(s) == 2)
	{
		ft_stock(m_size, str, 1);
		m_size->map[m_size->i][m_size->j].color = \
		ft_atoi(ft_strchr(s, ',', ','));
	}
	else if (check_color(s) == 3)
	{
		ft_stock(m_size, str, 1);
		m_size->map[m_size->i][m_size->j].color = 0;
	}
	else
		ft_stock(m_size, s, 0);
	free (str);
}

int	ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	b;
	int	size;

	i = 0;
	while (haystack[i])
	{
		b = 0;
		if (haystack[i] == needle[b])
		{
			while (haystack[i + b] == needle[b])
			{
				b++;
				if (needle[b] == '\0' )
					return (0);
			}
		}
		i++;
	}
	return (1);
}
