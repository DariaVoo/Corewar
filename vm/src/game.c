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

/*
	Функция удаляет ноду из связного списка,
	возвращает 1 в случае успеха, 0 - если была удалена первая нода списка,
	т.к. в нашем случае удаление происходит не по основному указателю,
	то мы делаем проверку на возвращаемое значение,
	чтобы изменить основной указатель (vm->carriage)
*/

int8_t		del_carriage(t_carriage **carriage)
{
	t_carriage	*del_carriage;

	del_carriage = *carriage;
	if (!*carriage)
		return (-1);
	if (!(*carriage)->prev)
	{
		*carriage = (*carriage)->next;
		free_carriage(del_carriage);
		return (0);
	}
	(*carriage)->prev->next = (*carriage)->next;
	*carriage = (*carriage)->next;
	free_carriage(del_carriage);
	return (1);
}

void		game(t_vm *vm)
{
	t_carriage	*current_carriage;
	int32_t		cycle_count;

	cycle_count = 0;

	ft_printf("BEFORE GAME:\n");
	for (t_carriage *kek = vm->carriage; kek; kek = kek->next)
		printf("%d\n", kek->regs[0]);

	while (1)
	{
		if (vm->cycle_dump == cycle_count)
			stop_game(vm->arena);
		current_carriage = vm->carriage;
		int i = 0; // debug
		while (current_carriage)
		{
			// debug
			if (i == 1)
			{
				if (del_carriage(&current_carriage) == 0)
					vm->carriage = current_carriage;
				break ;
			}
			i++;
			update_carriage(current_carriage, vm->arena);
			current_carriage = current_carriage->next;
		}
		break ;
		cycle_count++;
	}
	debug_print_carriage(vm);
	vm->carriage->opcode = 11;
	// vm->carriage->carry = 1;
	// execute_oper(vm->arena, vm->carriage);
	// ft_printf("next oper = %d\n", *(vm->arena + vm->carriage->program_counter));
	// debug_print_carriage(vm);
	// vm->carriage->opcode = *(vm->arena + vm->carriage->program_counter);
	execute_oper(vm->arena, vm->carriage);
	debug_print_carriage(vm);
	arena_print(vm->arena);
	// debug_print_carriage(vm);
	// op_live(vm->arena, vm->carriage);
	// debug_print_carriage(vm);
	// arena_print(vm->arena);
}