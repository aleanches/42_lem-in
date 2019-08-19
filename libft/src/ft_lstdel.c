/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 08:10:05 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/19 14:59:01 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
}
