/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 00:26:50 by nowife            #+#    #+#             */
/*   Updated: 2016/01/31 15:11:11 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_next_dir_path(char *path, int *ss)
{
	int		ts;
	char	*ret;

	ts = *ss;
	if (!path[*ss])
		return (NULL);
	while (path[ts] && path[ts] != ':')
		ts++;
	ret = ft_strsub(path, *ss, ts - *ss);
	while (path[*ss] && path[*ss] != ':')
		*ss = *ss + 1;
	*ss = *ss + 1;
	return (ret);
}

char	*ft_seek_path_list(char *cmd, char *path)
{
	int				i;
	char			*open;
	char			*ret;
	DIR				*opnd;
	struct dirent	*dir;

	open = NULL;
	ret = NULL;
	i = 0;
	while ((open = ft_get_next_dir_path(path, &i)))
	{
		opnd = opendir(open);
		while (opnd && (dir = readdir(opnd)))
		{
			if (ft_strcmp(dir->d_name, cmd) == 0)
			{
				closedir(opnd);
				return (ft_strjoin(open, ft_strjoin("/", dir->d_name)));
			}
		}
		closedir(opnd);
		ft_strdel(&open);
	}
	return (NULL);
}

char	*ft_get_exec_path(char *cmd, t_sto *envp)
{
	int		i;
	t_sto	*path_list;

	i = 0;
	path_list = NULL;
	while (cmd[i])
		if (cmd[i++] == '/')
			return (cmd);
	path_list = ft_sto_find_name(envp, "PATH");
	if (!path_list)
	{
		ft_exec_error_handling(002, NULL, NULL);
		return (NULL);
	}
	return (ft_seek_path_list(cmd, path_list->value));
}

void	ft_exec_single(char *bin, char **argv, char **envp)
{
	pid_t	father;
	int		sys;

	father = fork();
	signal(SIGINT, ft_signal_parent_handler);
	if (!father)
	{
		signal(SIGINT, ft_signal_child_handler);
		execve(bin, argv, envp);
		kill(getpid(), SIGKILL);
	}
	else
		wait(&sys);
}

t_sto	*ft_exec_subcmd(char *cmd, t_sto *arg, t_sto *evp, t_sto *exec_envp)
{
	char	**envp;
	char	**argv;
	char	*path;

	if (!evp && !ft_get_exec_path(cmd, evp))
		return (ft_exec_error_handling(003, arg, evp));
	if (!(path = ft_get_exec_path(cmd, evp)))
	{
		ft_exec_error_handling(001, arg, evp);
		return (evp);
	}
	argv = ft_sto_to_tab(arg);
	envp = ft_sto_to_tab(exec_envp);
	ft_exec_single(path, argv, envp);
	return (evp);
}
