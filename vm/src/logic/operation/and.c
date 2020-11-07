/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:12:08 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/06 12:40:12 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	take_args(u_int8_t *arena, t_arg *args, t_carriage *carriage, int32_t num_arg)
{
	int32_t		i;
	int32_t		address;

	i = 0;
	while (i < MAX_ARGS)
	{
		if (args[i].type == REG_CODE && i != num_arg)
			args[i].value = carriage->regs[args[i].value];
		else if (args[i].type == IND_CODE && i != num_arg)
		{
			// можно юзануть get_arg 
			address = carriage->program_counter + args[i].type % IDX_MOD;
			address = address < 0 ? MEM_SIZE + address : address;
			args[i].value = *(uint32_t*)(arena + address);
		}
		i++;
	}
}

int		op_and(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	

	return (0);
}