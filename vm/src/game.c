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
		// условие для dump
		
		exec_cycle(vm);
		if (vm->cycle_to_die == vm->cycle_after_check || vm->cycle_to_die <= 0)
			cycles_to_die_check(vm);
	}
}