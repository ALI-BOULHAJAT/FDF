/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:30:24 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/16 19:12:01 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_strchr(const char *s)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (str[i] != 'x')
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (&str[i + 1]);
}
