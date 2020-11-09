/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/09 21:42:09 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ld(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		i;
	int32_t		address;
	extern t_op	g_optab[17];

	i = 0;
	args = carriage->args;
	shift = get_args(args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	while (i < g_optab[carriage->opcode - 1].col_args)
	{
		if (args[i].type == IND_CODE)
		{
			address = carriage->program_counter + args[i].value % IDX_MOD;
			args[i].value = *(arena + address + (address > 0 ? 0 : MEM_SIZE));
		}
		i++;
	}
	carriage->regs[args[SECOND].value] = args[FIRST].value;
	carriage->carry = carriage->regs[args[SECOND].value] == 0 ? 1 : 0;
	return (shift);
}
