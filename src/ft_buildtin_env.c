/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:38:29 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 19:47:35 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_one_envp(t_sto *cmd)
{
	int		i;
	int		equal;

	i = 0;
	equal = 0;
	if (cmd->value == NULL)
		return (0);
	while (cmd->value[i])
	{
		if (cmd->value[i] == '=')
		{
			equal = 1;
			if (i == 0 || i == (int)ft_strlen(cmd->value))
				return (0);
		}
		i++;
	}
	if (!equal)
		return (0);
	return (1);
}

t_sto	*ft_print_envp(t_sto *cmd, t_sto *envp)
{
	t_sto	*envp_swp;
	t_sto	*cmd_swp;

	envp_swp = envp;
	cmd_swp = cmd;
	while (cmd_swp)
	{
		if (!ft_check_one_envp(cmd_swp))
		{
			ft_buildtin_env_error_handling(001, cmd_swp, envp);
			ft_strdel(&(cmd_swp->value));
		}
		cmd_swp = cmd_swp->next;
	}
	if (cmd)
		ft_print_sto(cmd);
	ft_print_sto(envp_swp);
	return (cmd);
}

t_sto	*ft_skip_cmd_options(t_sto *cmd)
{
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	while (cmd_swp &&
		(cmd_swp->value[0] == '-' || ft_strcmp(cmd_swp->value, "env") == 0))
		cmd_swp = cmd_swp->next;
	return (cmd_swp);
}

int		ft_get_env_options(t_sto *cmd)
{
	t_sto	*cmd_swp;
	int		i;
	int		ret;

	cmd_swp = cmd;
	ret = 0;
	while (cmd_swp)
	{
		i = 1;
		if (cmd_swp->value[0] == '-')
			while (cmd_swp->value[i])
			{
				if (cmd_swp->value[i++] == 'i')
					ret = 1;
				else
					ft_buildtin_env_error_handling(004, cmd_swp, NULL);
			}
		cmd_swp = cmd_swp->next;
	}
	return (ret);
}

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
	envp_swp = ft_get_env_options(cmd) == 01 ? NULL : envp;
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
