/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:46:02 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/19 14:59:33 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

void		ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = tmp;
}
