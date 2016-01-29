/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:52:05 by nowife            #+#    #+#             */
/*   Updated: 2016/01/29 19:27:51 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_buildtin_cd_chdir(t_sto *envp, char *path)
{
	t_sto	*pwd;
	t_sto	*old_pwd;
	char	*cwd;

	cwd = NULL;
	pwd = ft_sto_find_name(envp, "PWD");
	old_pwd = ft_sto_find_name(envp, "OLDPWD");
	cwd = getcwd(cwd, 0);
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", path);
	else
	{
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(path);
	}
	if (!old_pwd)
		envp = ft_new_sto(envp, "OLDPWD", cwd);
	else
	{
		ft_strdel(&(old_pwd->value));
		pwd->value = ft_strdup(cwd);
	}
	chdir(path);
	return (envp);
}

t_sto	*ft_buildtin_cd_return_old(t_sto *envp)
{
	t_sto	*pwd;
	t_sto	*old_pwd;
	char	*cwd;

	cwd = NULL;
	pwd = ft_sto_find_name(envp, "PWD");
	old_pwd = ft_sto_find_name(envp, "OLDPWD");
	cwd = getcwd(cwd, 0);
	if (!old_pwd)
		return (ft_buildtin_cd_error_handling(003, envp));
	if (access(old_pwd->value, F_OK) == -1)
		return (ft_buildtin_cd_error_handling(002, envp));
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", old_pwd->value);
	else
	{
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(old_pwd->value);
	}
	ft_strdel(&(old_pwd->value));
	old_pwd->value = ft_strdup(cwd);
	chdir(pwd->value);
	return (envp);
}

t_sto	*ft_buildtin_cd_return_home(t_sto *envp)
{
	t_sto	*pwd;
	t_sto	*old_pwd;
	t_sto	*home;
	char	*cwd;

	home = ft_sto_find_name(envp, "HOME");
	old_pwd = ft_sto_find_name(envp, "OLDPWD");
	pwd = ft_sto_find_name(envp, "PWD");
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (!home)
		return (ft_buildtin_cd_error_handling(004, envp));
	if (access(home->value, F_OK) == -1)
		return (ft_buildtin_cd_error_handling(002, envp));
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", home->value);
	else
	{
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(home->value);
	}
	if (!old_pwd)
		envp = ft_new_sto(envp, "OLDPWD", cwd);
	else
	{
		ft_strdel(&(old_pwd->value));
		old_pwd->value = ft_strdup(cwd);
	}
	return (envp);
}

t_sto	*ft_buildtin_cd_error_handling(int err_nb, t_sto *envp)
{
	ft_putstr(C_BOLD);
	ft_putstr(C_RED);
	ft_putstr("ERROR ");
	ft_putstr("in buildtin cd ");
	ft_putstr(C_CYAN);
	if (err_nb == 001)
		ft_putendl("The number of arguments are invalid");
	else if (err_nb == 002)
		ft_putendl("The argument is either not here or has been denied access");
	else if (err_nb == 003)
		ft_putendl("There is no more OLDPWD in the env");
	ft_putstr(C_NONE);
	return (envp);
}

t_sto	*ft_buildtin_cd(t_sto *cmd, t_sto *envp)
{
	t_sto	*cmd_swp;

	cmd_swp = cmd->next;
	if (ft_get_sto_len(cmd_swp) > 1)
	{
		ft_buildtin_cd_error_handling(001, envp);
		return (envp);
	}
	else if (cmd_swp && access(cmd_swp->value, F_OK) == -1)
	{
		ft_buildtin_cd_error_handling(002, envp);
		return (envp);
	}
	if (cmd_swp == NULL)
		envp = ft_buildtin_cd_return_home(envp);
	else if (ft_strcmp(cmd_swp->value, "-") == 0)
		envp = ft_buildtin_cd_return_old(envp);
	else
		envp = ft_buildtin_cd_chdir(envp, cmd_swp->value);
	return (envp);
}
