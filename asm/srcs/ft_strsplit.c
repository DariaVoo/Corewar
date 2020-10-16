/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:47:20 by rretta            #+#    #+#             */
/*   Updated: 2019/09/18 17:30:09 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_word_count(char const *s, char c)
{
	size_t	q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}

static size_t	ft_sym_count(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void		*ft_free(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
	{
		ft_memdel((void *)tmp[i]);
		i++;
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	size_t	i;
	size_t	q;

	if (!s)
		return (NULL);
	if (!c)
		c = '\0';
	i = 0;
	q = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (NULL == tmp)
		return (NULL);
	while (s[i] != '\0' && q != ft_word_count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!(tmp[q] = ft_strsub(s, i, ft_sym_count(s, c, i))))
			return (ft_free(tmp));
		while (s[i] != c && s[i] != '\0')
			i++;
		q++;
	}
	tmp[q] = NULL;
	return (tmp);
}
