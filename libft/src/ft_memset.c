/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:26:10 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:26:12 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char*)buf;
	i = 0;
	while (i < count)
	{
		tmp[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
