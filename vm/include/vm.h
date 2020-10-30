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

# define TRUE 1
# define FALSE 0
# define OPCODE_SIZE	1
# define MAX_ARGS		3
# define TYPE_ARGS_SIZE	1

# define REG_SIZE_BYTE	1
# define DIR_SIZE_BYTE	4
# define IND_SIZE_BYTE	2

# define THR_BITS		0x03

# define INT_SIZE 4

typedef struct				s_arg
{
	uint8_t	type;
	int32_t	value;
}							t_arg;

typedef struct				s_carriage
{
	uint32_t				regs[REG_NUMBER];
	uint16_t				cycle_to_die;
	int						program_counter;
	int						live;
	int						carry;
	struct s_arg			*args;
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
	int32_t					cycle_dump;
	uint8_t					arena[MEM_SIZE];
	uint8_t					count_champs;
}							t_vm;

// typedef struct				s_op
// {
// 	char					*name_oper;
// 	int						col_arg;
// 	int						*type_arg;
// 	int						opcode;
// 	int						cycle_to_die;
// 	char					*comment;
// 	int						change_carry;
// 	int						code_type_arg;
// 	int	(*func)(uint32_t arg1, uint32_t arg2, uint32_t arg3, t_vm *vm);
// }							t_op;

void				game(t_vm *vm);

/* VIRTUAL MACHINE */
void				init_vm(t_vm *vm, t_champion *champ[], t_carriage *carriage);
void				init_arena(t_vm *vm);

/* CARRIAGE */
void				set_starter_kit_carriage(t_carriage **carriage, t_champion *champ[]);
void				add_carriage(t_carriage **carriage, t_champion *champ);

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
int32_t				get_number_dump_cycle();
void				init_arrptr(void **array, uint32_t size);
void				exit_error(const char *str);

/* DEBUG */
void				debug_print_carriage(t_vm *vm);
void				champ_print(t_champion *ptr);
void				arena_print(uint8_t *arena);

/* VISUALIZATION */
void				visualisation();



/* OPERATIONS */
int32_t				get_args(t_arg **args, uint8_t *arena, t_carriage *carriage);
int					op_live(uint8_t *arena, t_carriage *carriage);
int					op_ld(uint8_t *arena, t_carriage *carriage);
int					op_st(uint8_t *arena, t_carriage *carriage);
int					op_add(uint8_t *arena, t_carriage *carriage);
int					op_sub(uint8_t *arena, t_carriage *carriage);
int					op_and(uint8_t *arena, t_carriage *carriage);
int					op_or(uint8_t *arena, t_carriage *carriage);
int					op_xor(uint8_t *arena, t_carriage *carriage);
int					op_zjmp(uint8_t *arena, t_carriage *carriage);
int					op_ldi(uint8_t *arena, t_carriage *carriage);
int					op_sti(uint8_t *arena, t_carriage *carriage);
int					op_fork(uint8_t *arena, t_carriage *carriage);
int					op_lld(uint8_t *arena, t_carriage *carriage);
int					op_lldi(uint8_t *arena, t_carriage *carriage);
int					op_lfork(uint8_t *arena, t_carriage *carriage);
int					op_aff(uint8_t *arena, t_carriage *carriage);

#endif
