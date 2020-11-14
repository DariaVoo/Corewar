/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:04:57 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/13 20:43:32 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			op_sti(uint8_t *arena, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int			i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	ft_printf("carriage = %d\n", carriage->regs[0]);
	ft_printf("args: %d %d %d\n", args[FIRST].value, args[SECOND].value, args[THIRD].value);
	take_args(arena, carriage, FIRST);
	ft_printf("after take args: %d %d %d\n", args[FIRST].value, args[SECOND].value, args[THIRD].value);
	address = carriage->program_counter + (args[SECOND].value + args[THIRD].value) % MEM_SIZE;
	address = address < 0 ? MEM_SIZE + address : address;
	i = 0;
	while (i < 4)
	{
		*(arena + (address + i) % MEM_SIZE) = (regs[args[FIRST].value - 1] >> ((3 - i) * CHAR_BIT)) & 0xFF;
		i++;
	}
}