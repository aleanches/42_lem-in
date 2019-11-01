/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:31 by vsanta            #+#    #+#             */
/*   Updated: 2019/11/01 19:05:09 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_new(void *data)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
