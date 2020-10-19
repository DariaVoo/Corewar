/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:52:46 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/10 16:30:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "vm_error.h"
# include "parse_n.h"
# include "op.h"
# include "../../lib/include/libft.h"
# include "../../lib/include/ft_printf.h"
# include "../../lib/include/get_next_line.h"

# include <stdio.h> /* perror */
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define INT_SIZE 4
///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;

typedef struct s_champion	t_champion;

typedef struct				s_carriage
{
	int32_t					regs[REG_NUMBER];
	int						cycle_to_die;
	uint8_t					command;
	int						carry;
	uint8_t					*position;
	struct s_carriage		*next;
}							t_carriage;

typedef struct				s_vm
{
	uint8_t					arena[MEM_SIZE];
	uint32_t				dump_cycle_to_die;
	int						count_champs;
	t_champion				*champs;
	struct s_carriage		*cursor;
}							t_vm;


typedef struct				s_op
{
	char					*name_oper;
	int						col_arg;
	int						*type_arg;
	int						opcode;
	int						cycle_to_die;
	char					*comment;
	int						change_carry;
	int						code_type_arg;
	int	(*func)(uint32_t arg1, uint32_t arg2, uint32_t arg3, t_vm *vm);
}							t_op;

struct						s_champion
{
	t_header				header;
	int						id;
	uint8_t					*code; // пока просто запиши весь код чемпиона сюда
	struct s_champion		*next;
};

/* VIRTUAL MACHINE MAIN */
t_vm						*create_vm(int count_champs);
t_champion					*init_champ(int id);
t_vm						*init_vm(size_t col_champs);
void						init_arena(t_vm *vm);
t_carriage					*init_carrige(int id);
t_champion					*parse_champion(char *chmp_file_name, int id);
t_champion					*valid_champions(char **chmp_file_name, size_t col_champs);
t_carriage					*valid_cursor(t_champion *players);

/* EXTRA FUNC */
void						exit_error(const char *str);

#endif
