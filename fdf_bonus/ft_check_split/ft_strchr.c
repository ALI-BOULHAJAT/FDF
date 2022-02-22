/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:30:24 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 11:24:54 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

char	*ft_strchr(const char *s, char c1, char c2)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (str[i] != c1 && str[i] != c2)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (&str[i + 1]);
}
