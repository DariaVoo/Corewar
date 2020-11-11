/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:50:52 by dima              #+#    #+#             */
/*   Updated: 2020/11/11 20:04:10 by qjosmyn          ###   ########.fr       */
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

int32_t		get_arg(uint8_t *arena, int16_t address, uint8_t type, t_op params)
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
		arg |= *(arena + (address + i) % MEM_SIZE);
		if (i != size - 1)
			arg = arg << CHAR_BIT;
		i++;
	}
	if (type == IND_CODE)
		arg = (int32_t)((int16_t)arg);
	return (arg);
}

int32_t		arguments(t_arg *args, uint8_t *arena, int32_t pc, t_op param)
{
	int32_t		i;
	int16_t		address;
	int32_t		shift;

	i = 0;
	address = pc + OPCODE_SIZE;
	shift = param.bit_type;
	while (i < param.col_args)
	{
		args[i].type = *(arena + address % MEM_SIZE);
		args[i].type = (args[i].type >> (CHAR_BIT - (i + 1) * 2)) & THR_BITS;
		args[i].value = get_arg(arena, address + shift, args[i].type, param);
		if (kek(3) == 1)
			return (0);
		shift += ft_size(args[i].type, param.tdir_size);
		ft_printf("args [%d] = %d\n", i , shift);
		i++;
	}
	return (shift);
}

int32_t		get_args(t_arg *args, uint8_t *arena, t_carriage *carriage, t_op *g_optab)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;
	t_op	param;

	param = g_optab[carriage->opcode - 1];
	shift = arguments(args, arena, carriage->program_counter, param);
	ft_printf("args: %d %d %d\n", args[FIRST].value, args[SECOND].value, args[THIRD].value);
	if (param.bit_type == 0)
	{
		shift = (param.type_arg[0] == T_REG) ? REG_SIZE_BYTE : shift;
		shift = (param.type_arg[0] == T_IND) ? IND_SIZE_BYTE : shift;
		shift = (param.type_arg[0] == T_DIR) ? DIR_SIZE_BYTE - 2 * param.tdir_size : shift;
	}
	if (shift == 0)
		return (0);
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
			args[i].value = carriage->regs[args[i].value - 1];
		else if (args[i].type == IND_CODE && i != num_arg)
		{
			address = carriage->program_counter + args[i].value % IDX_MOD;
			address = address < 0 ? MEM_SIZE + address : address;
			// Читаем 4 байта. Это костыль, чтою меньше функций юзать
			args[i].value = get_arg(arena, address, DIR_CODE, g_optab[0]);
			ft_printf("address = %d\n", *(arena + address));
		}
		else if (args[i].type == DIR_CODE && i != num_arg)
			args[i].value = args[i].value;
		i++;
	}
}
