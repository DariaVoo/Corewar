#include "asm.h"
#include "../libft/includes/libftprintf.h"

char		*ft_parse_label(char *split, int *i)
{
	char	**labels;
	char	*label;

	skip_spaces(split, i);
	labels = ft_strsplit(&split[*i], LABEL_CHAR);
	if (labels != NULL)
	{
		if (check_label(labels[0]))
		{
			(*i) += ft_strlen(labels[0]);
			if (split[*i] && split[*i] == ':')
			{
				(*i)++;
				label = ft_strdup(labels[0]);
				free_massiv(labels);
				return (label);
			}
		}
	}
	free_massiv(labels);
	return NULL;
}