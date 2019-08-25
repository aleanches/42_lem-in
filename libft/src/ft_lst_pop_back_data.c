/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:29 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_pop_back_data(t_lst **lst)
{
	t_lst	*last;
	void	*data;

	last = ft_lst_pop_back(lst);
	if (last == NULL)
		return (NULL);
	data = last->data;
	ft_memdel((void**)&last);
	return (data);
}
