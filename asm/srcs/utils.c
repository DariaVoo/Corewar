/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:48:06 by rretta            #+#    #+#             */
/*   Updated: 2020/11/14 22:30:38 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			skip_spaces(char *split, int *i)
{
	while (split[*i] && (split[*i] == ' ' || split[*i] == '\t'))
	{
		(*i)++;
	}
}

int				ft_is_number(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (i == 0 && (name[i] == '+' || name[i] == '-'))
		{
			i++;
			continue;
		}
		if (name[i] < '0' || name[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int				massiv_len(char **args)
{
	int i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

static char		*ft_custom_strjoin(char *s1, char *s2)
{
	char	*ans;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ans = ft_strnew(len);
	if (!ans)
		return (NULL);
	ans = ft_strcat(ans, s1);
	ans = ft_strcat(ans, s2);
	ans[len] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ans);
}

int				get_number_of_lines(t_data *data)
{
	char	*string;
	int		num;
	char	*label;
	int		sym;

	num = 0;
	label = ft_strdup(" ");
	while (get_next_line(data->read_fd, &string))
	{
		sym = 0;
		if (ft_strchr(string, LABEL_CHAR))
		{
			if (ft_parse_label(string, &sym) != NULL)
			{
				sym = 0;
				label = ft_custom_strjoin(label, ft_parse_label(string, &sym));
			}
		}
		num++;
		ft_strdel(&string);
	}
	data->all_labels = ft_strdup(label);
	ft_strdel(&string);
	ft_strdel(&label);
	return (num);
}
