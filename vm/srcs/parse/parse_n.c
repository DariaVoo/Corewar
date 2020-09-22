/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:44:06 by cnails            #+#    #+#             */
/*   Updated: 2020/09/22 19:20:20 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse_n.h"
/*
*/

static int		ft_numlen(long long nb)
{
	if (nb < 0)
		return (1 + ft_numlen(nb * -1));
	if (nb >= 10)
		return (1 + ft_numlen(nb / 10));
	else
		return (1);
}

char			*ft_itoa(long long n)
{
	char	*str;
	int		i;

	i = ft_numlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (ft_numlen(n) + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}


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

	tmp = ft_itoa(nbr);
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
		if (av[i][0] == '-')
			i++;
		else
			len++;
		i++;
	}
	return (len);
}

int		is_not_dupl(t_arg *arg, t_arg *end, int nbr)
{
	t_arg *head;

	head = arg;
	while (head != end)
	{
		if (head->index == nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

char	**parse_n(int ac, char **av)
{
	t_arg	*arg;
	t_arg	*head;
	char	**res;
	int		len;
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	len = ret_len(ac, av);
	printf("len = %d\n", len);
	arg = (t_arg *)malloc(sizeof(t_arg));
	head = arg;
	// if (!(res = (char **)malloc(sizeof(char **) * (len + 1))))
		// return (NULL);
	// while (i <= len) {
		// res[i] = NULL;
		// i++;
	// }
	i = 1;
	while (i < ac)
	{
		if (!strcmp(av[i], "-n"))
		{
			if (av[i + 1] && is_valid_int(atoi(av[i + 1]), av[i + 1]))
			{
				arg->index = atoi(av[i + 1]);
				printf("nbr = %d\n", is_not_dupl(head, arg, arg->index));
				if (arg->index < len && av[i + 2] && is_not_dupl(head, arg, arg->index))
					arg->name = strdup(av[i + 2]);
				else {
					printf("Error 1\n");
					exit(1);
				}
				i += 2;
			}
			else {
				printf("Error 2\n");
				exit(1);
			}
		}
		else
		{
			arg->index = -1;
			arg->name = strdup(av[i]);
		}
		if (i < ac)
		{
			arg->next = (t_arg *)malloc(sizeof(t_arg));
			arg = arg->next;
			arg->next = NULL;
		}
		i++;
	}
	while (head->next)
	{
		printf("ind = %d\nname = %s\n", head->index, head->name);
		head = head->next;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	char **str;
	int i = 0;

	str = parse_n(ac, av);
	// while (str[i]) {
	// 	printf("%s\n", str[i]);
	// 	free(str[i]);
	// 	i++;
	// }
	return (0);
}


