/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:18:00 by mgras             #+#    #+#             */
/*   Updated: 2016/01/29 19:26:43 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "colors.h"
# include <sys/types.h>
# include <dirent.h>

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
**	ft_sto_manipulation.c
*/
void				ft_print_sto(t_sto *pr);
t_sto				*ft_sto_find_name(t_sto *o, char *name);
t_sto				*ft_new_sto(t_sto *old, char *name, char *value);
t_sto				*ft_free_one_sto(t_sto *del);
t_sto				*ft_free_sto_chain(t_sto *del);

/*
**	ft_sto_manipulation_1
*/
t_sto				*ft_rev_sto(t_sto *lst);
t_sto				*ft_del_one_sto(t_sto *del);

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

/*
**	ft_spliter.c
*/
int					ft_get_tab_size(char *line);
int					ft_get_next_mark(char *line, int pos);
char				**ft_splitline(char *line);

/*
**	ft_parse.c
*/
int					ft_get_operation_index(t_sto *cmd);
t_sto				*ft_get_next_cmd(t_sto *input, t_sto *cmd);
t_sto				*ft_parse_core(t_sto *input, t_sto *envp, int *exit);

/*
**	ft_utility_0.c
*/
int					ft_get_sto_len(t_sto *sto);
int					ft_is_special_character(char c);
int					ft_is_special_separator(char *s);
int					ft_is_complex_subcmd(t_sto *subcmd);
char				**ft_sto_to_tab(t_sto *sto);

/*
**	ft_cmd.c
*/
t_sto				*ft_get_next_sub_cmd(t_sto *input, t_sto *cmd);
t_sto				*ft_cmd_call(t_sto *cmd, t_sto *envp);

/*
**	ft_buildtin_env.c
*/
int					ft_check_one_envp(t_sto *cmd);
t_sto				*ft_print_envp(t_sto *cmd, t_sto *envp);
t_sto				*ft_buildtin_env(t_sto *cmd, t_sto *envp);

/*
**	ft_exec_cmd.c
*/
char				*ft_get_next_dir_path(char *path, int *ss);
char				*ft_seek_path_list(char *cmd, char *path);
char				*ft_get_exec_path(char *cmd, t_sto *envp);
t_sto				*ft_exec_subcmd(char *cmd, t_sto *arg, t_sto *evp);

/*
**	ft_native_cmd_call.c
*/
t_sto				*ft_native_cmd_call(t_sto *cmd, t_sto *envp);

/*
**	ft_buildtin_unsetenv.c
*/
t_sto				*ft_buildtin_unsetenv(t_sto *cmd, t_sto *envp);

/*
**	ft_buildtin_setenv.c
*/
t_sto				*ft_buildtin_setenv(t_sto *cmd, t_sto *envp);

/*
**	ft_buildtin_cd.c
*/
t_sto				*ft_buildtin_cd_error_handling(int err_nb, t_sto *envp);
t_sto				*ft_buildtin_cd(t_sto *cmd, t_sto *envp);

#endif
