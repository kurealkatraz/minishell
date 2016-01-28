/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:01:10 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 01:29:13 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_get_next_cmd(t_sto *input, t_sto *cmd)
{
	t_sto	*swp;

	swp = input;
	while (swp && ft_strcmp(swp->value, ";") != 0)
	{
		cmd = ft_new_sto(cmd, NULL, swp->value);
		swp = swp->next;
	}
	return (cmd);
}

t_sto	*ft_parse_core(t_sto *input, t_sto *envp)
{
	t_sto	*cmd;

	(void)envp;
	while ((cmd = ft_get_next_cmd(input, NULL)))
	{
		cmd = ft_free_sto_chain(cmd);
	}
	return (input);
}
