/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:45 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:38 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_pop_back(t_lst **lst)
{
	t_lst	*pre_last;
	t_lst	*last;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->next == NULL)
	{
		last = *lst;
		*lst = NULL;
		return (last);
	}
	pre_last = *lst;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	return (last);
}
