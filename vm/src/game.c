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

void		game(t_vm *vm)
{
	t_carriage	*current_carriage;
	int32_t		cycle_count;

	cycle_count = 0;
	while (1)
	{
		if (vm->cycle_dump == cycle_count)
		{
			stop_game(vm->arena);
		}
		current_carriage = vm->carriage;




		while (current_carriage)
		{
			update_carriage(current_carriage, vm->arena);
			current_carriage = current_carriage->next;
		}
		break ;
		cycle_count++;
	}
		debug_print_carriage(vm);
		ft_printf("LOL\n");
		op_ld(vm->arena, vm->carriage);
		debug_print_carriage(vm);
}