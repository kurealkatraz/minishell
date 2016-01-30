/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_native_cmd_call.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 23:59:19 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 17:31:57 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_native_cmd_call(t_sto *cmd, t_sto *envp)
{
	int		operation_index;
	t_sto	*envp_swp;
	t_sto	*cmd_swp;

	cmd_swp = cmd;
	envp_swp = envp;
	operation_index = ft_get_operation_index(cmd_swp);
	if (operation_index == 0)
		ft_exec_subcmd(cmd_swp->value, cmd_swp, envp_swp, envp_swp);
	else
		ft_putendl("soon");
	return (cmd);
}
