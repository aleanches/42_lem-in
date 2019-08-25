/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:24:06 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:24:08 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_push_back_data(t_lst **lst, void *data)
{
	t_lst *new;

	if (data == NULL)
		return (NULL);
	if ((new = ft_lst_new(data)) == NULL)
		return (NULL);
	ft_lst_push_back(lst, new);
	return (*lst);
}
