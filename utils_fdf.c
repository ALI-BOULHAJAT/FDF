/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:57 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/13 23:46:57 by aboulhaj         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		l_s[2];
	int		j;
	char	*str;

	if (s1 && s2)
	{
		l_s[0] = ft_strlen((char *)s1);
		l_s[1] = ft_strlen((char *)s2);
		str = (char *)malloc ((l_s[0] + l_s[1] + 1) * sizeof(char));
		if (!str)
		{
			free (s1);
			return (0);
		}
		j = 0;
		if ((l_s[1] + l_s[0]))
		{
			while (*s1 && l_s[0] && l_s[0]--)
				str[j++] = (char )*s1++;
			while ((*s2 && l_s[0] == 0) && l_s[1]--)
				str[j++] = (char )*s2++;
		}
		return (str[j] = 0, str);
	}
	return (0);
}

char	*re_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = strdup("");
	str = ft_strjoin(s1, s2);
	free (s1);
	return (str);
}

char *get_next_line(int fd)
{
    int i = 0;
    int var = 1;
    char *buf;
    char *retr = NULL;
    if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
    while (var)
    {
        buf = (char *)malloc(1);
        i = read(fd, buf, 1);
        if (i == 0)
        {
            free (buf);
            break;
        }
        if (buf[0] == '\n')
            var = 0;
        retr = re_strjoin(retr, buf);
        free(buf);
    }
    return(retr);
}

int count_line(char *file)
{
	char 	*line;
	int		count_line;
	int fd;
	
	fd = open(file, O_RDONLY);
	count_line = 0;
	while ((line = get_next_line(fd)))
	{
		count_line++;
		free (line);	
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

int count_coul(char *file)
{
	char *line;
	int count_coul;
	int fd;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count_coul = ft_count_coul(line, ' ');
	//printf("%d\n",count_coul);
	close(fd);
	return (count_coul);
}

// int main (int ac, char **av)
// {
// 	int fd;
// 	fd = open(av[1], O_RDONLY);
// 	printf("%d", count_coul(fd));
// }