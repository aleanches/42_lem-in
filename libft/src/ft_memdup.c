/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:25:55 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:25:57 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *data, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if ((res = malloc(sizeof(char) * size)))
	{
		while (i < size)
		{
			((char *)res)[i] = ((char *)data)[i];
			i++;
		}
		return (res);
	}
	return (NULL);
}
