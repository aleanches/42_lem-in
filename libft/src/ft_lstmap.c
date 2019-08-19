/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:44:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/19 14:59:25 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst)
	{
		if (!(tmp = f(lst)))
			return (NULL);
		tmp->next = ft_lstmap(lst->next, f);
		return (tmp);
	}
	return (NULL);
}
