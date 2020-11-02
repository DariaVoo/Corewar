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

void		del_carriage(t_carriage **carriage)
{
	t_carriage	*del_carriage;

	del_carriage = *carriage;
	if (!*carriage)
		return ;
	if ((*carriage)->prev)
		(*carriage)->prev->next = (*carriage)->next;
	else
		{}
	*carriage = (*carriage)->next;
	free(del_carriage);
}

void		game(t_vm *vm)
{
	t_carriage	*current_carriage;
	int32_t		cycle_count;

	cycle_count = 0;
	for (t_carriage *kek = vm->carriage; kek->next; kek = kek->next)
		ft_printf("%d\n", kek->regs[0]);
	while (1)
	{
		if (vm->cycle_dump == cycle_count)
			stop_game(vm->arena);
		current_carriage = vm->carriage;
		while (current_carriage)
		{
			del_carriage(&current_carriage);
			ft_printf("{red}------------------------------------------{eoc}\n");
			break ;
			update_carriage(current_carriage, vm->arena);
			current_carriage = current_carriage->next;
		}
		break ;
		cycle_count++;
	}
	for (t_carriage *kek = current_carriage; kek->next; kek = kek->next)
		ft_printf("%d\n", kek->regs[0]);
		// debug_print_carriage(vm);
		// op_live(vm->arena, vm->carriage);
		// debug_print_carriage(vm);
		// arena_print(vm->arena);
}