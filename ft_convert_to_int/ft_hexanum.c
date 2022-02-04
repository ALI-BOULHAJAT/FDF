/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexanum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:18 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/03 10:16:14 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_hexanum(char *s)
{
	int	i;
	int	ret;
	int	base;

	i = 0;
	ret = 0;
	base = 1;
	while (s[i])
		i++;
	while (i--)
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			ret += ((s[i] - 87) * base);
		else if (s[i] >= 'A' && s[i] <= 'F')
			ret += ((s[i] - 55) * base);
		else if (s[i] >= '0' && s[i] <= '9')
			ret += (s[i] - 48) * base;
		base *= 16 ;
	}
	return (ret);
}
