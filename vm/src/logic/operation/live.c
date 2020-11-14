/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:15:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/13 20:46:35 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(uint8_t *arena, t_carriage *carriage)
{
	t_arg		*args;
	extern t_op	g_optab[17];

	(void)arena;
	args = carriage->args;
	if (args[FIRST].value == -carriage->regs[0])
		carriage->live = 1;
}