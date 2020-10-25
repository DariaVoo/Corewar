#define LEX_ERR			"Lexical error \n" 		//потом убрать \n
#define SYN_ERR			"Syntax error \n"
#define USAGE			"Usage: ./asm [options] <file.s>\n"
#define HEADER_ERR		"Error: wrong header file\n"
#define EXEC_MAGIC_ERR	"Error: COREWAR_EXEC_MAGIC > UINT_MAX\n"
#define MALLOC_ERR      "Error: malloc error\n"

void    ft_error(char *err, char *line, int num_str, int ind_str);
void	ft_error_length(int f);