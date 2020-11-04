/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:00:36 by rretta            #+#    #+#             */
/*   Updated: 2020/11/04 23:08:37 by rretta           ###   ########.fr       */
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