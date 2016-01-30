/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:52:05 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 17:14:49 by mgras            ###   ########.fr       */
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
	if (!old_pwd)
		envp = ft_new_sto(envp, "OLDPWD", cwd);
	else
		envp = ft_change_sto(envp, old_pwd, "OLDPWD", cwd);
	chdir(path);
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", cwd);
	else
		envp = ft_change_sto(envp, pwd, "PWD", cwd);
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
		return (ft_buildtin_cd_error_handling(003, envp));
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", old_pwd->value);
	else
		envp = ft_change_sto(envp, pwd, "PWD", old_pwd->value);
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
		return (ft_buildtin_cd_error_handling(004, envp));
	if (!pwd)
		envp = ft_new_sto(envp, "PWD", home->value);
	else
		envp = ft_change_sto(envp, pwd, "PWD", home->value);
	if (!old_pwd)
		envp = ft_new_sto(envp, "OLDPWD", cwd);
	else
		envp = ft_change_sto(envp, old_pwd, "OLDPWD", cwd);
	chdir(home->value);
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
	else if (cmd_swp && access(cmd_swp->value, F_OK) == -1 &&
			ft_strcmp(cmd_swp->value, "-") != 0)
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
