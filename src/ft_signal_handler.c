/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:57:20 by mgras             #+#    #+#             */
/*   Updated: 2016/01/31 15:14:49 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_child_handler(int sig_nb)
{
	ft_putendl("GOT THA SIGNAL CHILD");
	exit(sig_nb);
}

void	ft_signal_parent_handler(int sig_nb)
{
	ft_putendl("\nChild was killed by Ctrl-C, returning to minishell");
	sig_nb = sig_nb + 0;
	return ;
}
