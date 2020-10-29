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
// carriage->opcode = *(champ->code + carriage->program_counter);
static void			init_carriage(t_carriage *carriage, uint8_t id)
{
	carriage->program_counter = MEM_SIZE / get_number_of_players() * id;
	ft_memset(carriage->regs, 0, REG_NUMBER);
	carriage->regs[0] = -id;
	carriage->cycle_to_die = CYCLE_TO_DIE;
	carriage->carry = 0;
	carriage->live = 0;
	carriage->next = NULL;
}
void		update_carriage(t_carriage *carriage)
{

}

void		game(t_vm *vm)
{
	t_carriage	*current;
	int32_t		cycle_count;

	cycle_count = 0;
	while (1)
	{
		if (vm->cycle_dump == cycle_count)
		{
			arena_print(vm->arena);
			break ;
		}
		current = vm->carriage;
		while (current)
		{
			current = current->next;
		}
		cycle_count++;
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
	set_starter_kit_carriage(&carriage, champ);
	init_vm(vm, champ, carriage);
	init_arena(vm);
	// arena_print(vm->arena);
	// game(vm);
	while (vm->carriage)
	{
		for (int i = 0; i < REG_NUMBER; i++)
			ft_printf("%d ", vm->carriage->regs[i]);
		ft_printf("\n");
		ft_printf("current_pos: %d\n", vm->carriage->program_counter);
		ft_printf("%.2x\n", vm->carriage->opcode);
		ft_printf("-------------------------------------\n");
		vm->carriage = vm->carriage->next;
	}
	// game(vm);
	// visualisation();
	
	return (0);
}
