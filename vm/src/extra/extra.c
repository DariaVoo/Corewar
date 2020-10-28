#include "vm.h"

void		exit_error(const char *str)
{
	ft_fprintf(STDERR_FILENO, "%s%s\n", E_ERR, str);
	exit (0);
	// exit(EXIT_FAILURE);
}

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
			ft_printf("{red}%.2x{eoc}", (0xff & arena[i]));
		else
			ft_printf("%.2x", (0xff & arena[i]));
		if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 64 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

/*
	функция для инициализации массива указателей на что-либо
*/

void			init_arrptr(void **array, uint32_t size)
{
	uint32_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
}