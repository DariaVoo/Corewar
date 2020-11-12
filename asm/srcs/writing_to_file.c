/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:10:17 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/04 20:10:22 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "../libft/includes/libftprintf.h"

void	sum_size(t_data *data)
{
	int 	i;
	int 	sum;

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

void	write_size_fd(long nb, int fd)
{
	int 	size;
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
/*
 * вывод хедера/ если флаг ф == 1 - это коммент
 */
int 	writing_header_to_file(char *str, int size, int fd, int f)
{
	int		i;

	i = 0;
	while (str[i] != '\0') {
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
		if (!ft_strcmp(name, g_op_tab[i].name_oper))
			return (g_op_tab[i].opcode);
		i++;
	}
	return (-1);
}

int 	write_code_dir(int args, int f, int fd)
{
	int 	size;
	int		count;

	size = args;
	count = 0;
	while (size != 0)
	{
		size = size / 256;
		count++;
	}
	while (f - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	ft_putchar_fd(args, fd);
	return (args);
}

int 	code_args(t_arg *args)
{
	int		i;
	int 	code;

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
//		ft_printf(RED"______ERROR______, %d\n"EOC, instr_num);

int 	size_to_label(t_instr *instrs, char *label, int instr_num, int arg, int *f)
{
	int 	i;

	i = 0;
	while (i < instr_num)
	{
		if (instrs[i].label && label && ft_strcmp(instrs[i].label, label) == 0) {
			ft_printf(GREEN"%s %i | SIZE %d\n"EOC, instrs[i].label, i, instrs[i - 1].sum_size);
			return (instrs[i - 1].sum_size);
		}
		i++;
	}
	*f = -1;
	return (arg);
}

void 	writing_args_to_fd(t_data *data, int ind_instr, int code_op, int fd)
{
	int		i;
	int		sz_dir;
	int		size;
	int 	f;
	t_arg	*args;

	i = 0;
	f = 0;
	sz_dir = 2;
	size = 0;
	args = data->instrs[ind_instr].args;
	while (i < 3)
	{
		if (args[i].type == T_REG)
			ft_putchar_fd(args[i].value, fd);
		else if (args[i].type == T_DIR)
		{
			if (g_op_tab[code_op -1].tdir_size == 0)
				sz_dir = 3;
			size = size_to_label(data->instrs, args[i].label, data->instr_num, args[i].value, &f);
			if (size < data->instrs[ind_instr].sum_size && f != -1)
				size = size - data->instrs[ind_instr].sum_size;
			write_code_dir(size, sz_dir, fd);
		}
		i++;
	}
}

void 	writing_instrs_to_fd(t_data *data, int fd)
{
	int 	i;
	int		code_op;

	i = 0;
	code_op = 0;
	while (i < data->instr_num) //i < data->instr_num
	{
		code_op = code_operation(data->instrs[i].name);
		ft_putchar_fd(code_op, fd);
		if (g_op_tab[code_op - 1].bit_type == 1)
			ft_putchar_fd(code_args(data->instrs[i].args), fd);
		writing_args_to_fd(data, i, code_op, fd);
		i++;
	}

}

int 	writing_to_file(t_data *data, int fd)
{
	sum_size(data);
	int i = 0;
	ft_printf(PURPLE"______SUM INSTRS______\n"EOC);
	while (i < data->instr_num) {
		ft_printf("name = %s | label = %s | sum = %d\n", data->instrs[i].name, data->instrs[i].label, data->instrs[i].sum_size);
		i++;
	}
	ft_printf(PURPLE"----------------------\n"EOC);
	write_magic_fd(COREWAR_EXEC_MAGIC, fd);
	writing_header_to_file(data->header->prog_name, PROG_NAME_LENGTH + 1, fd, 0);
	write_size_fd(data->file_size, fd);
	writing_header_to_file(data->header->comment, COMMENT_LENGTH + 1, fd, 1);
	writing_instrs_to_fd(data, fd);

	//CHAMP_MAX_SIZE
	return (0);
}
