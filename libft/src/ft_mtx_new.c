/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:37:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:27:11 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		**ft_mtx_new_row(unsigned int size, unsigned int y,
								void *(*f)(unsigned x, unsigned y))
{
	unsigned int	x;
	void			**row;

	x = 0;
	if ((row = (void**)malloc(sizeof(void*) * size + 1)) == NULL)
		return (NULL);
	while (x < size)
	{
		row[x] = f(x, y);
		x++;
	}
	row[x] = NULL;
	return (row);
}

void			***ft_mtx_new(unsigned int size,
								void *(*f)(unsigned x, unsigned y))
{
	unsigned int	y;
	void			***col;

	y = 0;
	if ((col = (void***)malloc(sizeof(void**) * size + 1)) == NULL)
		return (NULL);
	while (y < size)
	{
		if ((col[y] = ft_mtx_new_row(size, y, f)) == NULL)
			return (NULL);
		y++;
	}
	col[y] = NULL;
	return (col);
}
