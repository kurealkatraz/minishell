/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_unsetenv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 01:35:05 by nowife            #+#    #+#             */
/*   Updated: 2016/01/31 14:40:52 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_buildtin_unsetenv(t_sto *cmd, t_sto *envp)
{
	t_sto	*envp_swp;
	t_sto	*cmd_swp;
	t_sto	*del_swp;

	envp_swp = envp;
	cmd_swp = cmd;
	del_swp = NULL;
	if (!envp)
		return (ft_buildtin_unsetenv_error_handling(001, NULL, envp));
	while (cmd_swp)
	{
		del_swp = ft_sto_find_name(envp_swp, cmd_swp->value);
		if (!del_swp)
			ft_buildtin_unsetenv_error_handling(002, cmd, envp);
		if (del_swp && del_swp->prev == NULL)
			envp = del_swp->next;
		ft_del_one_sto(del_swp);
		cmd_swp = cmd_swp->next;
	}
	return (envp);
}
