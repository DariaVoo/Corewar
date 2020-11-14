/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:29:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 21:30:47 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	sum_size(t_data *data)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	data->instrs[0].sum_size = 0;
	while (i < data->instr_num)
	{
		sum = data->instrs[i].size + sum;
		data->instrs[i].sum_size = sum;
		i++;
	}
	data->file_size = sum;
}

void	write_hex_fd(long nbr, int fd)
{
	if (nbr >= 256)
	{
		write_hex_fd(nbr / 256, fd);
		write_hex_fd(nbr % 256, fd);
	}
	else
		ft_putchar_fd(nbr, fd);
}

void	write_magic_fd(long nb, int fd)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (4 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex_fd(COREWAR_EXEC_MAGIC, fd);
}
