/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:58:51 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 17:59:55 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	err_line(t_fdf *m_size)
{
	write (2, "Found wrong line length. Exiting.", 33);
	exit(1);
}

void	err_file(char *file)
{
	write (2, "No file ", 8);
	write (2, file, ft_strlen(file));
	exit(1);
}

void	err_data(void)
{
	write (2, "No data found.", 14);
	exit(1);
}

void	err_argv(void)
{
	write(2, "Usage : ./fdf1 <filename> [ case_size z_size ]", 46);
	exit(1);
}
