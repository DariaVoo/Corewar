#include "vm.h"

void		champ_print(t_champion *ptr)
{
	unsigned int i;

	i = 0;
	ft_printf("Magic header: %x\nNAME: %s\nProg size: %x\nComment: %s\nCode:\n", ptr->header.magic, ptr->header.prog_name, ptr->header.prog_size, ptr->header.comment);
	while (i < ptr->header.prog_size)
	{
		ft_printf("%.2x", (0xff & ptr->code[i]));
		if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 16 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

void		arena_print(uint8_t *arena)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (arena[i])
			ft_printf("%.2x", (0xff & arena[i]));
		else
			ft_printf("%.2x", (0xff & arena[i]));
		// if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 64 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

void			debug_print_carriage(t_vm *vm)
{
	t_carriage	*copy;

	copy = vm->carriage;
	while (copy)
	{
		for (int i = 0; i < REG_NUMBER; i++)
		{
			if (copy->regs[i])
				ft_printf("[%2d]", copy->regs[i]);
			else
				ft_printf("[%2d]", copy->regs[i]);
		}
		ft_printf("\n");
		ft_printf("player id: %d\n", copy->player_id);
		ft_printf("program_counter: %d\n", copy->program_counter);
		ft_printf("cycle_to_die: %d\n", copy->cycle_to_die);
		ft_printf("opcode: [%.2x]\n", copy->opcode);
		ft_printf("-------------------------------------\n");
		copy = copy->next;
	}
}