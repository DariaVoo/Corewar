/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:00:36 by rretta            #+#    #+#             */
/*   Updated: 2020/11/14 22:25:42 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_cor_extension(char *file, t_data *data)
{
	char	*filename;

	filename = ft_strsub(file, 0, ft_strlen(file) - 2);
	file = ft_strjoin(filename, ".cor");
	ft_strdel(&filename);
	data->file = ft_strdup(file);
	ft_strdel(&file);
}

void	ft_check_filename(char *name)
{
	if (ft_strlen(ft_strstr(name, ".s")) != 2)
		ft_exit("Bad file name\n");
}
