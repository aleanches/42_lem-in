/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:37:09 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/13 19:58:23 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"


int		ft_lm_push_next_nodes(t_lm *lm, t_lst **st, t_room *room)
{
	int i;

	i = 0;
	while (lm->mtx[room->i][i])
	{
		if (lm->mtx[room->i][i] == '+' && lm->rooms[i]->vis == -1)
			ft_lst_push_front_data(st, (void*)(lm->rooms[i]));
		i++;
	}
	return (i);
}

int		ft_lm_bfs(t_lm *lm, t_room *start)
{
	t_lst *st_cur;
	t_lst *st_next;
	t_room	*room_cur;
	int dist;

	st_cur = NULL;
	st_next = NULL;
	room_cur = NULL;
	dist = 0;
	ft_lst_push_front_data(&st_cur, (void*)start);
	while (st_cur)
	{
		room_cur = (t_room*)ft_lst_pop_back_data(&st_cur);
		room_cur->vis = 1;
		room_cur->dist = dist;
		ft_lm_push_next_nodes(lm, &st_next, room_cur);
		if (st_cur == NULL)
		{
			st_cur = st_next;
			st_next = NULL;
			dist++;
		}
	}
	return (0);
}