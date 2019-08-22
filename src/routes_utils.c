/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:20:46 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/22 20:25:58 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void 	ft_lm_set_def(t_lm *lm, int vis, int bfs, int dist)
{
	int i;
	i = 0;
	while (lm->rooms[i])
	{
		if (vis == 1)
			lm->rooms[i]->vis = -1;
		if (bfs == 1)
			lm->rooms[i]->bfs = -1;
		if (dist == 1)
			lm->rooms[i]->dist = -1;
		i++;
	}
}

void 	ft_lm_set_rooms_s_e(t_lm *lm, t_lst *rooms, char c)
{
	while (rooms && rooms->next)
	{
		lm->mtx[ROOM(rooms)->i][ROOM(rooms->next)->i] = c;
		rooms = rooms->next;
	}
}

void 	ft_lm_open_routes_s_e(t_lm *lm, t_lst *routes)
{
	while (routes)
	{
		ft_lm_set_rooms_s_e(lm, ((t_route*)(routes->data))->rooms, '+');
		routes = routes->next;
	}
}

void 	ft_lm_close_cross(t_lm *lm)
{
	int i;
	int j;

	i = 0;
	while (lm->rooms[i])
	{
		j = 0;
		while (lm->mtx[i][j])
		{
			if (lm->mtx[i][j] == '+' &&
				lm->rooms[i]->vis > 1 && lm->rooms[j]->vis > 1)
				lm->mtx[i][j] = '-';
			j++;
		}
		i++;
	}
}