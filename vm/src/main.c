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

#include "vm.h"

int				main(int argc, char **argv)
{
	char		*champ_names[MAX_PLAYERS + 1];
	t_champion	*champ[MAX_PLAYERS + 1];
	t_carriage	*carriage;
	t_vm		vm[1];
	int			i;
	int			y;

	i = (y = 0, y + 2);
	if (argc < MIN_ARGS_NUMBER + 1)
		exit_error(E_USAGE);
	argv++;
	init_arrptr((void *)champ_names, MAX_PLAYERS + 1);
	init_arrptr((void *)champ, MAX_PLAYERS + 1);
	carriage = NULL;
	parse_args(champ_names, argv);
	parse_files(champ, champ_names);
	set_starter_kit_carriage(&carriage, champ);
	init_vm(vm, champ, carriage);
	init_arena(vm);
	game(vm);
	// visualisation();
	return (0);
}
