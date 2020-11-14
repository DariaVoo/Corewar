/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:52:46 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 16:45:03 by qjosmyn          ###   ########.fr       */
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

# include <stdio.h>
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

# define FIRST			0
# define SECOND			1
# define THIRD			2
# define OPCODE_ZJMP	9

# define THR_BITS		0x03

# define INT_SIZE		4

typedef struct			s_arg
{
	uint8_t				type;
	int32_t				value;
}						t_arg;

typedef struct			s_carriage
{
	int32_t				regs[REG_NUMBER];
	uint16_t			cycle_to_die;
	int16_t				program_counter;
	int					live;
	int					carry;
	struct s_arg		*args;
	struct s_carriage	*next;
	struct s_carriage	*prev;
	uint8_t				opcode;
	int32_t				last_live;
	int32_t				player_id;
}						t_carriage;

typedef struct			s_champion
{
	t_header			header;
	int					id;
	int32_t				last_live;
	int32_t				curr_lives_num;
	int32_t				prev_lives_num;
	uint8_t				*code;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_vm
{
	t_champion			**champ;
	struct s_carriage	*carriage;
	uint8_t				*arena;
	int32_t				cycle_dump;
	uint8_t				count_champs;
	int32_t				cycle_to_die;
	int64_t				iter_from_start;
	int32_t				cycle_after_check;
	int32_t				check_num;
	int32_t				lives_num;
	int32_t				carriage_num;
	t_champion			*last_alive;
}						t_vm;

typedef struct			s_op
{
	char				*name_oper;
	int					col_args;
	int					type_arg[MAX_ARGS];
	int					opcode;
	int					cycle_to_die;
	char				*comment;
	int					bit_type;
	int					tdir_size;
}						t_op;

typedef struct			s_op_func
{
	void				(*func)(t_vm *vm, t_carriage *carriage);
}						t_op_func;


/*
** VIRTUAL MACHINE
*/
void					init_vm(t_vm *vm, t_champion *champ[], uint8_t *arena, \
								t_carriage *carriage);
void					init_arena(uint8_t *arena, t_champion *champ[]);
void					game(t_vm *vm);
void					game_intro_msg(t_vm *vm);
void					game_outro_msg(t_vm *vm);

/*
** CARRIAGE
*/
void					set_starter_kit_carriage(t_carriage *carriage[], \
												uint8_t *arena);
void					add_carriage(t_carriage **carriage, uint8_t *arena, \
										uint8_t id);
t_carriage				*copy_carriage(t_carriage *carriage);

/*
** CHAMPIONS
*/
void					parse_files(t_champion *champ[], char *champ_names[]);
t_champion				*parse_champ_file(const char *champ_name, uint8_t id);
t_champion				*create_champ(int id);

/*
** PARSING ARGS
*/
void					parse_args(char *champ_names[], char **argv);
uint8_t					parse_dump_flag(char *splited_argv[]);
int32_t					update_dump_flag(const int32_t dump_flag);
uint8_t					parse_n_flag(char **splited_argv);
int8_t					update_n_flag(const int8_t shift);
void					parse_champ_name(const char *argv_name, \
											char *champ_name[]);
uint8_t					update_limit_number(uint8_t i);


/*
** EXTRA FUNC
*/
uint8_t					get_number_of_players();
int32_t					get_number_dump_cycle();
void					init_arrptr(void **array, uint32_t size);
void					exit_error(const char *str);

/*
** FREE FUNC
*/
void					free_arrptr(void *array[]);
void					free_champ(t_champion *champ[]);
void					free_carriage(t_carriage *carriage);
void					free_carriage_list(t_carriage **head_carriage);

/*
** DEBUG
*/
void					debug_print_carriage(t_vm *vm);
void					champ_print(t_champion *ptr);
void					arena_print(uint8_t *arena);

/*
** VISUALIZATION
*/
void					visualisation();

/*
** ARGS
*/
int32_t					get_args(t_arg *args, uint8_t *arena, \
									t_carriage *carriage, t_op *g_optab);
int32_t					get_arg(uint8_t *arena, int16_t address, \
								uint8_t type, t_op params);
t_arg					*take_args(uint8_t *arena, t_carriage *carriage, \
									int32_t num_arg);

int32_t					calc_addr(int32_t addr);
void					cycles_to_die_check(t_vm *vm);

/*
** OPERATION
*/
void					load_oper(uint8_t *arena, t_carriage *carriage);
void					execute_oper(t_vm *vm, t_carriage *carriage);
void					op_live(t_vm *vm, t_carriage *carriage);
void					op_ld(t_vm *vm, t_carriage *carriage);
void					op_st(t_vm *vm, t_carriage *carriage);
void					op_add(t_vm *vm, t_carriage *carriage);
void					op_sub(t_vm *vm, t_carriage *carriage);
void					op_and(t_vm *vm, t_carriage *carriage);
void					op_or(t_vm *vm, t_carriage *carriage);
void					op_xor(t_vm *vm, t_carriage *carriage);
void					op_zjmp(t_vm *vm, t_carriage *carriage);
void					op_ldi(t_vm *vm, t_carriage *carriage);
void					op_sti(t_vm *vm, t_carriage *carriage);
void					op_fork(t_vm *vm, t_carriage *carriage);
void					op_lld(t_vm *vm, t_carriage *carriage);
void					op_lldi(t_vm *vm, t_carriage *carriage);
void					op_lfork(t_vm *vm, t_carriage *carriage);
void					op_aff(t_vm *vm, t_carriage *carriage);

#endif
