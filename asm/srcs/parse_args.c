/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:49:30 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 21:14:51 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse_register(char *arg, t_data *data, int num_arg)
{
	int number;

	if (arg[0] == 'r' && arg[1] && ft_isdigit(arg[1]))
	{
		data->instrs[data->instr_num].args[num_arg].type = T_REG;
		number = ft_atoi(&arg[1]);
		if (!ft_is_number(&arg[1]) || (number < 1 || number > 16))
			free_fd_put_error("Invalid register in args", data->split, \
												data, (*data->symbol_number));
		data->instrs[data->instr_num].args[num_arg].value = number;
	}
}

void		parse_direct(char *arg, t_data *data, int num_arg)
{
	if (ft_strchr(arg, DIRECT_CHAR))
	{
		data->instrs[data->instr_num].args[num_arg].type = T_DIR;
		if (ft_strchr(arg, LABEL_CHAR))
		{
			if (!arg[0] || !arg[1] || !arg[2])
				free_fd_put_error("Invalid direct arg with label", \
									data->split, data, (*data->symbol_number));
			if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
			{
				if (ft_strstr(data->all_labels, &arg[2]) != 0)
					data->instrs[data->instr_num].args[num_arg].label = \
															ft_strdup(&arg[2]);
				else
					free_fd_put_error("No such label",
							data->split, data, (*data->symbol_number));
			}
			else
				free_fd_put_error("Invalid direct arg with label", \
									data->split, data, (*data->symbol_number));
		}
		else
			extract_number(arg, data, num_arg);
	}
}

void		parse_indirect(char *arg, t_data *data, int num_arg)
{
	int number;

	if (ft_isdigit(arg[0]) || arg[0] == '+' || arg[0] == '-')
	{
		data->instrs[data->instr_num].args[num_arg].type = T_IND;
		if (ft_is_number(arg))
		{
			number = ft_atoi(arg);
			data->instrs[data->instr_num].args[num_arg].value = number;
		}
		else
			free_fd_put_error(LOL, data->split, data, (*data->symbol_number));
	}
	else if (arg[0] == LABEL_CHAR)
	{
		if (ft_strstr(data->all_labels, &arg[1]) != 0)
		{
			data->instrs[data->instr_num].args[num_arg].type = T_IND;
			data->instrs[data->instr_num].args[num_arg].label = \
															ft_strdup(&arg[1]);
		}
		else
			free_fd_put_error("No such label", \
					data->split, data, (*data->symbol_number));
	}
}

void		parse_one_arg(char *arg_old, t_data *data, int num_arg)
{
	char *arg;

	arg = ft_strtrim(arg_old);
	parse_register(arg, data, num_arg);
	if (data->instrs[data->instr_num].args[num_arg].type == 0)
		parse_direct(arg, data, num_arg);
	if (data->instrs[data->instr_num].args[num_arg].type == 0)
		parse_indirect(arg, data, num_arg);
	ft_strdel(&arg);
	if (data->instrs[data->instr_num].args[num_arg].type == 0)
		free_fd_put_error("Invalid type of arg", data->split, data, \
														(*data->symbol_number));
	data->instrs[data->instr_num].args[num_arg].arg_number = num_arg;
}

void		ft_parse_args(char *split, int *i, t_data *data)
{
	char	**args;
	int		args_num;
	int		j;

	j = 0;
	args = ft_strsplit(&split[*i], SEPARATOR_CHAR);
	args_num = massiv_len(args);
	if (args_num > 3 || args == NULL)
		free_fd_put_error(FT_PARSE_ARGS1, split, data, *i);
	if (args == NULL)
		free_fd_put_error(FT_PARSE_ARGS2, split, data, *i);
	while (args[j] && j < args_num)
	{
		parse_one_arg(args[j], data, j);
		j++;
	}
	j = valid_args(data);
	if (j == TOO_MANY_ARGS)
		free_fd_put_error("Invalid number of args(too many)", split, \
																	data, *i);
	else if (j == FEW_ARGS)
		free_fd_put_error("Invalid number of args(few)", split, data, *i);
	else if (j == INVALID_TYPE)
		free_fd_put_error("Invalid type of args", split, data, *i);
	free_massiv(args);
}
