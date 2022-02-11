/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:04:28 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/10 08:29:42 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	*write_word(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr)
	{
		strlcpy(ptr, s, i + 1);
		return (ptr);
	}
	return (NULL);
}

char	**ft_freestr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_str;
	char	**tab;

	if (s)
	{
		num_str = count_word(s, c);
		tab = (char **)malloc(sizeof(char *) * (num_str + 1));
		if (!tab)
			return (NULL);
		i = -1;
		while ((++i) < num_str)
		{
			while (*s == c)
				s++;
			tab[i] = write_word(s, c);
			if (!tab[i])
				return (ft_freestr(tab));
			s = s + ft_strlen(tab[i]);
		}
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}
