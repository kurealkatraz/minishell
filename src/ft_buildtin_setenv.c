/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_setenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:38:57 by nowife            #+#    #+#             */
/*   Updated: 2016/01/29 12:49:04 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_buildtin_setenv(t_sto *cmd, t_sto *envp)
{
	t_sto	*cmd_swp;
	char	*name_tmp;
	char	*value_tmp;

	cmd_swp = cmd;
	while (cmd_swp)
	{
		if (!ft_check_one_envp(cmd_swp))
			ft_strdel(&(cmd_swp->value));
		cmd_swp = cmd_swp->next;
	}
	cmd_swp = cmd;
	while (cmd_swp)
	{
		if (cmd_swp->value)
		{
			name_tmp = ft_env_name(cmd_swp->value);
			value_tmp = ft_env_value(cmd_swp->value);
			envp = ft_new_sto(envp, name_tmp, value_tmp);
			ft_strdel(&name_tmp);
			ft_strdel(&value_tmp);
		}
		cmd_swp = cmd_swp->next;
	}
	return (envp);
}
