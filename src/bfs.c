/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:37:09 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/16 16:16:37 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"


void	ft_lm_push_next_nodes(t_lm *lm, int no_vis, t_lst **st, t_room *room)
{
	int i;

	i = 0;
	while (lm->mtx[room->i][i])
	{
		if (lm->mtx[room->i][i] == '+' && lm->rooms[i]->bfs == -1 &&
			(no_vis ? lm->rooms[i]->vis == -1 : 1) &&
			ft_lm_find_room_by_i(*st, i) == -1)
			ft_lst_push_front_data(st, (void*)(lm->rooms[i]));
		i++;
	}
}

int		ft_lm_bfs(t_lm *lm, int no_vis, t_room *start, t_room *end)
{
	t_lst	*st_cur;
	t_lst	*st_next;
	t_room	*room_cur;
	int		dist;
	int		is_last;

	room_cur = (t_room*)(st_next = (st_cur = NULL));
	is_last = (dist = 0);
	ft_lm_set_def(lm, 0, 1, 1);
	ft_lst_push_front_data(&st_cur, (void*)start);
	while (st_cur)
	{
		room_cur = (t_room*)ft_lst_pop_back_data(&st_cur);
		if (room_cur->bfs == -1)
		{
			room_cur->bfs = 1;
			room_cur->dist = dist;
			ft_lm_push_next_nodes(lm, no_vis, &st_next, room_cur);
		}
		if (room_cur->i == end->i)
			break;
		if (st_cur == NULL)
		{
			st_cur = st_next;
			st_next = NULL;
			dist++;
		}
	}
	return (0);
}