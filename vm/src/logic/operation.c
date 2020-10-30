/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/31 00:40:43 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		kek(int kek)
{
	static int lol = 0;

	if (kek == 1)
		lol = 1;
	else if (lol == 1)
	{
		lol = 0;
		return(1);
	}
	return (lol);
}

static int32_t	ft_size(int code)
{
	if (code == REG_CODE)
		return (1);
	else if (code == IND_CODE)
		return (2);
	else if (code == DIR_CODE)
		return (4);
	return (0);
}

static int32_t	get_arg(uint8_t *ptr, uint8_t type)
{
	int32_t	arg;
	int32_t	i;
	uint8_t	size;

	arg = 0;
	i = 0;
	size = (type == REG_CODE) ? REG_SIZE_BYTE : 0;
	size = (type == IND_CODE) ? IND_SIZE_BYTE : size;
	size = (type == DIR_CODE) ? DIR_SIZE_BYTE : size;
	if (size == 0)
		kek(1);
	while (i < size)
	{
		arg |= *(ptr + i);
		if (i != size - 1)
			arg = arg << CHAR_BIT;
		i++;
	}
	if (type == IND_CODE)
		arg = (int32_t)((int16_t)arg);
	return (arg);
}

int32_t		get_args(t_arg **args, uint8_t *arena, t_carriage *carriage, const t_op *g_op_tab)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	shift = 1;
	i = 0;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		(*args)[i].type = (*ptr >> (CHAR_BIT - (i + 1) * 2)) & THR_BITS;
		(*args)[i].value = get_arg(ptr + shift, (*args)[i].type);
		// if ((*args)[i].type == IND_CODE)
		// {
		// 	if ((carriage->program_counter + (*args)[i].value) < 0)
		// 		(*args)[i].value = *(arena + MEM_SIZE + 
		// 				carriage->program_counter + (*args)[i].value % IDX_MOD);	
		// 	else
		// 		(*args)[i].value = *(arena + carriage->program_counter + 
		// 											(*args)[i].value % IDX_MOD);
		// }
		if (kek(3) == 1)
			return (0);
		shift += ft_size((*args)[i].type);
		i++;
	}
	return (shift);
}

int			execute_oper(uint8_t *arena, t_carriage *carriage)
{
	int32_t shift;
	extern t_op g_op_tab[17];

	shift = g_op_tab[carriage->opcode - 1].func(arena, carriage);
	if (shift == 0)
	{
		ft_printf("PLOXA in execute_oper\n");
		return (0);
	}
	carriage->program_counter += OPCODE_SIZE + shift;
	return (1);
}