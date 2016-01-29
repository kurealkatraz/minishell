/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:32:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/29 01:02:34 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_sto_to_tab(t_sto *sto)
{
	char	**tab;
	t_sto	*swp;
	int		i;

	swp = sto;
	i = 0;
	while (swp)
	{
		i++;
		swp = swp->next;
	}
	tab = (char**)malloc(sizeof(char*) * i);
	i = 0;
	swp = sto;
	while (swp)
	{
		tab[i++] = ft_strdup(swp->value);
		swp = swp->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_free_char_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

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

int		ft_is_complex_subcmd(t_sto *subcmd)
{
	t_sto	*s;

	s = subcmd;
	while (s)
	{
		if (ft_is_special_separator(s->value) || ft_strcmp(s->value, "|") == 0)
			return (1);
		s = s->next;
	}
	return (0);
}
