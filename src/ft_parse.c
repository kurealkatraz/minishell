/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:01:10 by nowife            #+#    #+#             */
/*   Updated: 2016/01/28 13:07:56 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_get_next_cmd(t_sto *input, t_sto *cmd)
{
	if (ft_strcmp(input->value, ";") == 0)
		input = input->next;
	while (input && ft_strcmp(input->value, ";") != 0)
	{
		cmd = ft_new_sto(cmd, NULL, input->value);
		input = input->next;
	}
	return (ft_rev_sto(cmd));
}

t_sto	*ft_parse_core(t_sto *input, t_sto *envp)
{
	t_sto	*cmd;
	t_sto	*input_swp;

	(void)envp;
	input_swp = input;
	while ((cmd = ft_get_next_cmd(input_swp, NULL)))
	{
		ft_print_sto(cmd);
		cmd = ft_free_sto_chain(cmd);
	}
	return (input);
}
