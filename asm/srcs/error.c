#include "asm.h"
#include "../libft/includes/libftprintf.h"

/*
 * переделать на fd 2 (stderr)
 */

void    ft_error(char *err, char *line, int num_str, int ind_str)
{
	int		i;

	i = 0;
	ft_printf("%s [%d:%d]", err, num_str, ind_str); // добавить принтф с фд
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

/*
 * ошибка размера имени(0) или комментария(1)
 */
void	ft_error_length(int f)
{
	if (f == 0) {
		ft_putstr_fd("Champion name too long (Max length ", 2);
		ft_putnbr_fd(PROG_NAME_LENGTH, 2);
		ft_putendl_fd(")", 2);
	}
	else if (f == 1) {
		ft_putstr_fd("Champion comment too long (Max length ", 2);
		ft_putnbr_fd(COMMENT_LENGTH, 2);
		ft_putendl_fd(")", 2);
	}
	exit(1);
}