/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sto_manipulation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 01:33:21 by nowife            #+#    #+#             */
/*   Updated: 2016/01/30 18:52:56 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_change_sto(t_sto *o, t_sto *del, char *n, char *v)
{
	if (v)
	{
		ft_strdel(&(del->value));
		del->value = ft_strdup(v);
	}
	if (n)
	{
		ft_strdel(&(del->name));
		del->name = ft_strdup(n);
	}
	return (o);
}

t_sto	*ft_rev_sto(t_sto *lst)
{
	t_sto	*n;
	t_sto	*swp;

	swp = lst;
	n = NULL;
	if (!lst)
		return (NULL);
	while (swp)
	{
		n = ft_new_sto(n, NULL, swp->value);
		swp = swp->next;
	}
	lst = ft_free_sto_chain(lst);
	return (n);
}

t_sto	*ft_del_one_sto(t_sto *del)
{
	t_sto	*p;
	t_sto	*n;

	if (!del)
		return (NULL);
	p = del->prev;
	n = del->next;
	del = ft_free_one_sto(del);
	if (p)
		p->next = n;
	if (n)
		n->prev = p;
	return (p);
}

t_sto	*ft_sto_join(t_sto *sto1, t_sto *sto2, t_sto *lim)
{
	t_sto	*n;
	t_sto	*swp1;
	t_sto	*swp2;

	n = NULL;
	swp1 = sto1;
	swp2 = sto2;
	while (swp1)
	{
		n = ft_new_sto(n, swp1->name, swp1->value);
		swp1 = swp1->next;
	}
	while (swp2 != lim)
	{
		if (ft_check_one_envp(swp2))
			n = ft_new_sto(n, ft_env_name(swp2->value), ft_env_value(swp2->value));
		swp2 = swp2->next;
	}
	return (ft_rev_sto(n));
}
