/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:10:17 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/14 21:30:16 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "error.h"
#include "../libft/includes/libftprintf.h"

int		write_header_to_file(char *str, int size, int fd, int f)
{
	int		i;

	i = 0;
	if (f == 1)
		size += 3;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	while (i < size)
	{
		ft_putchar_fd(0x0, fd);
		i++;
	}
	return (0);
}

int		code_operation(char *name)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (name && !ft_strcmp(name, g_op_tab[i].name_oper))
			return (g_op_tab[i].opcode);
		i++;
	}
	return (-1);
}

int		write_code_dir(int args, int type, int fd, int tdir_size)
{
	int		size;
	int8_t	buf;

	if (type == T_DIR)
		size = 4 - 2 * tdir_size;
	else if (type == T_IND)
		size = 2;
	else
		size = 1;
	while (size > 0)
	{
		buf = (args >> ((size - 1) * CHAR_BIT)) & 0xFF;
		ft_putchar_fd(buf, fd);
		size--;
	}
	return (args);
}

int		code_args(t_arg *args)
{
	int		i;
	int		code;

	i = 0;
	code = 0;
	while (i < 3)
	{
		code = code | args[i].type;
		code = code << 2;
		i++;
	}
	return (code);
}

int		size_to_label(t_data *data, t_arg *args, int cur_size, int tdir_size)
{
	int		i;
	int		size;
	t_sort	*lab;
	t_instr *instrs;

	i = 0;
	size = 0;
	lab = NULL;
	instrs = data->instrs;
	while (i < data->instr_num)
	{
		lab = instrs[i].labels;
		while (lab)
		{
			if (lab->label && args->label && ft_strcmp(lab->label, \
															args->label) == 0)
			{
				size = instrs[i].sum_size - instrs[i].size - cur_size;
				return (size);
			}
			lab = lab->next;
		}
		i++;
	}
	return (args->value);
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
