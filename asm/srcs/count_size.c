/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:38:41 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/14 19:38:45 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libftprintf.h"
=======
/*   By: sweet-cacao <sweet-cacao@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:50:32 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 19:50:32 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"
>>>>>>> cfcf2b8a0bba82cd00fe3fb823f17e53eb483132

void	ft_count_size(t_data *data)
{
	int i;
	int size;
	int t_dir_size;

	size = 2;
	i = 0;
	t_dir_size = 4;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].bit_type == 0)
		size--;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].tdir_size == 1)
		t_dir_size = 2;
	while (i < g_op_tab[data->instrs[data->instr_num].id_instr].col_args)
	{
		if (data->instrs[data->instr_num].args[i].type == T_DIR)
			size += t_dir_size;
		else if (data->instrs[data->instr_num].args[i].type == T_IND)
			size += 2;
		else if (data->instrs[data->instr_num].args[i].type == T_REG)
			size++;
		i++;
	}
	data->instrs[data->instr_num].size = size;
}
