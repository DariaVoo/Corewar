/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:55:21 by pkingsbl          #+#    #+#             */
/*   Updated: 2019/09/20 20:05:25 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../libft/includes/libftprintf.h"

int		ft_words(char const *s, char c, char ch)
{
	int i;
	int z;

	i = 0;
	z = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c || s[i] == ch)
			i++;
		if (s[i] != '\0')
		{
			z++;
			i++;
		}
		while (s[i] != c && s[i] != ch && s[i] != '\0')
			i++;
	}
	return (z);
}

static int		ft_lenword(char const *s, unsigned int start, char c, char ch)
{
	int i;

	i = 0;
	while ((s[start] == c || s[start] == ch) && s[start] != '\0')
		start++;
	if (s[start] != '\0' && s[start] != c && s[start] != ch)
	{
		while (s[start] != c && s[start] != ch && s[start] != '\0')
		{
			i++;
			start++;
		}
	}
	return (i);
}

static int		where_is_pointer(char const *s, unsigned int start, char c, char ch)
{
	while ((s[start] == c || s[start] == ch) && s[start] != '\0')
		start++;
	if (s[start] != c && s[start] != ch && s[start] != '\0')
	{
		while (s[start] != c && s[start] != ch && s[start] != '\0')
			start++;
	}
	return (start);
}

static void		*ft_free(char **dest)
{
	int		i;

	i = 0;
	while (dest[i])
	{
		ft_memdel((void *)dest[i]);
		i++;
	}
	return (NULL);
}

char			**ft_strmultsplit(char const *s, char c, char ch)
{
	int		z;
	int		word_size;
	int		point;
	int		count_pointers;
	char	**arr;

	if (!s)
		return (NULL);
	z = 0;
	point = 0;
	count_pointers = ft_words(s, c, ch);
	if (!(arr = (char**)malloc(sizeof(char *) * (count_pointers + 1))))
		return (NULL);

	while (z < count_pointers)
	{
		word_size = ft_lenword(s, point, c, ch);
		point = where_is_pointer(s, point, c, ch);
		if (!(arr[z] = ft_strsub(s, point - word_size, word_size)))
			return (ft_free(arr));
		z++;
	}
	arr[z] = NULL;
	return (arr);
}
