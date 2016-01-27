/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sto_manipulations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:06:13 by mgras             #+#    #+#             */
/*   Updated: 2016/01/27 17:28:37 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_sto(t_sto *pr)
{
	t_sto	*swp;

	swp = pr;
	while (swp)
	{
		if (swp->name)
			ft_putstr(swp->name);
		if (swp->name && swp->value)
			ft_putchar('=');
		if (swp->value)
			ft_putstr(swp->value);
		ft_putchar('\n');
		swp = swp->next;
	}
}

t_sto	*ft_new_sto(t_sto *old, char *name, char *value)
{
	t_sto	*n;

	n = NULL;
	n = (t_sto*)malloc(sizeof(t_sto));
	n->next = old;
	n->prev = NULL;
	if (old)
		old->prev = n;
	n->name = ft_strdup(name);
	n->value = ft_strdup(value);
	return (n);
}

t_sto	*ft_free_one_sto(t_sto *del)
{
	if (del->name)
		ft_strdel(&(del->name));
	if (del->value)
		ft_strdel(&(del->value));
	free(del);
	del = NULL;
	return (del);
}

t_sto	*ft_free_sto_chain(t_sto *del)
{
	t_sto	*tmp;

	while (del)
	{
		tmp = del->next;
		del = ft_free_one_sto(del);
		del = tmp;
	}
	return (del);
}
