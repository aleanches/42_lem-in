/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/01 18:30:45 by Alexandr         ###   ########.fr       */
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