/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:37:09 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 20:28:08 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void	ft_lm_bfs_push_next_nodes(t_lm *lm, int no_vis,
										t_lst **st, t_room *room)
{
	int	i;

	i = 0;
	while (lm->mtx[room->i][i])
	{
		if (lm->mtx[room->i][i] == '+' && lm->rooms[i]->bfs == -1 &&
			(no_vis ? lm->rooms[i]->vis == -1 : 1) &&
			ft_lm_room_find_by_i(*st, i) == -1)
			ft_lst_push_front_data(st, (void*)(lm->rooms[i]));
		i++;
	}
}

int			ft_lm_bfs(t_lm *lm, int no_vis, t_room *start, t_room *end)
{
	t_lst	*st_cur;
	t_lst	*st_next;
	t_room	*room_cur;
	int		dist;

	st_cur = NULL;
	st_next = NULL;
	room_cur = NULL;
	ft_lm_set_def(lm, dist = 0, 1, 1);
	ft_lst_push_front_data(&st_cur, (void*)start);
	while (st_cur)
	{
		room_cur = (t_room*)ft_lst_pop_back_data(&st_cur);
		if (room_cur->bfs == -1)
		{
			room_cur->bfs = 1;
			room_cur->dist = dist;
			ft_lm_bfs_push_next_nodes(lm, no_vis, &st_next, room_cur);
		}
		if (room_cur->i == end->i)
			return (ft_lm_free_route(&st_cur, ft_lm_free_route(&st_next, 1)));
		if (st_cur == NULL)
		{
			st_cur = st_next;
			st_next = NULL;
			dist++;
		}
	}
	return (0);
}
