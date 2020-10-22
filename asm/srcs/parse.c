#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

void    ft_read_file(t_data *data)
{
	char *str;

	while (gnl)
	{
		data->line_count++;
		ft_line_valid_data(str, *data);
		if (valid != -1) //-1 когда ошибок нет, любое другое число - ошибка есть и она находится на позиции этого числа (колонка)
			ft_error(str, "error_msg", data->line_count);
	}
	name != NULL, comment != NULL, instr != NULL
	name >< DEFINED_BYTES, comment >< DEFINED_BYTES
}