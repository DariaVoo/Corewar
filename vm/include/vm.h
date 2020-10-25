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
	int32_t					regs[REG_NUMBER];
	int						cycle_to_die;
	int						live;
	uint8_t					opcode;
	int						carry;
	int						program_counter;
	struct s_carriage		*next;
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
	t_champion				*champs;
	struct s_carriage		*carriage;
	uint8_t					arena[MEM_SIZE];
	uint8_t					count_champs;
	uint8_t					dump_cycle_to_die;
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
void				init_vm(t_vm *vm);

/* PARSING ARGS */
void				init_champion_names(char *champion_names[MAX_PLAYERS]);
void				parse_args(t_vm *vm, \
								char *champion_names[MAX_PLAYERS], \
								char **argv);
uint8_t				parse_dump_flag(t_vm *vm, char **splited_argv);
uint8_t				is_dump_flag(const char *str);
uint8_t				parse_n_flag(char **splited_argv);
uint8_t				is_n_flag(const char *argv_str);
int8_t				update_n_flag(const int8_t shift);
void				parse_champion_name(const char *argv_name, \
										char **champion_name);
void				merge_champion_names(char *champion_names[MAX_PLAYERS],
								char *unranking_champion_names[MAX_PLAYERS]);
int8_t				get_number_of_players(char *champion_names[MAX_PLAYERS]);

/* CHAMPIONS */
t_champion			*init_champ(int id);
void				init_arena(t_vm *vm);
t_carriage			*init_carriage(int col_champs, int id);
t_champion			*parse_champion(char *chmp_file_name, int id);
t_champion			*valid_champions(char **chmp_file_name, size_t col_champs);
t_carriage			*valid_carriage(t_champion *players, int col_champs);

/* EXTRA FUNC */
void				exit_error(const char *str);
void				champ_print(t_champion *ptr);
void				arena_print(uint8_t *arena);

#endif
