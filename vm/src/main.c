/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 17:40:17 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		intro(t_vm *vm)
{
	int32_t		i;
	t_champion	**champ;

	i = 0;
	champ = vm->champ;
	while (i < vm->count_champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" \"%s\"\n", \
		champ[i]->id, champ[i]->header.prog_size, champ[i]->header.prog_name, \
													champ[i]->header.comment);
		i++;
	}
}

static void		outro(t_vm *vm)
{
	t_champion	*champ;

	champ = vm->last_alive;
	ft_printf("Contestant %d, \"%s\", has won !\n", champ->id, \
											champ->header.prog_name);
}

static void		initialization(char *champ_names[], t_champion *champ[], \
								uint8_t *arena, t_carriage **carriage)
{
	init_arrptr((void *)champ_names, MAX_PLAYERS + 1);
	init_arrptr((void *)champ, MAX_PLAYERS + 1);
	ft_memset(arena, 0, MEM_SIZE);
	*carriage = NULL;
}

int				main(int argc, char **argv)
{
	char		*champ_names[MAX_PLAYERS + 1];
	t_champion	*champ[MAX_PLAYERS + 1];
	uint8_t		arena[MEM_SIZE];
	t_carriage	*carriage;
	t_vm		vm[1];

	if (argc < MIN_ARGS_NUMBER + 1)
		exit_error(E_USAGE);
	argv++;
	initialization(champ_names, champ, arena, &carriage);
	parse_args(champ_names, argv);
	parse_files(champ, champ_names);
	init_arena(arena, champ);
	set_starter_kit_carriage(&carriage, arena);
	init_vm(vm, champ, arena, carriage);
	intro(vm);
	game(vm);
	outro(vm);
	/* free */
	free_arrptr((void *)champ_names);
	free_champ(champ);
	free_carriage_list(&(vm->carriage));
	// visualisation();
	return (0);
}
