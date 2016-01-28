/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:32:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 14:47:02 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_special_character(char c)
{
	if (c == ';' || c == '>' || c == '<' || c == '|')
		return (1);
	else
		return (0);
}

int		ft_is_special_separator(char *s)
{
	if (ft_is_special_character(s[0]) && s[1] == '\0')
		return (1);
	else if (s[0] == '>' || s[0] == '<')
		if (ft_is_special_character(s[0]) && s[1] == s[0] && s[2] == '\0')
			return (1);
	return (0);
}