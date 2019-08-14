/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/01 18:41:32 by Alexandr         ###   ########.fr       */
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
