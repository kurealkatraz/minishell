/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:13:59 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:31:38 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_sto	*evp;

	evp = NULL;
	(void)argv;
	(void)argc;
	evp = ft_import_native_envp(NULL, envp);
	evp = ft_shell_lvls_import(evp);
	evp = ft_free_sto_chain(evp);
	return (0);
}
