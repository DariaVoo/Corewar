#include "asm.h"
#include "error.h"
#include "../libft/includes/libftprintf.h"

/*
 * Проверка на кавычкатость
 * В строке две кавычки
 * после имени и до первой кавычки только пробелы и табы
 * после второй кавычки только только пробелы и табы, либо комментарий
 * если все ок, вернет индекс после первой кавычки (int start)
 *
 */
 int 	valid_quotes(char *line, int ind, int num_line)
 {
	 int		i;
	 int 	quotes;
	 int 	start;

	 i = ind;
	 quotes = 0;
	 start = -1;
	 while (line[i] == ' ' || line[i] == '\t')
		 i++;
	 /*
	  * проверка кавычек
	  */
	 if (line[i] == '"')
	 {
		 quotes++;
		 i++;
		 start = i;
		 while (line[i] != '"' && line[i] != '\0')
			 i++;
		 if (line[i] == '"')
			 quotes++;
		 i++;
		 if (quotes != 2)
			 ft_error(LEX_ERR, NULL, num_line, ind);
	 }
	 else {
		 ft_error(SYN_ERR, (line + i), num_line, i);
	 }
	 /*
	  * Проверка на символы после кавычек
	  */
	 while (line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT_CHAR && line[i] != '\0')
	 {
		 if (line[i] != ' ' && line[i] != '\t')
			 ft_error(SYN_ERR, (line + i), num_line, i);
		 i++;
	 }
	 return (start);
 }

/*
 * количество символов до ch(вторая кавычка)
 */

 size_t	ft_strlen_char(const char *str, char ch)
 {
	 size_t	i;

	 i = 0;
	 if (!str)
		 return (0);
	 while (str[i] != ch && str[i] != '\0')
		 i++;
	 return (i);
 }

/*
 * *line - вся строка
 * ind - индекс в строке(после name или comment)
 */

 int		parse_line_header(char *line, char *def, int ind, int num_line)
 {
	 int		i;
	 int		j;
	 char 	*str;

	 i = 0;
	 j = valid_quotes(line, ind, num_line);
	 str = NULL;
	 ft_printf("vsya stroka %s\n", line);


	 if (j != -1)
	 {
		 return (j);
	 }

	 return (-1);
 }

/*
 * line - вся строка
 * num_line - номер строки
 * ind - индекс в строке
 */

 int     ft_parse_header(t_header *header, char *line, int num_line)
 {
 	write(1, "AAAA\n", 5);
	 int 	ind;
	 int 	start;

	 ind = 0;
	 start = 0;
	 while (line[ind] == ' ' || line[ind] == '\t')
		 ind++;

	 if (!header->is_name && !ft_strncmp((line + ind),NAME_CMD_STRING, (sizeof(NAME_CMD_STRING) - 1)))
	 {
		 start = parse_line_header(line, NAME_CMD_STRING, (ind + sizeof(NAME_CMD_STRING)), num_line);
		 if (ft_strlen_char((line + start), '"') > PROG_NAME_LENGTH)
			 ft_error_length(0);
		 ft_strncpy(header->prog_name, (line + start), ft_strlen_char((line + start), '"'));
		 header->is_name = 1;
	 }
	 else if (!header->is_comment && !ft_strncmp((line + ind),COMMENT_CMD_STRING, sizeof(COMMENT_CMD_STRING)))
	 {
		 start = parse_line_header(line, COMMENT_CMD_STRING, (ind + sizeof(COMMENT_CMD_STRING)), num_line);
		 if (ft_strlen_char((line + start), '"') > COMMENT_LENGTH)
			 ft_error_length(1);
		 ft_strncpy(header->comment, (line + start), ft_strlen_char((line + start), '"'));
		 header->is_comment = 1;
	 }
	 else {
		 ft_printf("AAAAAAA: %s-%d-size%zu\n", (line + ind), ft_strncmp((line + ind),COMMENT_CMD_STRING, sizeof(COMMENT_CMD_STRING)), sizeof(COMMENT_CMD_STRING));
		 ft_error(LEX_ERR, NULL, num_line, ind);
	 }
	 return (0);
 }
