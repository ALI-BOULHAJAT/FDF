/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:58:51 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/20 16:55:10 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	err_line(t_fdf *m_size)
{
	write (2, "Found wrong line length. Exiting.", 33);
	//free(m_size);
	//free(m_size->img);
	system("leaks fdf");
	exit(0);
}

void	err_file(char *file)
{
	write (2, "No file ", 8);
	write (2, file, ft_strlen(file));
	exit(0);
}

void	err_data(void)
{
	write (2, "No data found.", 14);
	exit(0);
}

void	err_argv(void)
{
	write(2, "Usage : ./fdf1 <filename> [ case_size z_size ]", 46);
	exit(0);
}
