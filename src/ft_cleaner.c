/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:23:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 01:13:27 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_clen(char *src)
{
	int		len;
	int		add;

	len = 0;
	add = 0;
	while (src[len])
	{
		if (src[len] == ';')
			add += 2;
		len++;
	}
	len += add;
	return (len + 2);
}

char	*ft_clean_blank(char *line, char *n, int *po2, int *po1)
{
	n[*po1] = ' ';
	while (line[*po2] && (line[*po2] == ' ' || line[*po2] == '\t'))
		*po2 = *po2 + 1;
	*po1 = *po1 + 1;
	return (line);
}

char	*ft_skip_brakets(char *line, char *n, int *po2, int *po1)
{
	char	b;

	b = line[*po2];
	while (line[*po2])
	{
		n[*po1] = line[*po2];
		*po1 = *po1 + 1;
		*po2 = *po2 + 1;
		if (line[*po2] == b)
			break ;
	}
	if (line[*po2])
	{
		n[*po1] = line[*po2];
		*po1 = *po1 + 1;
		*po2 = *po2 + 1;
	}
	return (line);
}

char	*ft_wrap_semicolon(char *line, char *n, int *po2, int *po1)
{
	if (line[*po2 - 1] != ' ')
	{
		n[*po1] = ' ';
		*po1 = *po1 + 1;
	}
	n[*po1] = line[*po2];
	*po1 = *po1 + 1;
	*po2 = *po2 + 1;
	if (line[*po2] != ' ')
	{
		n[*po1 + 1] = ' ';
		*po1 = *po1 + 2;
	}
	return (line);
}

char	*ft_clean_line(char *line)
{
	int		po1;
	int		po2;
	char	*n;

	po1 = 0;
	po2 = 0;
	n = (char*)malloc(sizeof(char) * (ft_get_clen(line)));
	ft_bzero(n, ft_strlen(line) + 1);
	while (line[po2])
	{
		if (line[po2] == ' ' || line[po2] == '\t')
			ft_clean_blank(line, n, &po2, &po1);
		else if (line[po2] == '\'' || line[po2] == '\"')
			ft_skip_brakets(line, n, &po2, &po1);
		else if (line[po2] == ';')
			ft_wrap_semicolon(line, n, &po2, &po1);
		else
			n[po1++] = line[po2++];
	}
	n[po1] = '\0';
	return (n);
}
