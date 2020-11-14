/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:00:36 by rretta            #+#    #+#             */
/*   Updated: 2020/11/04 18:19:54 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../libft/includes/libftprintf.h"

char	*ft_cor_extension(char *file)
{
	char	*filename;

	filename = ft_strsub(file, 0, ft_strlen(file) - 2);
	file = ft_strjoin(filename, ".cor");
	ft_strdel(&filename);
	return (file);
}

void	ft_check_filename(char *name)
{
	if (ft_strlen(ft_strstr(name, ".s")) != 2)
		ft_exit("Bad file name\n");
}