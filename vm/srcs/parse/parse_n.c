/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:44:06 by cnails            #+#    #+#             */
/*   Updated: 2020/09/22 11:44:02 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
*/

int		ft_strlen(char *str) {
	int i = 0;

	while (str[i]) {
		i++;
	}
	return (i);
}

/*
*/

// struct	s_parse_n
// {
// 	size_t
// }		t_parse_n;

int		is_valid_int(int nbr, char *str)
{
	char *tmp;

	tmp = itoa(nbr);
	if (strcmp(tmp, str))
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int		ret_len(int ac, char **av)
{
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		if (!(av[i][0] == '-'))
			len++;
	}
	return (len);
}

char	**parse_n(int ac, char **av)
{
	char	**res;
	int		len;
	int		nbr;
	int		tmp;
	int		i;

	tmp = 0;
	i = 1;
	len = ret_len(ac, av);
	if (!(res = (char **)malloc(sizeof(char **) * len)))
		return (NULL);
	while (i < ac)
	{
		if (!strcmp(av[i], "-n"))
		{
			if (av[i + 1] && is_valid_int(atoi(av[i + 1]), av[i + 1]))
			{
				nbr = atoi(av[i + 1]);
				if (nbr <= len && !res[nbr] && av[i + 2])
					res[nbr] = strdup(av[i + 2]);
				i += 2;
			}
		}
		else
		{
			tmp = 0;
			while (tmp < len)
			{
				if (!res[tmp])
				{
					res[tmp] = av[i + 1];
					i++;
					break;
				}
				tmp++;
			}
		}
		i++;
	}
}
