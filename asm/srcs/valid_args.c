/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sweet-cacao <sweet-cacao@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:48:02 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 19:48:02 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

int		get_bool(t_data *data, int i)
{
	int bool;

	bool = 0;
	if (data->instrs[data->instr_num].args[i].type == T_DIR)
		bool = T_DIR & g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_IND)
		bool = T_IND & g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_REG)
		bool = T_REG & g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	return (bool);
}

int		valid_args(t_data *data)
{
	int i;
	int num_args;

	i = 0;
	num_args = g_op_tab[data->instrs[data->instr_num].id_instr].col_args;
	while (i < 3)
	{
		if ((num_args) == i)
		{
			if (i < 3 && data->instrs[data->instr_num].args[i].type != 0)
				return TOO_MANY_ARGS;
			else
				return (1);
		}
		if (data->instrs[data->instr_num].args[i].type == 0)
			return FEW_ARGS;
		if (!get_bool(data, i))
			return INVALID_TYPE;
		i++;
	}
	return (1);
}