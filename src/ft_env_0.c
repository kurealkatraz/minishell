/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:01:20 by mgras             #+#    #+#             */
/*   Updated: 2016/01/29 13:02:10 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_shell_lvls_import(t_sto *envp)
{
	t_sto	*swp;
	int		swp_value;

	swp = envp;
	swp_value = 0;
	while (swp != NULL && 0 != ft_strcmp(swp->name, "SHLVL"))
		swp = swp->next;
	if (swp == NULL)
		return (envp = ft_new_sto(envp, "SHLVL", "1"));
	swp_value = ft_atoi(swp->value) + 1;
	ft_strdel(&(swp->value));
	swp->value = ft_itoa(swp_value);
	return (envp);
}

char	*ft_env_value(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (ft_strsub(str, i + 1, ft_strlen(str)));
}

char	*ft_env_name(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (ft_strndup(str, i));
}

t_sto	*ft_import_native_envp(t_sto *envp, char **native_envp)
{
	int		i;
	char	*name_tmp;
	char	*value_tmp;

	i = 0;
	envp = NULL;
	name_tmp = NULL;
	value_tmp = NULL;
	while (native_envp[i])
		i++;
	while (--i > 0)
	{
		name_tmp = ft_env_name(native_envp[i]);
		value_tmp = ft_env_value(native_envp[i]);
		envp = ft_new_sto(envp, name_tmp, value_tmp);
		ft_strdel(&name_tmp);
		ft_strdel(&value_tmp);
	}
	return (envp);
}
