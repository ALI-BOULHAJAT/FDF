/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:45:45 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 11:25:39 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	k;

	i = 0;
	k = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			m = -1;
		i++;
		while (str[i] >= 48 && str[i] <= 57)
			k = (str[i++] - '0') + (k * 10);
		return (k * m);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		k = (str[i++] - '0') + (k * 10);
	}
	return (k);
	return (0);
}
