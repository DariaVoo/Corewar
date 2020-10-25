#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"
#include "../includes/error.h"

void	ft_parse_body(char *str, t_data data)
{
	char **arr;
	char *tmp;

	tmp = epur_asm_str(str);
	arr = w_count(str, ' ');
}


// UTILS
int		ft_wc(char const *s, char c)
{
	int		q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}