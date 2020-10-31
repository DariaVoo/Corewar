#include "vm.h"

static void	update_carriage(t_carriage *carriage, uint8_t *arena)
{
	carriage->opcode = *(arena + carriage->program_counter);
	carriage->cycle_to_die--;
}

static void	stop_game(uint8_t *arena)
{
	arena_print(arena);
	exit(0);
}

// void		add_carriage(t_carriage **carriage, uint8_t *arena, uint8_t id)
// {
// 	t_carriage	*new_carriage;

// 	new_carriage = create_carriage();
// 	init_carriage(new_carriage, arena, id);
// 	if (*carriage)
// 		new_carriage->next = *carriage;
// 	*carriage = new_carriage;
// }

void		del_carriage(t_carriage **carriage)
{
	t_carriage *suka;
	*carriage = (*carriage)->next;
}

void		game(t_vm *vm)
{
	t_carriage	*current_carriage;
	int32_t		cycle_count;

	cycle_count = 0;
	while (1)
	{
		if (vm->cycle_dump == cycle_count)
			stop_game(vm->arena);
		current_carriage = vm->carriage;
		while (current_carriage)
		{
			del_carriage(&current_carriage);
			break ;
			update_carriage(current_carriage, vm->arena);
			current_carriage = current_carriage->next;
		}
		break ;
		cycle_count++;
	}
	debug_print_carriage(vm);
	op_ld(vm->arena, vm->carriage);
	debug_print_carriage(vm);
}