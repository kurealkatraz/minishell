/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:26:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/29 18:19:47 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_parse_cmd_category(t_sto *cmd, t_sto *envp)
{
	if (ft_strcmp(cmd->value, "env") == 0)
		ft_buildtin_env(cmd, envp);
	else if (ft_strcmp(cmd->value, "cd") == 0)
		;//ft_buildtin_cd(cmd, envp);
	else if (ft_strcmp(cmd->value, "unsetenv") == 0)
		envp = ft_buildtin_unsetenv(cmd->next, envp);
	else if (ft_strcmp(cmd->value, "setenv") == 0)
		envp = ft_buildtin_setenv(cmd->next, envp);
	else
		ft_native_cmd_call(cmd, envp);
	return (envp);
}

t_sto	*ft_get_next_sub_cmd(t_sto *input, t_sto *cmd)
{
	t_sto	*swp;
	int		spe;

	swp = input;
	spe = 0;
	if (!swp)
		return (NULL);
	if (ft_strcmp(swp->value, ";") == 0)
		swp = swp->next;
	while (swp && ft_strcmp(swp->value, ";") != 0 && spe < 2)
	{
		if (ft_is_special_separator(swp->value))
			spe++;
		cmd = ft_new_sto(cmd, NULL, swp->value);
		swp = swp->next;
	}
	return (ft_rev_sto(cmd));
}

t_sto	*ft_cmd_call(t_sto *cmd, t_sto *envp)
{
	t_sto	*sub_cmd;
	t_sto	*tmp_cmd;

	tmp_cmd = cmd;
	sub_cmd = NULL;
	while ((sub_cmd = ft_get_next_sub_cmd(tmp_cmd, sub_cmd)))
	{
		envp = ft_parse_cmd_category(sub_cmd, envp);
		sub_cmd = ft_free_sto_chain(sub_cmd);
		if (ft_strcmp(tmp_cmd->value, ";") == 0)
			tmp_cmd = tmp_cmd->next;
		while (tmp_cmd && ft_strcmp(tmp_cmd->value, ";") != 0)
			tmp_cmd = tmp_cmd->next;
	}
	return (envp);
}
