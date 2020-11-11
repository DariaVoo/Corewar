/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:08:28 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/11 00:04:15 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_st(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int32_t		i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	shift = get_args(args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	if (args[SECOND].type == IND_CODE)
	{
		address = carriage->program_counter + args[SECOND].value % IDX_MOD;
		i = 0;
		while (i < 4)
		{
			*(arena + address + i) = (regs[args[FIRST].value - 1] >> ((3 - i) * CHAR_BIT)) & 0xFF;
			i++;
		}
	}
	else if (args[SECOND].type == REG_CODE)
		regs[args[SECOND].value - 1] = regs[args[FIRST].value - 1];
	return (shift);
}