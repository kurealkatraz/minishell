/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 19:34:49 by mgras             #+#    #+#             */
/*   Updated: 2015/03/22 15:25:19 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		cur;

	cur = 0;
	while (src[cur] != '\0' && cur < n)
	{
		dst[cur] = src[cur];
		cur++;
	}
	while (cur < n)
	{
		dst[cur] = '\0';
		cur++;
	}
	return (dst);
}
