//
// Created by pbelo on 12.09.2020.
//
#include "asm.h"
#include "../libft/includes/libftprintf.h"

int 	skip_invisible_character(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		parse_line_header(char *line_split, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("vsya stroka %s\n", line_split);

	while (line_split[j] == ' ' || line_split[j] == '\t')
		j++;
	while (line[i] != '\0')
	{
		if (line[i] != line_split[j]) {
			ft_exit(LEX_ERR);
		}
		i++;
		j++;
	}
	while (line_split[j] != '"')
	{
		if (line_split[j] != ' ' && line_split[j] != '\t')

			ft_exit(SYN_ERR);
		j++;
	}
	return (j);
}

int     ft_parse_header(char **split, t_header *header)
{
	char 	**line_header;
    int		line_number;

    line_number = 1;
    line_header = NULL;


	while (*split[0] == COMMENT_CHAR || *split[0] == '\n') {
		line_number++;
		split++;
	}
	line_header = ft_strmultsplit(*split, ' ', '\t');
	ft_printf("seychas na %s\n", *split);
	for (int i = 0; i < 7; ++i) {
		ft_printf("{%s}\n", line_header[i]);
	}
	///
	if (parse_line_header(*split, NAME_CMD_STRING) != 0)
	{
		ft_memcpy(header->prog_name, line_header[1], ft_strlen(line_header[1]));
		split++;
		line_number++;
	}
	while (*split[0] == COMMENT_CHAR || *split[0] == '\n') {
		line_number++;
		split++;
	}
	if (parse_line_header(*split, COMMENT_CMD_STRING) != 0)
	{
		split++;
		line_number++;
	}
	while (*split[0] == COMMENT_CHAR || *split[0] == '\n')
	{
		line_number++;
		split++;
	}

	ft_printf("line_number = %d\n",line_number);








//    while (*split != NULL)
//    {
//
//        if (ft_strstr(*split, ".name"))
//            ft_memcpy(header->prog_name, *split, ft_strlen(*split));
//        ft_printf("i = %d",
//        ft_printf("%s\n", header->prog_name);
//        split++;
//        i++;
//    }
    return (line_number);
}

//int     ft_parse_header(char **split, t_header *header)
//{
//	int i = 0;
//    header->prog_size = 800;
//	while (*split != NULL)
//	{
//		while (*split[0] == '#')
//			split++;
//		if (ft_strstr(*split, ".name"))
//			ft_memcpy(header->prog_name, *split, ft_strlen(*split));
//		ft_printf("i = %d", is_name(*split));
////        ft_printf("%s\n", header->prog_name);
//		split++;
//		i++;
//	}
//	return (i);
//}

