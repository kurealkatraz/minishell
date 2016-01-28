/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:01:10 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 15:17:39 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_sto	*ft_parse_cmd_category(t_sto *cmd, t_sto *envp)
{
	if (ft_strcmp(cmd->value, "env") == 0)
		;//ft_buildtin_env(cmd, envp);
	else if (ft_strcmp(cmd->value, "cd") == 0)
		;//ft_buildtin_cd(cmd, envp);
	else if (ft_strcmp(cmd->value, "unsetenv") == 0)
		;//ft_buildtin_unsetenv(cmd, envp);
	else if (ft_strcmp(cmd->value, "setenv") == 0)
		;//ft_buildtin_setenv(cmd, envp);
	else
		ft_regular_cmd_call(cmd, envp);
	return (envp);
}

t_sto	*ft_parse_core(t_sto *input, t_sto *envp)
{
	t_sto	*cmd;
	t_sto	*input_swp;

	input_swp = input;
	while ((cmd = ft_get_next_cmd(input_swp, NULL)))
	{
		ft_parse_cmd_category(cmd, envp);
		cmd = ft_free_sto_chain(cmd);
		if (ft_strcmp(input_swp->value, ";") == 0)
			input_swp = input_swp->next;
		while (input_swp && ft_strcmp(input_swp->value, ";") != 0)
			input_swp = input_swp->next;
	}
	return (input);
}
