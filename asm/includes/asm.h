/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:39:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 21:43:28 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "error.h"
# include "libftprintf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define LOL			"Invalid indirect arg, it is not a number"
# define FT_PARSE_ARGS1	"Invalid number of args(too many)"
# define FT_PARSE_ARGS2	"Invalid number of args(few)"
# define MAX_ARGS		3
# define MAX_OP			17
# define BUFF			4096
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define PURPLE			"\033[35;1m"
# define EOC			"\e[0m"
# define LEN_N			sizeof(N_CMD_STR)
# define LEN_C			sizeof(C_CMD_STR)
# define TOO_MANY_ARGS	2
# define FEW_ARGS		3
# define INVALID_TYPE	4
# define MAX_ARGS		3
# define MAX_OP			17
# define BUFF 			4096
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define PURPLE			"\033[35;1m"
# define EOC			"\e[0m"
# define TOO_MANY_ARGS	2
# define FEW_ARGS		3
# define INVALID_TYPE	4
# define CH_STR			26

typedef struct			s_arg
{
	int					type;
	char				*label;
	int					size;
	int					value;
	int					arg_number;
}						t_arg;

typedef struct			s_sort
{
	char				*label;
	struct s_sort		*next;
}						t_sort;

typedef struct			s_instr
{
	char				*name;
	int					id;
	int					size;
	t_arg				args[3];
	char				*label;
	int					id_instr;
	int					sum_size;
	t_sort				*labels;
}						t_instr;

typedef struct			s_label
{
	char				*name;
	int					label_id;
	int					label_row;
	int					instr_id;
	struct s_label		*next;
}						t_label;

typedef struct			s_data
{
	int					read_fd;
	int					write_fd;
	int					file_size;
	int					line_count;
	t_label				*label;
	t_header			*header;
	t_instr				*instrs;
	int					instr_num;
	int					*symbol_number;
	char				*split;
	char				*all_labels;
	char				*file_name;
}						t_data;

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

const t_op				g_op_tab[MAX_OP];

int						check_label(char *label);
t_sort					*add_block(char *label);
void					push_end(char *label, t_sort **sort);
void					sort_del(t_sort **sort);
void					ft_exit(char *str);
void					free_fd_put_error(char *err, char *line, \
													t_data *data, int ind_str);
char					*ft_saved_name(char *str);
void					ft_close_fd(int a, int b);
void					skip_spaces(char *split, int *i);
int						ft_is_number(char *name);
int						massiv_len(char **args);
int						get_number_of_lines(t_data *data);
void					ft_init_structs(t_data *data, int instr_num);
int						ft_line_parser(char *str, t_data *data);
int						ft_is_comment(char *str);
int						ft_parse_header(t_header *header, char *line, \
																int num_line);
void					ft_read_file(t_data *data);
void					ft_parse_body(char *str, t_data *data);
char					*ft_parse_label(char *split, int *i);
void					ft_parse_function(char *split, int *i, t_data *data);
void					ft_parse_args(char *split, int *i, t_data *data);
void					ft_count_size(t_data *data);
void					extract_number(char *arg, t_data *data, int num_arg);
void					ft_check_filename(char *name);
void					ft_check_header_file(void);
void					ft_check_args(char **av, int ac);
void					ft_check_filename(char *str);
int						check_label(char *label);
void					ft_check_all_data(t_data *data);
void					ft_check_flags(char ***av, int ac);
int						valid_args(t_data *data);
void					free_massiv(char **massiv);
void					free_data(t_data *data);
void					ft_cor_extension(char *file, t_data *data);
int						writing_to_file(t_data *data, int fd);
int						writing_header_to_file(char *str, int size, int fd, \
																		int f);
void					write_magic_fd(long nb, int fd);
void					write_hex_fd(long nbr, int fd);
int						ft_skip(char *line, int id);
void					sum_size(t_data *data);
void					write_hex_fd(long nbr, int fd);
void					write_magic_fd(long nb, int fd);
int						writing_to_file(t_data *data, int fd);
void					write_size_fd(long nb, int fd);
void					write_args_to_fd(t_data *data, int ind_instr, int code_op, int fd);
int						size_to_label(t_data *data, t_arg *args, int cur_size, int tdir_size);
int						code_args(t_arg *args);
int						write_code_dir(int args, int type, int fd, int tdir_size);
int						code_operation(char *name);
int						write_header_to_file(char *str, int size, int fd, int f);
void					write_instrs_to_fd(t_data *data, int fd);

#endif
