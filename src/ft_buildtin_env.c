/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:38:29 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 23:45:49 by nowife           ###   ########.fr       */
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
			ft_strdel(&(cmd_swp->value));
		cmd_swp = cmd_swp->next;
	}
	if (cmd)
		ft_print_sto(cmd->next);
	ft_print_sto(envp_swp);
	return (cmd);
}

t_sto	*ft_buildtin_env(t_sto *cmd, t_sto *envp)
{
	int		operation_index;
	t_sto	*envp_swp;
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	envp_swp = NULL;
	operation_index = ft_get_operation_index(cmd_swp);
	if (cmd_swp->next == NULL)
		return (ft_print_envp(NULL, envp));
	envp_swp = ft_strcmp(cmd_swp->next->value, "-i") ? envp : NULL;
	if (operation_index == 0)
		ft_print_envp(cmd_swp, envp_swp);
	else
		ft_putendl("Comming soon");
	return (envp);
}
