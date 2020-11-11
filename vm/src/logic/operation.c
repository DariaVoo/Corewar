/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/11 01:22:11 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

int			execute_oper(uint8_t *arena, t_carriage *carriage)
{
	int32_t shift;

	shift = 0;
	if (carriage->opcode >= 1 && carriage->opcode <= 16)
	{
		shift = g_opfunc[carriage->opcode - 1].func(arena, carriage);
		if (shift == 0)
		{
			ft_printf("PLOXA in execute_oper\n");
			return (0);
		}
	}
	if (carriage->opcode != OPCODE_ZJMP)
		carriage->program_counter += OPCODE_SIZE + shift;
	return (1);
}

void		load_oper(uint8_t *arena, t_carriage *carriage)
{
	uint8_t		opc;
	extern t_op	g_optab[17];

	carriage->opcode = *(arena + carriage->program_counter);
	opc = carriage->opcode;
	carriage->cycle_to_die = opc >= 1 && opc <= 16 ? g_optab[opc - 1].cycle_to_die : 0;
}
