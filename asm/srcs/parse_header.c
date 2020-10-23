 //
 // Created by pbelo on 12.09.2020.
 //
 #include "asm.h"
 #include "../libft/includes/libftprintf.h"

 //
// Created by pbelo on 12.09.2020.
//
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
//		return (ft_strlen_char((line + j), '"'));
	 }

	 return (-1);
 }

/*
 * line - вся строка
 * f = 0 - name
 * f = 1 - comment
 * num_line - номер строки
 * ind - индекс в строке
 */

 int     ft_parse_header(t_header *header, char *line, int f, int num_line)
 {
	 int 	ind;
	 int 	start;

	 ind = 0;
	 start = 0;
	 while (line[ind] == ' ' || line[ind] == '\t')
		 ind++;
	 if (f == 0)
	 {
		 if (ft_strncmp((line + ind),NAME_CMD_STRING, (sizeof(NAME_CMD_STRING) - 1)) == 0)
		 {
			 start = parse_line_header(line, NAME_CMD_STRING, (ind + sizeof(NAME_CMD_STRING)), num_line);
			 ft_strncpy(header->prog_name, (line + start), ft_strlen_char((line + start), '"'));
			 header->is_name = 1;
		 }
		 else {
			 ft_printf("AAAAAAA %s-%d-size%zu\n", (line + ind), ft_strncmp((line + ind),NAME_CMD_STRING, sizeof(NAME_CMD_STRING)), sizeof(NAME_CMD_STRING));
			 ft_error(LEX_ERR, NULL, num_line, ind);
		 }
	 }
	 else if (f == 1)
	 {
		 if (ft_strncmp((line + ind),COMMENT_CMD_STRING, sizeof(COMMENT_CMD_STRING)) == 0)
		 {
			 start = parse_line_header(line, NAME_CMD_STRING, (ind + sizeof(NAME_CMD_STRING)), num_line);
			 ft_strncpy(header->comment, (line + start), ft_strlen_char((line + start), '"'));
			 header->is_comment = 1;
		 }
		 else
			 ft_error(LEX_ERR, NULL, num_line, ind);
	 }
	 return (0);
 }

// int 	skip_invisible_character(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t')
// 		i++;
// 	return (i);
// }

// int		parse_line_header(char *line_split, char *line)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	ft_printf("vsya stroka %s\n", line_split);

// 	while (line_split[j] == ' ' || line_split[j] == '\t')
// 		j++;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] != line_split[j]) {
// 			ft_exit(LEX_ERR);
// 		}
// 		i++;
// 		j++;
// 	}
// 	while (line_split[j] != '"')
// 	{
// 		if (line_split[j] != ' ' && line_split[j] != '\t')

// 			ft_exit(SYN_ERR);
// 		j++;
// 	}
// 	return (j);
// }

// int     ft_parse_header(char **split, t_header *header)
// {
// 	char 	**line_header;
//     int		line_number;

//     line_number = 1;
//     line_header = NULL;


// 	while (*split[0] == COMMENT_CHAR || *split[0] == '\n') {
// 		line_number++;
// 		split++;
// 	}
// 	line_header = ft_strmultsplit(*split, ' ', '\t');
// 	ft_printf("seychas na %s\n", *split);
// 	for (int i = 0; i < 7; ++i) {
// 		ft_printf("{%s}\n", line_header[i]);
// 	}
// 	///
// 	if (parse_line_header(*split, NAME_CMD_STRING) != 0)
// 	{
// 		ft_memcpy(header->prog_name, line_header[1], ft_strlen(line_header[1]));
// 		split++;
// 		line_number++;
// 	}
// 	while (*split[0] == COMMENT_CHAR || *split[0] == '\n') {
// 		line_number++;
// 		split++;
// 	}
// 	if (parse_line_header(*split, COMMENT_CMD_STRING) != 0)
// 	{
// 		split++;
// 		line_number++;
// 	}
// 	while (*split[0] == COMMENT_CHAR || *split[0] == '\n')
// 	{
// 		line_number++;
// 		split++;
// 	}

// 	ft_printf("line_number = %d\n",line_number);








// //    while (*split != NULL)
// //    {
// //
// //        if (ft_strstr(*split, ".name"))
// //            ft_memcpy(header->prog_name, *split, ft_strlen(*split));
// //        ft_printf("i = %d",
// //        ft_printf("%s\n", header->prog_name);
// //        split++;
// //        i++;
// //    }
//     return (line_number);
// }

// //int     ft_parse_header(char **split, t_header *header)
// //{
// //	int i = 0;
// //    header->prog_size = 800;
// //	while (*split != NULL)
// //	{
// //		while (*split[0] == '#')
// //			split++;
// //		if (ft_strstr(*split, ".name"))
// //			ft_memcpy(header->prog_name, *split, ft_strlen(*split));
// //		ft_printf("i = %d", is_name(*split));
// ////        ft_printf("%s\n", header->prog_name);
// //		split++;
// //		i++;
// //	}
// //	return (i);
// //}

