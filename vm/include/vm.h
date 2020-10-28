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

# include "parse_args.h"
# include "vm_error.h"
# include "op.h"
# include "../../lib/include/libft.h"
# include "../../lib/include/ft_printf.h"
# include "../../lib/include/get_next_line.h"

# include <stdio.h> /* perror */
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define INT_SIZE 4

typedef struct				s_carriage
{
	uint64_t				current_pos;
	uint32_t				regs[REG_NUMBER];
	int						cycle_to_die;
	int						live;
	int						carry;
	int						program_counter;
	struct s_carriage		*next;
	uint8_t					opcode;
}							t_carriage;

typedef struct				s_champion
{
	t_header				header;
	int						id;
	uint8_t					*code; // пока просто запиши весь код чемпиона сюда
	struct s_champion		*next;
}							t_champion;

typedef struct				s_vm
{
	t_champion				**champ;
	struct s_carriage		*carriage;
	int32_t					dump_cycle;
	uint8_t					arena[MEM_SIZE];
	uint8_t					count_champs;
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

/* VIRTUAL MACHINE */
void				init_vm(t_vm *vm, t_champion *champ[], t_carriage *carriage);
void				init_arena(t_vm *vm);

/* CARRIAGE */
void				set_starter_kit_carriage(t_carriage **carriage, char *champ_names[]);
void				add_carriage(t_carriage **carriage, uint8_t id);

/* CHAMPIONS */
void				parse_files(t_champion *champ[], char *champ_names[]);
t_champion			*parse_champ_file(const char *champ_name, uint8_t id);
t_champion			*create_champ(int id);

/* PARSING ARGS */
void				parse_args(char *champ_names[], char **argv);
uint8_t				parse_dump_flag(char *splited_argv[]);
int32_t				update_dump_flag(const int32_t dump_flag);
uint8_t				parse_n_flag(char **splited_argv);
int8_t				update_n_flag(const int8_t shift);
void				parse_champ_name(const char *argv_name, char *champ_name[]);



/* EXTRA FUNC */
uint8_t				get_number_of_players();
void				init_arrptr(void **array, uint32_t size);
void				*node_malloc(size_t size);
void				exit_error(const char *str);
void				champ_print(t_champion *ptr);
void				arena_print(uint8_t *arena);

#endif
