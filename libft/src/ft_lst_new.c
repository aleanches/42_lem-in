/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:10 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/31 15:55:08 by Alexandr         ###   ########.fr       */
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
