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

void		game(t_vm *vm)
{
	t_carriage *current;

	while (1)
	{
		current = vm->carriage;
		while (current)
		{

			current = current->next;
		}
	}
}

int			main(int argc, char **argv)
{
	char		*champ_names[MAX_PLAYERS + 1];
	t_champion	*champ[MAX_PLAYERS + 1];
	t_carriage	*carriage;
	t_vm		vm[1];

	if (argc < MIN_ARGS_NUMBER + 1)
		exit_error(E_USAGE);
	else
		argv++;
	init_arrptr((void *)champ_names, MAX_PLAYERS + 1);
	init_arrptr((void *)champ, MAX_PLAYERS + 1);
	carriage = NULL;
	parse_args(champ_names, argv);
	parse_files(champ, champ_names);
	set_starter_kit_carriage(&carriage, champ_names);
	init_vm(vm, champ, carriage);
	init_arena(vm);
	arena_print(vm->arena);
	// game(vm);
	while (vm->carriage)
	{
		ft_printf("%d\n", vm->carriage->regs[0]);
		vm->carriage = vm->carriage->next;
	}
	return (0);
}
