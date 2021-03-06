/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:14:23 by mgras             #+#    #+#             */
/*   Updated: 2016/01/31 15:17:21 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_buildtin_cd_error_handling(int err_nb, t_sto *envp)
{
	ft_putstr(C_BOLD);
	ft_putstr(C_RED);
	ft_putstr("ERROR ");
	ft_putstr("in the buildtin cd process ");
	ft_putstr(C_NONE);
	ft_putstr(C_CYAN);
	if (err_nb == 001)
		ft_putendl("The number of arguments are invalid");
	else if (err_nb == 002)
		ft_putendl("The argument is either not here or has been denied access");
	else if (err_nb == 003)
		ft_putendl("There is no more OLDPWD in the env, or it's invalid");
	else if (err_nb == 004)
		ft_putendl("There is no more HOME in the env, or it's invalid");
	ft_putstr(C_NONE);
	return (envp);
}

t_sto	*ft_buildtin_env_error_handling(int err_nb, t_sto *cmd, t_sto *envp)
{
	ft_putstr(C_BOLD);
	ft_putstr(C_RED);
	ft_putstr("ERROR ");
	ft_putstr("in the buildtin env process ");
	ft_putstr(C_NONE);
	ft_putstr(C_CYAN);
	if (err_nb == 001)
	{
		ft_putstr("envp added argument ");
		ft_putstr(cmd->value);
		ft_putendl(" is not valid it will be skipped");
	}
	else if (err_nb == 002)
		ft_putendl("Can't find the PATH variable");
	else if (err_nb == 003)
		ft_putendl("There is no Env");
	else if (err_nb == 004)
	{
		ft_putstr("The follow line ");
		ft_putstr(cmd->value);
		ft_putendl(" contains unvalid options that will be ignored");
	}
	ft_putstr(C_NONE);
	return (envp);
}

t_sto	*ft_buildtin_unsetenv_error_handling(int err_nb, t_sto *c, t_sto *envp)
{
	ft_putstr(C_BOLD);
	ft_putstr(C_RED);
	ft_putstr("ERROR ");
	ft_putstr("in the buildtin unsetenv process ");
	ft_putstr(C_NONE);
	ft_putstr(C_CYAN);
	if (err_nb == 001)
		ft_putendl("There is no more env variable to unset ");
	else if (err_nb == 002)
	{
		ft_putstr("Can't find the asked variable : ");
		ft_putendl(c->value);
	}
	ft_putstr(C_NONE);
	return (envp);
}

t_sto	*ft_exec_error_handling(int err_nb, t_sto *cmd, t_sto *evp)
{
	ft_putstr(C_BOLD);
	ft_putstr(C_RED);
	ft_putstr("ERROR ");
	ft_putstr("in the native execution process ");
	ft_putstr(C_NONE);
	ft_putstr(C_CYAN);
	if (err_nb == 001)
	{
		ft_putstr("The command ");
		ft_putstr(C_MAGENTA);
		ft_putstr(cmd->value);
		ft_putstr(C_CYAN);
		ft_putendl(" is unknowed");
	}
	else if (err_nb == 002)
		ft_putendl("Can't find the PATH variable");
	else if (err_nb == 003)
		ft_putendl("There is no Env");
	else if (err_nb == 004)
		ft_putendl("You do not have the rights to execute this binary, sorry");
	ft_putstr(C_NONE);
	return (evp);
}
