/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 00:26:50 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 15:47:21 by mgras            ###   ########.fr       */
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
		return (NULL);
	return (ft_seek_path_list(cmd, path_list->value));
}

void	ft_exec_single(char *bin, char **argv, char **envp)
{
	pid_t	child;
	int		sys;

	child = fork();
	if (child == 0)
	{
		execve(bin, argv, envp);
		kill(getpid(), SIGKILL);
	}
	else
		wait(&sys);
}

void	ft_print_char_tab(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		ft_putendl(argv[i++]);
}

t_sto	*ft_exec_subcmd(char *cmd, t_sto *arg, t_sto *evp)
{
	char	**envp;
	char	**argv;
	char	*path;

	if (!(path = ft_get_exec_path(cmd, evp)))
		return (evp);
	argv = ft_sto_to_tab(arg);
	envp = ft_sto_to_tab(evp);
	ft_exec_single(path, argv, envp);
	return (evp);
}
