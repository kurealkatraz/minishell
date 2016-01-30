/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_env_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:50:31 by mgras             #+#    #+#             */
/*   Updated: 2016/01/30 19:55:20 by mgras            ###   ########.fr       */
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

int		ft_get_env_options(t_sto *cmd, t_sto *lim)
{
	t_sto	*cmd_swp;
	int		i;
	int		ret;

	cmd_swp = cmd;
	ret = 0;
	while (cmd_swp && cmd_swp != lim)
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
