/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:08:28 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/04 14:51:15 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_st(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	shift = get_args(&args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	if (args[SECOND].type == IND_CODE)
	{
		address = carriage->program_counter + args[SECOND].value % IDX_MOD;
		*(arena + address) = regs[args[FIRST].value];
	}
	else if (args[SECOND].type == REG_CODE)
		regs[args[SECOND].value] = regs[args[FIRST].value];
	return (shift);
}