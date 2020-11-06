#include "asm.h"
#include "../libft/includes/libftprintf.h"

void	free_massiv(char **massiv)
{
	int i;

	i = 0;
	if (!massiv )
		return;
	while(massiv[i])
	{
		free(massiv[i]);
		i++;
	}
	free(massiv);
}