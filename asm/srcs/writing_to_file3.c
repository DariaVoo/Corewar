/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:30:49 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 21:30:56 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_size_fd(long nb, int fd)
{
	int		size;
	int		count;

	size = nb;
	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (7 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex_fd(size, fd);
}

int		writing_to_file(t_data *data, int fd)
{
	sum_size(data);
	write_magic_fd(COREWAR_EXEC_MAGIC, fd);
	write_header_to_file(data->header->prog_name, PROG_NAME_LENGTH + 1, fd, 0);
	write_size_fd(data->file_size, fd);
	write_header_to_file(data->header->comment, COMMENT_LENGTH + 1, fd, 1);
	write_instrs_to_fd(data, fd);
	return (0);
}
