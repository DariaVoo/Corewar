//
// Created by snorcros on 10/17/20.
//
#include "vm.h"

int check_carriage(t_carriage *carriage)
{
	if (!carriage->check_now)
		return (-1);
	carriage->count_check++;
	carriage->count_live = 0;
	if (carriage->after_live >= carriage->cycle_to_die || carriage->cycle_to_die <= 0)
		return (-2);
	if (carriage->after_live >= NBR_LIVE)
		carriage->cycle_to_die -= CYCLE_DELTA;
	else
		carriage->count_check++;
	if (carriage->count_check == MAX_CHECKS && 1) //add smth
		carriage->cycle_to_die -= CYCLE_DELTA;
	return (1);
}

int fighting(t_vm *vm)
{
	int res_check;
	t_carriage *carriage;

	while (vm->count_alive)
	{
		carriage = vm->carriages;
		while (carriage) {
			res_check = check_carriage(carriage);
			if (res_check == -2)
				delete_carriage(&vm->carriages, carriage); //vm->count_alive-- внутри
			else if (res_check == 0)
				set_new_code();
			else if (res_check == 1)
				reduce_cycle(); //внутри выставляем carriage->check_now
			if (carriage->cycle_to_do == 0)
				do_op();
			carriage = carriage->next;
		}
	}
	return (1);
}
