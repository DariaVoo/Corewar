/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:15:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/11 19:59:28 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	extern t_op	g_optab[17];

	args = carriage->args;
	shift = get_args(args, arena, carriage, g_optab);
	ft_printf("args: %d %d %d\n", args[FIRST].value, args[SECOND].value, args[THIRD].value);
	if (shift == 0)
		return (0);
	if (args[FIRST].value == -carriage->regs[0])
		carriage->live = 1;
	return (shift);
}