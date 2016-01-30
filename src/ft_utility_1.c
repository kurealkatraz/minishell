/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:36:30 by mgras             #+#    #+#             */
/*   Updated: 2016/01/30 16:37:31 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_char_tab(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		ft_putendl(argv[i++]);
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
