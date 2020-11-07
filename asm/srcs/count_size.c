#include "asm.h"
#include "../libft/includes/libftprintf.h"

void	ft_count_size(t_data *data)
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
	int size;
	int t_dir_size;

	size = 2;
	i = 0;
	t_dir_size = 4;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].bit_type == 0)
		size--;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].tdir_size == 1)
		t_dir_size = 2;
	while (i < g_op_tab[data->instrs[data->instr_num].id_instr].col_args)
	{
		if (ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_DIR") == 0)
			size+=t_dir_size;
		else if (ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_IND") == 0)
			size+=2;
		else if (ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_REG") == 0)
			size++;
		i++;
	}
	data->instrs[data->instr_num].size = size;
}