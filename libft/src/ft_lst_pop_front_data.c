/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:23:50 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:51 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_pop_front_data(t_lst **lst)
{
	t_lst	*first;
	void	*data;

	first = ft_lst_pop_front(lst);
	if (first == NULL)
		return (NULL);
	data = first->data;
	ft_memdel((void**)&first);
	return (data);
}
