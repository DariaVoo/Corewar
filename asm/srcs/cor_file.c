/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_cor_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:00:36 by rretta            #+#    #+#             */
/*   Updated: 2020/11/12 22:04:59 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../libft/includes/libftprintf.h"

void	ft_check_filename(char *name)
{
	if (ft_strlen(ft_strstr(name, ".s")) != 2)
		ft_exit("Bad file name\n");
	else
		ft_printf("File: %s\n", name);
}

char	*ft_cor_extension(char *file)
{
	char	*filename;

	filename = ft_strsub(file, 0, ft_strlen(file) - 2);
	file = ft_strjoin(filename, ".cor");
	ft_strdel(&filename);
	return (file);
}