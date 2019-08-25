/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:31 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:23:22 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_new(void *data)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(t_lst*))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
