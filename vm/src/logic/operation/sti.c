/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:04:57 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/09 21:37:29 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			op_sti(uint8_t *arena, t_carriage *carriage)
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
	take_args(arena, carriage, FIRST);
	address = carriage->program_counter + (args[SECOND].value + args[THIRD].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	i = 0;
	while (i < 4)
	{
		*(arena + address + i) = (regs[args[FIRST].value] >> ((3 - i) * CHAR_BIT)) & 0xFF;
		ft_printf("%d\n", (regs[args[FIRST].value] >> ((3 - i) * CHAR_BIT)) & 0xFF);
		i++;
	}
	return (shift);
}