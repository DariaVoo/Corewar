/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/31 15:07:32 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	game(vm);
	// visualisation();
	return (0);
}
