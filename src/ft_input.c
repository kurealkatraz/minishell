/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:32:25 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:59:43 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_lex_user_input(char *line, t_sto *input)
{
	char	**line_split;
	char	*clean_line;
	int		i;

	i = 0;
	clean_line = ft_strtrim(line);
	line_split = ft_strsplit(clean_line, ' ');
	ft_strdel(&clean_line);
	while (line_split[i])
	{
		input = ft_new_sto(input, NULL, line_split[i]);
		ft_strdel(&(line_split[i]));
		i++;
	}
	free(line_split);
	return (input);
}

t_sto	*ft_input_core(t_sto *envp)
{
	char	*line;
	t_sto	*input;

	input = NULL;
	while (get_next_line(1, &line) > 0)
	{
		input = ft_lex_user_input(line, input);
		input = input == NULL ? NULL : ft_free_sto_chain(input);
		ft_strdel(&line);
	}
	return (envp);
}
