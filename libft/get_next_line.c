/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 10:28:14 by mgras             #+#    #+#             */
/*   Updated: 2015/11/29 22:48:46 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rl(int const fd, char *buff, char *sav[fd])
{
	char	*swp;
	char	*c;
	int		i;

	i = 0;
	while (!(c = ft_strchr(sav[fd], '\n'))
			&& (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		swp = sav[fd];
		sav[fd] = ft_strjoin(swp, buff);
		ft_strdel(&swp);
	}
	ft_strdel(&buff);
	if (i == -1)
		return (-1);
	if (i == 0 && !c)
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		*sav[256];
	char			*buff;
	char			*swp;
	int				read;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL)
		return (-1);
	if (sav[fd] == NULL)
		sav[fd] = ft_strnew(1);
	read = ft_rl(fd, buff, &*sav);
	if (read == -1)
		return (-1);
	if (read == 0)
	{
		*line = sav[fd];
		sav[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(sav[fd], 0, (ft_strchr(sav[fd], '\n')) - sav[fd]);
	swp = sav[fd];
	sav[fd] = ft_strdup(ft_strchr(sav[fd], '\n') + 1);
	ft_strdel(&swp);
	return (1);
}
