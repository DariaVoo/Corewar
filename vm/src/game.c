#include "vm.h"

void		game_intro_msg(t_vm *vm)
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

void		game_outro_msg(t_vm *vm)
{
	t_champion	*champ;

	champ = vm->last_alive;
	if (champ)
		ft_printf("Contestant %d, \"%s\", has won !\n", champ->id, \
											champ->header.prog_name);
}

void		exec_cycle(t_vm *vm)
{
	t_carriage	*carriage;

	vm->iter_from_start++;
	vm->cycle_after_check++;
	carriage = vm->carriage;
	while (carriage)
	{
		execute_oper(vm, carriage);
		carriage = carriage->next;
	}
}

void		game(t_vm *vm)
{
	game_intro_msg(vm);
	while (vm->carriage_num)
	{
		if (vm->cycle_dump == vm->iter_from_start)
		{
			arena_print(vm->arena);
			break ;
		}
		exec_cycle(vm);
		if (vm->cycle_to_die == vm->cycle_after_check || vm->cycle_to_die <= 0)
			cycles_to_die_check(vm);
	}
	game_outro_msg(vm);
}
