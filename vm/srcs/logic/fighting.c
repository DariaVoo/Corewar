//
// Created by snorcros on 10/17/20.
//
#include "vm.h"

int check_carriage(t_carriage *carriage)
{

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
			if (res_check == 0)
				set_new_code();
			else if (res_check == 1)
				reduce_cycle(); // внутри чекаем умерла ли каретка, если да то vm->count_alive--
			else if (res_check == 2)
				do_op();
			carriage = carriage->next;
		}
	}
	return (1);
}
