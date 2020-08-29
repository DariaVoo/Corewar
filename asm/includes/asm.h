#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libftprintf.h"

# define BUFF 4096

// ///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;

typedef struct		s_op
{
	char			*name_oper;
	int				col_arg;
	int				*type_arg;
	int				opcode;
	int				cycle_to_die;
	char			*comment;
	int				change_carry;
	int				code_type_arg;
}					t_op;

typedef struct		s_champion
{
	t_header	header;
	
	char		*code; // пока просто запиши весь код чемпиона сюда
}					t_champion;


t_champion *parse_champion(char *chmp_file_name);

#endif