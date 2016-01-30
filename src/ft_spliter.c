/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 00:33:42 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 17:12:23 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_tab_size(char *line)
{
	int		ss;
	int		size;

	ss = 0;
	size = 0;
	while (line[ss])
	{
		if (line[ss] == ' ')
			size++;
		ss++;
	}
	size++;
	return (size);
}

int		ft_get_next_mark(char *line, int pos)
{
	char	bracket;

	pos++;
	pos = pos == 1 && (line[pos] == '\'' || line[pos] == '\"') ? 0 : pos;
	if (line[pos] == '\'' || line[pos] == '\"')
	{
		bracket = line[pos++];
		while (line[pos] != bracket)
			pos++;
		return (pos + 1);
	}
	while (line[pos] && line[pos] != ' ')
		pos++;
	return (pos);
}

char	**ft_splitline(char *line)
{
	int		i;
	int		po1;
	int		po2;
	int		len;
	char	**ret;

	ret = (char**)malloc(sizeof(char*) * (ft_get_tab_size(line) + 1));
	po2 = 0;
	po1 = 0;
	i = 0;
	len = ft_strlen(line);
	while (po2 < len)
	{
		po2 = ft_get_next_mark(line, po2);
		ret[i++] = ft_strsub(line, po1, po2 - po1);
		po1 = po2 + 1;
	}
	ret[i] = NULL;
	return (ret);
}
