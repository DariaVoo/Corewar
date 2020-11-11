#include "asm.h"
#include "../libft/includes/libftprintf.h"

char		*ft_parse_label(char *split, int *i)
{
	char	**labels;
	char	*label;

	labels = NULL;
	label = NULL;
	skip_spaces(split, i);
	labels = ft_strsplit(&split[*i], LABEL_CHAR);
	if (labels != NULL)
	{
		if (check_label(labels[0]))
		{
			(*i) += ft_strlen(labels[0]);
			//проверка на наличие двоеточия и его пропуск
			//если сразу после нет двоеточия то оно в другом месте
			if (split[*i] && split[*i] == ':')
			{
				(*i)++;
				label = ft_strdup(labels[0]);
				free_massiv(labels);
				return (label);
			}
			else
			{
				free_massiv(labels);
				return NULL;
			}
		}
		else
		{
			free_massiv(labels);
		}
	}
	//по сути этого случая не может быть так как проверка на label char есть раньше
	return NULL;
}