/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:01:10 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 16:53:08 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_operation_index(t_sto *cmd)
{
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	while (cmd_swp)
	{
		if (ft_strcmp(cmd_swp->value, ">") == 0)
			return (100);
		else if (ft_strcmp(cmd_swp->value, "<") == 0)
			return (101);
		else if (ft_strcmp(cmd_swp->value, ">>") == 0)
			return (102);
		else if (ft_strcmp(cmd_swp->value, "<<") == 0)
			return (103);
		else if (ft_strcmp(cmd_swp->value, "|") == 0)
			return (200);
		cmd_swp = cmd_swp->next;
	}
	return (0);
}

t_sto	*ft_get_next_cmd(t_sto *input, t_sto *cmd)
{
	t_sto	*swp;

	swp = input;
	if (!swp)
		return (NULL);
	if (ft_strcmp(swp->value, ";") == 0)
		swp = swp->next;
	while (swp && ft_strcmp(swp->value, ";") != 0)
	{
		cmd = ft_new_sto(cmd, NULL, swp->value);
		swp = swp->next;
	}
	return (ft_rev_sto(cmd));
}

t_sto	*ft_parse_core(t_sto *input, t_sto *envp)
{
	t_sto	*cmd;
	t_sto	*input_swp;

	input_swp = input;
	while ((cmd = ft_get_next_cmd(input_swp, NULL)))
	{
		ft_cmd_call(cmd, envp);
		cmd = ft_free_sto_chain(cmd);
		if (ft_strcmp(input_swp->value, ";") == 0)
			input_swp = input_swp->next;
		while (input_swp && ft_strcmp(input_swp->value, ";") != 0)
			input_swp = input_swp->next;
	}
	return (input);
}
