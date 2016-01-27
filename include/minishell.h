/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:18:00 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 21:56:36 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "colors.h"

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
t_sto				*ft_sto_find_name(t_sto *o, char *name);
t_sto				*ft_new_sto(t_sto *old, char *name, char *value);
t_sto				*ft_free_one_sto(t_sto *del);
t_sto				*ft_free_sto_chain(t_sto *del);

/*
**	ft_input.c
*/
t_sto				*ft_lex_user_input(char *line, t_sto *input);
t_sto				*ft_input_core(t_sto *envp);

/*
**	ft_cleaner.c
*/
int					ft_get_c_len(char *line);
char				*ft_strclcpy(char *dst, char *src);
char				*ft_clean_line(char *line);

/*
**	ft_colors.c
*/
void				ft_prompt_name(t_sto *envp);
void				ft_prompt_tree(void);
void				ft_prompt_imput_field(t_sto *envp);

#endif
