#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"



void    ft_read_file(t_data *data)
{
	char *str;
	while (get_next_line(data->read_fd, &str))
	{
		data->line_count++; //номер строки для вывода ошибки
		// ft_putnbr(data->line_count);
		// ft_putchar('\n');
		ft_line_parser(str, data);
		//сама ошибка выводится и обрабатывается непосредственно внутри функций
		/*
		if (col_error != -1) //-1 когда ошибок нет, любое другое число - ошибка есть и она находится на позиции этого числа (колонка)
			ft_error(str, "error_msg", data->line_count, col_error); */
	}
	/*
	name != NULL, comment != NULL, instr != NULL
	name >< DEFINED_BYTES, comment >< DEFINED_BYTES
	*/
}

int		ft_line_parser(char *str, t_data *data)
{
	if (ft_is_comment(str) == 1) //пропуск комментариев
		return (-1);
	if (data->header->is_comment == 0 || data->header->is_name == 0)
		ft_parse_header(data->header, str, data->line_count);
	if (data->header->is_comment == 1 && data->header->is_name == 1)
		ft_parse_body(str, data);
	return (1);
}

int		ft_is_comment(char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}



