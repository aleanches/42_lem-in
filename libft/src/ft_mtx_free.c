/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:45:07 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:30:30 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtx_free(void ****mtx, void (*f)(void **data))
{
	int x;
	int y;

	y = 0;
	if (mtx == NULL || *mtx == NULL)
		return ;
	while ((*mtx)[y])
	{
		x = 0;
		while ((*mtx)[y][x])
		{
			f(&((*mtx)[y][x]));
			x++;
		}
		free((*mtx)[y]);
		(*mtx)[y] = NULL;
		y++;
	}
	free((*mtx));
	(*mtx) = NULL;
}
