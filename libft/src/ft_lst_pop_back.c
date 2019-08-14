/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/01 17:37:34 by Alexandr         ###   ########.fr       */
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
		return(last);
	}
	pre_last = *lst;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	return(last);
}