#include "vm.h"

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
	while (vm->carriage_num)
	{
		if (vm->cycle_dump == vm->iter_from_start)
		{
			arena_print(vm->arena);
			break ;
		}
		// ft_printf("cycle %d\n", vm->iter_from_start);
		exec_cycle(vm);
		if (vm->cycle_to_die == vm->cycle_after_check || vm->cycle_to_die <= 0)
			cycles_to_die_check(vm);
	}
}