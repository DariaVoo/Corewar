#ifndef ASM_H
# define ASM_H


# include <stdio.h> // JUST FOR TESTS
# include "op.h"
# include "error.h"
# include "libftprintf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_ARGS 3

#define MAX_OP 17

# define BUFF 4096

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[35;1m"
# define EOC		"\e[0m"

/*
 ** Error codes
 */
# define TOO_MANY_ARGS 2
# define FEW_ARGS 3
# define INVALID_TYPE 4



// ///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;


// //структура для аргумента
typedef struct s_arg
{
	int type;
	char *label;
	int size; //размер аргумента (2 или 4) нужен для получения значения
	int value; //значение, для label рассчитывается при ВТОРОМ проходе
	int arg_number; //порядковый номер аргумента, возможно, не нужен, но может пригодиться для валидации
//	int instr_num_curr; //порядковый номер текущей инструкции
//	int instr_num_to_go; //порядковый номер инструкции, к которой нужно перескачить (сложить размеры инструкций между двумя значениями)
//	int bc;
//	int id_label;
}              t_arg;

/* Алгоритм
2 прохода:
---------1 проход---------
1) парсинг name и comment
2) парсинг строки
    --парсинг и валидация лейбла, заполнение структуры лейблов
    --парсинг и валидация названия команды
    --парсинг и валидация аргументов и разделителей
3)Обработка ошибок
---------2 проход---------
1)валидация лейблов,заполнение порядкого номера инструкции, айдишника
2)после этого для каждой инструкции расчет байткода и запись в файл
*/

// t_champion *parse_champion(char *chmp_file_name);
int		check_label(char *label);

# define CH_STR 26

// VP
//typedef struct	s_flags
//{
//	int		aff; //print source file (-a in original asm for refenece)
//	int		help; //print help (usage analog)
//	int		joke; //print random joke from defined jokes
//}				t_flags;

//инструкции, данные в задании (Операции и их аргументы)
typedef struct s_instr
{
    char *name; //название инструкции
//    int bc; //байткод, но надо подумать в чем его хранить (код операции)
    int id; //id инструкции и связующее звено между массивом считываемых инструкций и данной структуры
	int		size;
    //здесь нужно прописать возможный размер, количество аргументов и тп, все то, что дано в таблице
//	char	arguments[3];
//
//	int		labels_id[3]; // ИЛИ ВСЕ-ТАКИ 3?
//    int num_args; // КОЛ-ВО АРГУМЕНТОВ

	t_arg args[3];
	char *label;
	int id_instr;//номер от 0 до 15

    // t_name_args type[3];
    int 		sum_size;

}               t_instr;

//считанные лейблы
//список
typedef struct s_label
{
    char	*name;
    // t_championstr championstr;
    int		label_id; //id лейбла
    int		label_row; // строка, на которой находится лейбл
	int		instr_id;
    // int id; //id инструкции в t_instr заполняется при ВТОРОМ проходе
    // int number; //number в t_champinstr заполняется при ВТОРОМ проходе
    //t_arg *args;
	struct s_label		*next;
}               t_label;

typedef struct s_data
{
	int			read_fd;
	int			write_fd;
	int			file_size;
	int			line_count; // 0 изначально 
	// char		*name;
	// char		*comment;
    //либо t_header;

//	int			*instructions;
	t_label		*label;
    t_header    *header;

    t_instr		*instrs;
	int			instr_num;
	int 		*symbol_number;
	char		*split; //current line
	char		*all_labels; //for validation
}				t_data;

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

const t_op					g_op_tab[MAX_OP];

/*
 ** util functions
 */
void    ft_exit(char *str);
void	free_close_fd_put_error(char *err, char *line, t_data *data, int ind_str);
// NEW LEAF
char    *ft_saved_name(char *str);
void    ft_close_fd(int a, int b);
void 	skip_spaces(char *split, int *i);
int		ft_is_number(char *name);
int		massiv_len(char **args);
int		get_number_of_lines(char *str, t_data *data);

/*
 ** init functions
 */
void	ft_init_structs(t_data *data, int instr_num);

/*
 ** read functions
 */
char	**ft_file_read(char **split, char *filename);
int		ft_line_parser(char *str, t_data *data);
int		ft_is_comment(char *str);
/*
 ** parse functions
 */
int     ft_parse_header(t_header *header, char *line, int num_line);
void    ft_read_file(t_data *data);
void	ft_parse_body(char *str, t_data *data);
char	*ft_parse_label(char *split, int *i);
void	ft_parse_function(char *split, int *i, t_data *data);
void	ft_parse_args(char *split, int *i, t_data *data);
void	ft_count_size(t_data *data);

/*
 ** check functions
 */
void    ft_check_header_file(void);
void	ft_check_args(char **av, int ac);
void    ft_check_filename(char *str);
// void    ft_check_flags(char *str);
int		check_label(char *label);
// NEW LEAF
void    ft_check_all_data(t_data *data);
void    ft_check_flags(char ***av, int ac);
int 	valid_args(t_data *data);

/*
 ** free_functions
 */
void	free_massiv(char **massiv);
void	free_data(t_data *data);

/*
** write funcs
*/

char	*ft_cor_extension(char *file);
int 	writing_to_file(t_data *data, int fd);
int 	writing_header_to_file(char *str, int size, int fd, int f);
void	write_magic_fd(long nb, int fd);
void	write_hex_fd(long nbr, int fd);




#endif