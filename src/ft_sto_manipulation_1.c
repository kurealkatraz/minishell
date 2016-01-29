/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sto_manipulation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 01:33:21 by nowife            #+#    #+#             */
/*   Updated: 2016/01/29 19:47:24 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sto	*ft_change_sto(t_sto *o, t_sto *del, char *n, char *v)
{
	ft_del_one_sto(del);
	o = ft_new_sto(o, n, v);
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
