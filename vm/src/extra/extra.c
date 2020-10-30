#include "vm.h"

void		exit_error(const char *str)
{
	ft_fprintf(STDERR_FILENO, "%s%s\n", E_ERR, str);
	exit (0);
	// exit(EXIT_FAILURE);
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