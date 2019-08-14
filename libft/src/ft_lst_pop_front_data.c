/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/01 18:30:50 by Alexandr         ###   ########.fr       */
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
