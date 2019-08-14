/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:39 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/01 18:31:42 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_push_front_data(t_lst **lst, void *data)
{
	t_lst *new;

	if (data == NULL)
		return (NULL);
	if ((new = ft_lst_new(data)) == NULL)
		return (NULL);
	ft_lst_push_front(lst, new);
	return (*lst);
}
