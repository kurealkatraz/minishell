/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:26:48 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 15:34:01 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

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

t_sto	*ft_regular_cmd_call(t_sto *cmd, t_sto *envp)
{
	t_sto	*sub_cmd;
	t_sto	*tmp_cmd;

	tmp_cmd = cmd;
	sub_cmd = NULL;
	while ((sub_cmd = ft_get_next_sub_cmd(tmp_cmd, sub_cmd)))
	{
		sub_cmd = ft_free_sto_chain(sub_cmd);
		if (ft_strcmp(tmp_cmd->value, ";") == 0)
			tmp_cmd = tmp_cmd->next;
		while (tmp_cmd && ft_strcmp(tmp_cmd->value, ";") != 0)
			tmp_cmd = tmp_cmd->next;
	}
	return (envp);
}
