/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:32:25 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:52:59 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_sto	*ft_lex_user_input(char *line, t_sto *input)
{
	char	**line_split;
	char	*clean_line;
	int		i;

	i = 0;
	clean_line = ft_strtrim(line);
	line_split = ft_strsplit(clean_line);
	ft_strdel(&clean_line);
	while (line_split[i])
	{
		input = ft_new_sto()
		ft_strdel(line_split[i]);
		i++;
	}
}

t_sto	*ft_input_core(t_sto *envp)
{
	char	*line;
	t_sto	*input;
	int		fd;

	fd = open(1, O_RDONLY);
	input = NULL;
	while (get_next_line(fd, &line))
	{
		input = ft_lex_user_input(line, input);
		input = input == NULL ? NULL : ft_free_sto_chain(input);
		ft_strdel(&line);
	}
	return (envp);
}
