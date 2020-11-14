/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:35:20 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/13 20:35:26 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		load_oper(uint8_t *arena, t_carriage *carriage)
{
	uint8_t		opc;
	extern t_op	g_optab[17];

	carriage->opcode = *(arena + carriage->program_counter);
	opc = carriage->opcode;
	carriage->cycle_to_die = opc >= 1 && opc <= 16 ? g_optab[opc - 1].cycle_to_die : 0;
}
