/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:47:36 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 21:14:51 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	extract_number(char *arg, t_data *data, int num_arg)
{
	int number;

	if (arg[0] != DIRECT_CHAR)
		free_fd_put_error("Invalid direct arg without label", \
									data->split, data, (*data->symbol_number));
	number = ft_atoi(&arg[1]);
	if (!ft_is_number(&arg[1]))
		free_fd_put_error("Invalid direct arg without label", \
									data->split, data, (*data->symbol_number));
	data->instrs[data->instr_num].args[num_arg].value = number;
}

void	skip_comment(char *str_init, char **str)
{
	char **str_lines;

	if (ft_strchr(str_init, COMMENT_CHAR))
	{
		str_lines = ft_strsplit(str_init, COMMENT_CHAR);
		*str = ft_strdup(str_lines[0]);
		free_massiv(str_lines);
	}
	else if (ft_strchr(str_init, ALT_COMMENT_CHAR))
	{
		str_lines = ft_strsplit(str_init, ALT_COMMENT_CHAR);
		*str = ft_strdup(str_lines[0]);
		free_massiv(str_lines);
	}
	else
		*str = ft_strdup(str_init);
}

void	go_to_start_if_label_in_arg(char *str, int *symbol_number, t_data *data)
{
	if (*symbol_number != 0 && data->instrs[data->instr_num].label == NULL)
	{
		*symbol_number = 0;
		skip_spaces(str, symbol_number);
	}
}

void	ft_parse_label_init(char *str, t_data *data, int *symbol_number, \
																char **label1)
{
	char	*label;

	if (ft_strchr(str, LABEL_CHAR))
	{
		label = ft_parse_label(str, symbol_number);
		*label1 = label;
		if (label != NULL)
		{
			if (data->instrs[data->instr_num].label == NULL)
			{
				data->instrs[data->instr_num].label = label;
				data->instrs[data->instr_num].labels = \
													add_block(ft_strdup(label));
			}
			else
				push_end(label, &data->instrs[data->instr_num].labels);
		}
	}
}

void	ft_parse_body(char *str_init, t_data *data)
{
	int		symbol_number;
	char	*str;
	char	*label;

	skip_comment(str_init, &str);
	symbol_number = 0;
	data->instrs[data->instr_num].sum_size = 0;
	data->instrs[data->instr_num].id = data->instr_num;
	data->symbol_number = &symbol_number;
	data->split = str_init;
	ft_parse_label_init(str, data, &symbol_number, &label);
	skip_spaces(str, &symbol_number);
	go_to_start_if_label_in_arg(str, &symbol_number, data);
	if (str[symbol_number] == '\0')
	{
		ft_strdel(&str);
		return ;
	}
	ft_parse_function(str, &symbol_number, data);
	ft_parse_args(str, &symbol_number, data);
	ft_count_size(data);
	data->instr_num += 1;
	ft_strdel(&str);
}
