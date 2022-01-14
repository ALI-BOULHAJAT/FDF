/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:30:24 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/14 17:41:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
char	*ft_strchr(const char *s)
{
	//char	find;
	char	*str;
	int		i;

	//find = (char) c;
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

// int main ()
// {
//     printf("%s", ft_strchr("1,0x810202"));
// }