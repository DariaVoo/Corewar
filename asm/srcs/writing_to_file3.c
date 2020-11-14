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

void	write_args_to_fd(t_data *data, int ind_instr, int code_op, int fd)
{
	int		i;
	int		size;
	t_arg	*args;
	t_instr *instrs;

	i = 0;
	size = 0;
	instrs = &data->instrs[ind_instr];
	args = data->instrs[ind_instr].args;
	while (i < g_op_tab[code_op - 1].col_args)
	{
		if (args[i].type == T_REG)
			ft_putchar_fd(args[i].value, fd);
		else
		{
			size = size_to_label(data, &args[i], instrs->sum_size \
							- instrs->size, g_op_tab[code_op - 1].tdir_size);
			write_code_dir(size, args[i].type, fd, \
											g_op_tab[code_op - 1].tdir_size);
		}
		i++;
	}
}

void	write_instrs_to_fd(t_data *data, int fd)
{
	int		i;
	int		code_op;

	i = 0;
	code_op = 0;
	while (i < data->instr_num)
	{
		code_op = code_operation(data->instrs[i].name);
		ft_putchar_fd(code_op, fd);
		if (g_op_tab[code_op - 1].bit_type == 1)
			ft_putchar_fd(code_args(data->instrs[i].args), fd);
		write_args_to_fd(data, i, code_op, fd);
		i++;
	}
}
