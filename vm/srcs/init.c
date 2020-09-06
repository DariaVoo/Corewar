/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:00:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/01 12:43:33 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champion	*init_champ(int id)
{
	t_champion	*champ;

	if ((champ = (t_champion*)ft_memalloc(sizeof(t_champion))) == NULL)
		ft_exit("ERROR: MALLOC");
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
	return (champ);
}

t_vm		*init_vm(size_t col_champs)
{
	t_vm	*vm;

	if ((vm = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
		ft_exit("ERROR: MALLOC\n");
	vm->champs = NULL;;
	vm->col_champs = col_champs;
	ft_memset(vm->arena, '0', MEM_SIZE);
	return (vm);
}

void		init_arena(t_vm *vm)
{
	t_champion	*ptr;
	size_t		i;

	i = vm->col_champs;
	ptr = vm->champs;
	while (i > 0)
		ft_memmove(&(vm->arena[MEM_SIZE / i--]), ptr->code, \
										ptr->header.prog_size);
}