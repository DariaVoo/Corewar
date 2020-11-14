/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:46:38 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/14 21:26:22 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "libftprintf.h"

void 	sin_err(char *line, int i, int num_lin)
{
	while (line[i] != COMMENT_CHAR && \
			line[i] != ALT_COMMENT_CHAR && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			ft_error(SYN_ERR, (line + i), num_lin, i + 1);
		i++;
	}
}


int		valid_quotes(char *line, int ind, int num_line)
{
	int		i;
	int		quotes;
	int		start;

	i = ind;
	quotes = 0;
	start = -1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
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
			ft_error(LEX_ERR, NULL, num_line, ind + 1);
	}
	else
		ft_error(SYN_ERR, (line + i), num_line, i + 1);
	sin_err(line, i, num_line);
	return (start);
}

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

int		parse_line_header(char *line, char *def, int ind, int num_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = valid_quotes(line, ind, num_line);
	str = NULL;
	if (j != -1)
		return (j);
	return (-1);
}

int		ft_parse_header(t_header *header, char *line, int num_line)
{
	int		id;
	int		start;

	id = 0;
	start = 0;
	while (line[id] == ' ' || line[id] == '\t')
		id++;
	if (!header->is_name && !ft_strncmp((line + id), NAME_CMD_STRING, (LEN_N - 1)))
	{
		start = parse_line_header(line, NAME_CMD_STRING, (id + LEN_N), num_line);
		if (ft_strlen_char((line + start), '"') > PROG_NAME_LENGTH)
			ft_error_length(0);
		ft_strncpy(header->prog_name, (line + start), ft_strlen_char((line + start), '"'));
		header->is_name = 1;
	}
	else if (!header->is_comment && !ft_strncmp((line + id), COMMENT_CMD_STRING, LEN_C - 1))
	{
		start = parse_line_header(line, COMMENT_CMD_STRING, (id + LEN_C), num_line);
		if (ft_strlen_char((line + start), '"') > COMMENT_LENGTH)
			ft_error_length(1);
		ft_strncpy(header->comment, (line + start), ft_strlen_char((line + start), '"'));
		header->is_comment = 1;
	}
	else
		ft_error(LEX_ERR, NULL, num_line, id + 1);
	return (0);
}
