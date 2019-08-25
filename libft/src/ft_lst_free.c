/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:22:58 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:09 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_free(t_lst **lst, void (*free_data)(void **data), int ret_val)
{
	t_lst	*next;

	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->next = NULL;
		free_data(&((*lst)->data));
		free(*lst);
		*lst = next;
	}
	return (ret_val);
}
