/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 15:21:07 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:30:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new = ft_strncpy(new, s1, size);
	new[size] = '\0';
	return (new);
}
