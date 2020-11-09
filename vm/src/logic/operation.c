/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/09 11:38:00 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

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

static int32_t	ft_size(int32_t code,  uint8_t tdir_size)
{
	if (code == REG_CODE)
		return (REG_SIZE_BYTE);
	else if (code == IND_CODE)
		return (IND_SIZE_BYTE);
	else if (code == DIR_CODE)
		return (DIR_SIZE_BYTE - 2 * tdir_size);
	return (0);
}

int32_t		get_arg(uint8_t *ptr, uint8_t type, t_op params)
{
	int32_t	arg;
	int32_t	i;
	uint8_t	size;

	arg = 0;
	i = 0;
	if (params.bit_type == 0)
	{
		size = (params.type_arg[0] == T_REG) ? REG_SIZE_BYTE : 0;
		size = (params.type_arg[0] == T_IND) ? IND_SIZE_BYTE : size;
		size = (params.type_arg[0] == T_DIR) ? DIR_SIZE_BYTE - 2 * params.tdir_size : size;
	}
	else if ((size = ft_size(type, params.tdir_size)) == 0)
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

int32_t		get_args(t_arg *args, uint8_t *arena, t_carriage *carriage, t_op *g_optab)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;
	t_op	params;

	params = g_optab[carriage->opcode - 1];
	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	shift = params.bit_type;
	i = 0;
	while (i < params.col_args)
	{
		args[i].type = (*ptr >> (CHAR_BIT - (i + 1) * 2)) & THR_BITS;
		args[i].value = get_arg(ptr + shift, args[i].type, params);
		if (kek(3) == 1)
			return (0);
		shift += ft_size(args[i].type, params.tdir_size);
		i++;
	}
	if (params.bit_type == 0)
	{
		shift = (params.type_arg[0] == T_REG) ? REG_SIZE_BYTE : shift;
		shift = (params.type_arg[0] == T_IND) ? IND_SIZE_BYTE : shift;
		shift = (params.type_arg[0] == T_DIR) ? DIR_SIZE_BYTE : shift;
	}
	return (shift);
}

void	take_args(uint8_t *arena, t_carriage *carriage, int32_t num_arg)
{
	int32_t		i;
	int32_t		address;
	t_arg		*args;
	extern t_op	g_optab[17];

	i = 0;
	args = carriage->args;
	while (i < MAX_ARGS)
	{
		if (args[i].type == REG_CODE && i != num_arg)
			args[i].value = carriage->regs[args[i].value];
		else if (args[i].type == IND_CODE && i != num_arg)
		{
			address = carriage->program_counter + args[i].value % IDX_MOD;
			address = address < 0 ? MEM_SIZE + address : address;
			args[i].value = get_arg(arena + address, DIR_CODE, g_optab[carriage->opcode - 1]);
		}
		else if (args[i].type == DIR_CODE && i != num_arg)
			args[i].value = args[i].value;
		i++;
	}
}

int			execute_oper(uint8_t *arena, t_carriage *carriage)
{
	int32_t shift;

	shift = g_opfunc[carriage->opcode - 1].func(arena, carriage);
	if (shift == 0)
	{
		ft_printf("PLOXA in execute_oper\n");
		return (0);
	}
	if (carriage->opcode != OPCODE_ZJMP)
		carriage->program_counter += OPCODE_SIZE + shift;
	return (1);
}
