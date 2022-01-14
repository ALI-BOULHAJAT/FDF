/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexanum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:18 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/14 17:26:21 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_hexanum(char *s)
{
    int i = 0;
    int ret = 0;
    int base = 1;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'f')
        {
            ret += ((s[i] - 87) * base);
            base *= 16 ;
            i++;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            ret += ((s[i] - 55) * base);
            base *= 16;
            i++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ret += (s[i] - 48) * base;
            base *= 16;
            i++;
        }
    }
    return (ret);
}
