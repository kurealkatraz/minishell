/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:18:00 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:58:56 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef struct		s_sto
{
	char			*name;
	char			*value;
	struct s_sto	*prev;
	struct s_sto	*next;
}					t_sto;

/*
**	ft_env_0.c
*/
t_sto				*ft_shell_lvls_import(t_sto *envp);
t_sto				*ft_import_native_envp(t_sto *envp, char **native_envp);
char				*ft_env_value(char *str);
char				*ft_env_name(char *str);

/*
**	ft_sto_manipulations.c
*/
void				ft_print_sto(t_sto *pr);
t_sto				*ft_new_sto(t_sto *old, char *name, char *value);
t_sto				*ft_free_one_sto(t_sto *del);
t_sto				*ft_free_sto_chain(t_sto *del);

/*
**	ft_input.c
*/
t_sto				*ft_lex_user_input(char *line, t_sto *input);
t_sto				*ft_input_core(t_sto *envp);

#endif
