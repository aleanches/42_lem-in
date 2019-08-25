/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:23:56 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:57 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_pop_front(t_lst **lst)
{
	t_lst	*first;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->next == NULL)
	{
		first = *lst;
		*lst = NULL;
		return (first);
	}
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	return (first);
}
