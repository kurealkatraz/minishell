/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 00:33:42 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 01:08:50 by nowife           ###   ########.fr       */
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
	pos++;
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
