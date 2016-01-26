/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 19:21:17 by mgras             #+#    #+#             */
/*   Updated: 2015/11/29 20:47:16 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_char(const char *s, char c)
{
	if (*s && *s != c)
		return (ft_strlen_char(s + 1, c) + 1);
	return (0);
}

static int	ft_tablen_word(const char *s, char c)
{
	if (!*s)
		return (1);
	if (*s != c)
		return (ft_tablen_word(s + 1, c));
	while (*s && *s == c)
		s++;
	return (ft_tablen_word(s, c) + 1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		size;
	int		index;

	if (!s)
		return (NULL);
	size = ft_tablen_word(s, c) + 1;
	tab = (char**)malloc(sizeof(char*) * size);
	if (!tab)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			size = ft_strlen_char(s, c);
			tab[index++] = ft_strsub(s, 0, size);
			s += size;
		}
		else
			++s;
	}
	tab[index] = NULL;
	return (tab);
}
