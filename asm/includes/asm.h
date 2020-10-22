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


# define BUFF 4096

// ///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;

// typedef struct		s_op
// {
// 	char			*name_oper;
// 	int				col_arg;
// 	int				*type_arg;
// 	int				opcode;
// 	int				cycle_to_die;
// 	char			*comment;
// 	int				change_carry;
// 	int				code_type_arg;
// }					t_op;

// //структура для аргумента
// typedef struct s_arg
// {
// 	char *type;
// 	char *label;
// 	int direct; //аргумент direct - 1 или indirect - 0
// 	int size; //размер аргумента (2 или 4) нужен для получения значения
// 	int value; //значение, для label рассчитывается при ВТОРОМ проходе
// 	int arg_number; //порядковый номер аргумента, возможно, не нужен, но может пригодиться для валидации
// 	int instr_num_curr; //порядковый номер текущей инструкции
// 	int instr_num_to_go; //порядковый номер инструкции, к которой нужно перескачить (сложить размеры инструкций между двумя значениями)
// 	int bc;
// 	int reg; //если аргумент является регистром то здесь число, иначе - 0
// 	int id_label;
// }              t_arg;

// //инструкции считываемые из файла
// typedef struct s_championstr
// {
// 	char *name;
// 	// char *label;
// 	int bc; //лучше char *
// 	int number; // порядковый номер инструкции, нужен для подсчета лейбла
// 	int id;
// 	int size; //итоговый размер инструкции, нужен для подсчета лейбла(хз,
// 	// может и не надо если размер инструкций с аргументами статичен)
// 	t_arg *args;
// }               t_championstr;

// typedef struct		s_champion
// {
// 	t_header        header;
// 	t_championstr   *championstr;// пока просто запиши весь код чемпиона сюда
// }					t_champion;

// //аргументы операций
// typedef struct  s_name_args
// {
// 	int    		t_reg;
// 	int    		t_dir;
// 	int			t_ind;
// //    t_name_args	*next;
// }               t_name_args;

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

// typedef struct 	s_corewar //переименовала из body в corewar
// {
// 	int line_number;
// 	t_championstr champion_str[CH_STR]; // CH_STR?????
// 	t_label *label;
// 	t_instr instr[16];
// 	char *file;
// }				t_corewar;

// typedef struct 	s_body
// {
// 	char *name;
// 	char *label;
// 	int label_num;
// 	t_arg args[3];
// 	int line_num;
// 	int id_instr;
// }				t_body;

// VP
typedef struct	s_flags
{
	int		aff; //print source file (-a in original asm for refenece)
	int		help; //print help (usage analog)
	int		joke; //print random joke from defined jokes
}				t_flags;

//инструкции, данные в задании (Операции и их аргументы)
typedef struct s_instr
{
    char *name; //название инструкции
    int bc; //байткод, но надо подумать в чем его хранить (код операции)
    int id; //id инструкции и связующее звено между массивом считываемых инструкций и данной структуры
    //здесь нужно прописать возможный размер, количество аргументов и тп, все то, что дано в таблице
    int num_args; //номер строки
    // t_name_args type[3];
	struct s_instr		*next;

}               t_instr;

//считанные лейблы
//список
typedef struct s_label
{
    char *name;
    // t_championstr championstr;
    int label_id; //id лейбла
    int label_row; // строка, на которой находится лейбл
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
	char		*name;
	char		*comment;
    //либо t_header;
	t_instr		*instrs;
	t_label		*label;
}				t_data;




/*
 ** util functions
 */
void    ft_exit(char *str);
// NEW LEAF
char    *ft_saved_name(char *str);
void    ft_close_fd(int a, int b);

/*
 ** init functions
 */
// void    ft_init_structs(t_header *header, t_body *body);

/*
 ** read functions
 */
char	**ft_file_read(char **split, char *filename);

/*
 ** parse functions
 */
int     ft_parse_header(char **split, t_header *header);
void    ft_parse_body(char **split, int i, int all_lines);
char	**ft_strmultsplit(char const *s, char c, char ch);
// NEW LEAF
void    ft_read_file(t_data *data);

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




#endif