/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_env_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:38:29 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 19:55:42 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_has_cmd(t_sto *cmd, t_sto *envp)
{
	t_sto	*cmd_swp;
	t_sto	*envp_swp;
	char	*tmp;

	cmd_swp = cmd;
	tmp = NULL;
	envp_swp = envp;
	while (cmd_swp)
	{
		if (ft_strcmp(cmd_swp->value, "env") == 0)
			;
		else if (cmd_swp->value[0] == '-')
			;
		else if ((tmp = ft_get_exec_path(cmd_swp->value, envp_swp)))
		{
			ft_strdel(&tmp);
			return (cmd_swp);
		}
		cmd_swp = cmd_swp->next;
	}
	return (NULL);
}

t_sto	*ft_env_select_proc(t_sto *cmd, t_sto *envp, char *path)
{
	int		operation_index;
	t_sto	*envp_swp;
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	operation_index = ft_get_operation_index(cmd);
	envp_swp = ft_get_env_options(cmd,
				ft_has_cmd(cmd->next, envp)) == 01 ? NULL : envp;
	if (operation_index == 0 && !ft_has_cmd(cmd->next, envp))
	{
		ft_print_envp(ft_skip_cmd_options(cmd), envp_swp);
		return (envp);
	}
	path = ft_strdup(ft_has_cmd(cmd->next, envp)->value);
	if (operation_index == 0 && path)
	{
		cmd_swp = ft_has_cmd(cmd->next, envp);
		envp_swp = ft_sto_join(envp, cmd, cmd_swp);
		ft_exec_subcmd(path, cmd_swp, envp, envp_swp);
		ft_free_sto_chain(envp_swp);
		return (envp);
	}
	ft_strdel(&path);
	return (envp);
}

t_sto	*ft_buildtin_env(t_sto *cmd, t_sto *envp)
{
	t_sto	*envp_swp;
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	envp_swp = NULL;
	if (!envp)
		return (NULL);
	if (cmd_swp->next == NULL)
		return (ft_print_envp(NULL, envp));
	envp = ft_env_select_proc(cmd, envp, NULL);
	return (envp);
}
