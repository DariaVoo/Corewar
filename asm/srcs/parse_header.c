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

void	sin_err(char *line, int i, int num_line)
{
	while (line[i] != COMMENT_CHAR && \
			line[i] != ALT_COMMENT_CHAR && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			ft_error(SYN_ERR, (line + i), num_line, i + 1);
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
		line[i] == '"' ? quotes++ : 0;
		i++;
		if (quotes != 2)
			ft_error(LEX_ERR, NULL, num_line, ind + 1);
	}
	else
		ft_error(SYN_ERR, (line + i), num_line, i + 1);
	sin_err(line, i, num_line);
	return (start);
}

static size_t	ft_strlen_char(const char *str, char ch)
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

int		ft_parse_header(t_header *head, char *ln, int num_line)
{
	int		id;
	int		s;

	id = 0;
	s = 0;
//	id = ft_skip(ln, id);
	while (ln[id] == ' ' || ln[id] == '\t')
		id++;
	if (!head->is_name && !ft_strncmp((ln + id), N_CMD_STR, (LEN_N - 1)))
	{
		s = parse_line_header(ln, N_CMD_STR, (id + LEN_N), num_line);
		if (ft_strlen_char((ln + s), '"') > PROG_NAME_LENGTH)
			ft_error_length(0);
		ft_strncpy(head->prog_name, (ln + s), ft_strlen_char((ln + s), '"'));
		head->is_name = 1;
	}
	else if (!head->is_comment && !ft_strncmp((ln + id), C_CMD_STR, LEN_C - 1))
	{
		s = parse_line_header(ln, C_CMD_STR, (id + LEN_C), num_line);
		if (ft_strlen_char((ln + s), '"') > COMMENT_LENGTH)
			ft_error_length(1);
		ft_strncpy(head->comment, (ln + s), ft_strlen_char((ln + s), '"'));
		head->is_comment = 1;
	}
	else
		ft_error(LEX_ERR, NULL, num_line, id + 1);
	return (0);
}
