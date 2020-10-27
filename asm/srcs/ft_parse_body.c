#include "../includes/asm2.h"
#include "../libft/includes/libftprintf.h"

void	ft_init_structs(t_data data, int instr_num)
{
	data.header = (t_header*)malloc(sizeof(t_header));
	data.instrs = (t_instr*)malloc(sizeof(t_instr) *10);
	data.label = (t_label*)malloc(sizeof(t_label));
	data.name = NULL;
	data.comment = NULL;
	data.line_count = 0;
	data.instr_num = 0;
}
void 	skip_spaces(char *split, int *i)
{
	while (split[*i] == ' ')
	{
		(*i)++;
	}
}

int		check_label(char *label)
{
	int 	i;
	int 	j;

	i = 0;
	while (label[i] != LABEL_CHAR)
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != label[i]) {
			printf("%c", label[i]);
			j++;
		}
		if (LABEL_CHARS[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char *ft_parse_label(char *split, int *i)
{
	char **labels;

	labels = NULL;
	labels = ft_strsplit(split, LABEL_CHAR);
	if (labels != NULL)
	{
		if (check_label(labels[0]))
		{
			(*i) += ft_strlen(labels[0]);

			return labels[0];
		}
	}
	return NULL;
}

void	ft_parse_body(char *str, t_data data)
{
	char	*label;
	int 	symbol_number;

//	symbol_number = 0;
//	data.instrs[data.instr_num] = NULL;
//	data.instrs[data.instr_num].label = ft_strdup("lol");
//	data.instrs[data.instr_num].name = "NAME";
	if (ft_strchr(str, LABEL_CHAR))
	{
		label = ft_parse_label(str, &symbol_number);
		ft_printf("%s\n", label);
		data.instrs[data.instr_num].label = label;

		ft_printf("%s\n", data.instrs[data.instr_num].label );
		//если лейбл есть пушим в конец структуры лейблов
		//		if (body.label != NULL)
		//			push_back(labels, label);
		if (data.instrs[data.instr_num].label != NULL)
			skip_spaces(str, &symbol_number);
	}
}

int main(void)
{
	t_data data;
	char *str = "label01: ";
	ft_init_structs(data, 10);
	ft_parse_body(str, data);
	ft_printf("label = '%s'", data.instrs[data.instr_num].label);
}