/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:11:32 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/19 14:59:05 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

void	ft_lstdelnode(t_list **lst, t_list *node)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == node)
	{
		*lst = node->next;
		free(node->content);
		free(node);
		return ;
	}
	while (tmp)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			free(node->content);
			free(node);
			return ;
		}
		tmp = tmp->next;
	}
}
