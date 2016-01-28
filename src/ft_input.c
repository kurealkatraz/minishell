/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowife <nowife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:32:25 by mgras             #+#    #+#             */
/*   Updated: 2016/01/28 01:40:17 by nowife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_lex_user_input(char *line, t_sto *input)
{
	char	**line_split;
	char	*clean_line;
	char	*trim_line;
	int		i;

	i = 0;
	trim_line = ft_strtrim(line);
	clean_line = ft_clean_line(trim_line);
	line_split = ft_splitline(clean_line);
	ft_strdel(&trim_line);
	ft_strdel(&clean_line);
	while (line_split[i])
	{
		input = ft_new_sto(input, NULL, line_split[i]);
		ft_strdel(&(line_split[i]));
		i++;
	}
	free(line_split);
	return (ft_rev_sto(input));
}

t_sto	*ft_input_core(t_sto *envp)
{
	char	*line;
	t_sto	*input;

	input = NULL;
	ft_prompt_imput_field(envp);
	while (get_next_line(1, &line) > 0)
	{
		input = ft_lex_user_input(line, input);
		ft_print_sto(input);
		ft_strdel(&line);
		input = input == NULL ? NULL : ft_free_sto_chain(input);
		ft_prompt_imput_field(envp);
	}
	ft_strdel(&line);
	return (envp);
}
