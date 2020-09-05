# include "asm.h"

int ft_is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
	}
	return (0);
}

//ВАРИАНТЫ
//есть лейбл, неверные символы 500
//есть лейбл, неверный последний знак 400
//есть лейбл и верный последний знак 200 -> проверить есть ли еще символы на строке и если нет то номер этой строки не прибавляем дальше
//нет лейбла и верный последний знак (строка с него начинается)
int ft_check_label(char *line, t_championstr championstr)
{
	int i;

	i = 0;
	while (line[i] != LABEL_CHAR)
	{
		if (ft_is_label_char(line[i]))
			championstr.label += line[i];
		else
		{
			return (500);
		}
		i++;
	}
	if (ft_strcmp("", championstr.label) == 0)
		return (300);
	if (line[i] && line[i] != LABEL_CHAR)
		return (400);
	return (200);
}

void ft_parse_line(char *line, t_championstr championstr[10000], t_label *label, t_instr *instr, int line_number)
{
	int code;

	label = NULL;
	if (strstr(line, (char *)LABEL_CHAR))
	{
		code = ft_check_label(line, championstr[line_number]);
		//вынести в отдельную функцию-обработчик ошибок
		if (code == 400)
		{

		}
		if (code == 500)
		{
			ft_printf("*****ERROR*****\n%s\nline: %d\n", "invalid label_chars", line_number);
			exit(1);
		}
		if (code == 300)
		{

		}
		if (code == 200)
		{

		}
	}
}

t_champion *parse_champion(char *chmp_file_name)
{
	/// YOUR CODE HERE
	t_championstr championstr[10000];

	ft_parse_line("line", championstr[10000]);
	ft_printf("Hi, %s!!\n", chmp_file_name);
	return (NULL);
}

