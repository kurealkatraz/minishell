/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:55:33 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 01:09:42 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt_name(t_sto *envp)
{
	t_sto	*name;

	ft_putstr(C_GREEN);
	name = ft_sto_find_name(envp, "USER");
	if (name != NULL)
		ft_putstr(name->value);
	else
		ft_putstr("Anon");
	ft_putstr(C_NONE);
}

void	ft_prompt_tree(void)
{
	char	*name;

	ft_putstr(C_BLUE);
	name = NULL;
	name = getcwd(name, 0);
	if (name != NULL)
		ft_putstr(name);
	else
		ft_putstr("You are 2 deep 4 me");
	free(name);
	ft_putstr(C_NONE);
}

void	ft_prompt_imput_field(t_sto *envp)
{
	t_sto	*swp;

	swp = envp;
	ft_prompt_name(swp);
	ft_putchar(' ');
	ft_prompt_tree();
	ft_putchar(' ');
}
