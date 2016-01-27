/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:23:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/27 21:56:41 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_c_len(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			while (line[i] && (line[i] == ' ' || line[i] == '\t'))
				i++;
		else
			i++;
		if (line[i])
			len++;
	}
	return (len);
}

char	*ft_strclcpy(char *dst, char *src)
{
	int		ss;
	int		ts;

	ss = 0;
	ts = 0;
	while (src[ts])
	{
		if (src[ts] == ' ' || src[ts] == '\t')
		{
			dst[ss++] = ' ';
			while (src[ts] && (src[ts] == ' ' || src[ts] == '\t'))
				ts++;
		}
		else
			dst[ss++] = src[ts++];
	}
	dst[ss] = '\0';
	return (dst);
}

char	*ft_clean_line(char *line)
{
	char	*line_tmp;
	char	*n;

	n = (char*)malloc(sizeof(char) * ft_get_c_len(line_tmp = ft_strtrim(line)));
	n = ft_strclcpy(n, line_tmp);
	ft_strdel(&line_tmp);
	return (n);
}
