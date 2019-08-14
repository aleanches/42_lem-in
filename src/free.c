/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:53:15 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/10 14:25:28 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

static void	ft_lm_rooms_free(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		ft_str_free(&(rooms[i]->name), 0);
		free(rooms[i]);
		rooms[i] = NULL;
		i++;
	}
}

int	ft_lm_free(t_lm **lm, int ret_val)
{
	if (*lm == NULL)
		return (ret_val);
	ft_lm_rooms_free((*lm)->rooms);
	ft_array_free(&((*lm)->mtx), 0);
	free(*lm);
	(*lm) = NULL;
	return (ret_val);
}