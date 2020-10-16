//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"
#include "../includes/error.h"



int		parse_line_header(char *line_name, char *line)
{
	int i;

	i = 0;
	ft_printf("vsya stroka %s\n", line_name);
	while (line[i] != '\0')
	{
		if (line[i] != line_name[i]) {
			ft_exit(LEX_ERR);
		}
			i++;
	}
	while (line_name[i] != '"')
	{
		if ((line_name[i] != ' ' && line_name[i] != '\t') || line_name[i] == COMMENT_CHAR || line_name[i] == ALT_COMMENT_CHAR)
			ft_exit(SYN_ERR);
		i++;
	}
	return (i);
}

int     ft_parse_header(char **split, t_header *header)
{
	char 	**line_header;
    int		line_number;

    line_number = 1;
    line_header = NULL;

//    header->prog_size = 800;??
	while (*split[0] == '#' || *split[0] == '\n') {
		line_number++;
		split++;
	}
	line_header = ft_strsplit(*split, '"');
//	if (line_header )
	if (parse_line_header(*split, NAME_CMD_STRING) != 0)
	{
		ft_memcpy(header->prog_name, line_header[1], ft_strlen(line_header[1]));
		split++;
		line_number++;
	}
//	free_table(line_header,);
	while (*split[0] == '#' || *split[0] == '\n') {
		line_number++;
		split++;
	}
	if (parse_line_header(*split, COMMENT_CMD_STRING) != 0)
	{
		split++;
		line_number++;
	}
	while (*split[0] == '#' || *split[0] == '\n')
	{
		line_number++;
		split++;
	}

	ft_printf("line_number = %d\n",line_number);
	ft_printf("seychas na %s\n", *split);








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

