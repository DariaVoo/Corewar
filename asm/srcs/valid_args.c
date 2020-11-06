#include "asm.h"
#include "../libft/includes/libftprintf.h"
#define MAX_ARGS 3

typedef struct				s_op
{
	char					*name_oper;
	int						col_args;
	int						type_arg[MAX_ARGS];
	int						opcode;
	int						cycle_to_die;
	char					*comment;
	int						bit_type;
	int						tdir_size;
}							t_op;



int valid_args(t_data *data, t_instr instr[16])
{
	t_op		g_op_tab[MAX_OP] =
			{
					{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
					{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
					{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
					{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
					{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
					{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
							"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
					{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
							"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
					{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
							"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
					{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
					{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
							"load index", 1, 1},
					{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
							"store index", 1, 1},
					{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
					{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
					{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
							"long load index", 1, 1},
					{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
					{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
					{"gtmd", 1, {T_REG}, 17, 5, "gtmd", 1, 0}
			};

	int i;
	int num_args;

	i = 0;
	num_args = g_op_tab[data->instrs[data->instr_num].id_instr];
//	num_args = instr[body.id_instr].num_args;
	//проверка количества аругументов
	while (i < 3)
	{
		if ((num_args - 1) == i)
		{
			if (i < 3 && body.args[i].type != NULL)
			{
				//количество аргументов больше, чем нужно
				exit(1);
			}
			else
				return (1);
		}
		if (body.args[i].type != NULL &&
		!((ft_strcmp(body.args[i].type, "T_DIR") == 0) && instr[body.id_instr].type[i].t_dir == 1) &&
		!((ft_strcmp(body.args[i].type, "T_IND") == 0) && instr[body.id_instr].type[i].t_ind == 1) &&
		!((ft_strcmp(body.args[i].type, "T_REG") == 0) && instr[body.id_instr].type[i].t_reg == 1))
		{
			//неправильный тип аргумента или аргументов слишком мало
			exit(1);
		}
		i++;
	}
	return (0);
}