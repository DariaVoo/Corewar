/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/09 18:44:32 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

int			main(int argc, char **argv)
{
	t_vm	vm[1];
	char	*champion_names[MAX_PLAYERS];

	if (argc < MIN_ARGS_NUMBER + 1)
	{
		printf("Usage: bla-bla-bla\n");
		return (1);
	}
	argc--;
	argv++;
	init_champion_names(champion_names);
	init_vm(vm);
	parse_args(vm, champion_names, argv);

	vm->count_champs = get_number_of_players(champion_names);
	vm->champs = valid_champions(champion_names, vm->count_champs);
	vm->carriage = valid_carriage(vm->champs, vm->count_champs);
	init_arena(vm);
	arena_print(vm->arena);
	while (vm->carriage)
	{
		ft_printf("%d\n", vm->carriage->regs[0]);
		vm->carriage = vm->carriage->next;
	}
	return (0);
}
