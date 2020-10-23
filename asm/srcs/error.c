#include "asm.h"
#include "../libft/includes/libftprintf.h"

/*
 * переделать на fd 2 (stderr)
 */

void    ft_error(char *err, char *line, int num_str, int ind_str)
{
	int		i;

	i = ind_str;
	ft_printf("%s [%d:%d]", err, num_str, ind_str);
	if (line) {
		write(1, " INSTRUCTION \"", 14);
		while (line[i] != ' ' && line[i] != '\t' && line[i] != COMMENT_CHAR &&
			   line[i] != ALT_COMMENT_CHAR && line[i] != '\0') {
			ft_putchar(line[i]);
			i++;
		}
		write(1, "\"\n", 2);
	}
	else
		write(1, "\n", 1);
	exit(1);
}