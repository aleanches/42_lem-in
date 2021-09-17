/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:37:09 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/26 18:13:21 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void	bfs_push_next_nodes(t_lm *lm, int no_vis,
										t_lst **st, t_room *room)
{
	int		i;

	i = 0;
	while (lm->mtx[room->i][i])
	{
		if (lm->mtx[room->i][i] == '+' && lm->rooms[i]->bfs == -1 &&
			(no_vis ? lm->rooms[i]->vis == -1 : 1) &&
			room_find_by_i(*st, i) == -1)
			ft_lst_push_front_data(st, (void*)(lm->rooms[i]));
		i++;
	}
}

static int	bfs_check_last(t_lst **st_cur, t_lst **st_next, int dist)
{
	if (*st_cur == NULL)
	{
		*st_cur = *st_next;
		*st_next = NULL;
		return (dist + 1);
	}
	return (dist);
}

int			bfs(t_lm *lm, int no_vis, t_room *start, t_room *end)
{
	t_lst	*st_cur;
	t_lst	*st_next;
	t_room	*room_cur;
	int		dist;

	st_cur = NULL;
	st_next = NULL;
	room_cur = NULL;
	set_def(lm, dist = 0, 1, 1);
	ft_lst_push_front_data(&st_cur, (void*)start);
	while (st_cur)
	{
		room_cur = (t_room*)ft_lst_pop_back_data(&st_cur);
		if (room_cur->bfs == -1)
		{
			room_cur->bfs = 1;
			room_cur->dist = dist;
			bfs_push_next_nodes(lm, no_vis, &st_next, room_cur);
		}
		if (room_cur->i == end->i)
			return (free_route(&st_cur, free_route(&st_next, 1)));
		dist = bfs_check_last(&st_cur, &st_next, dist);
	}
	return (0);
}
