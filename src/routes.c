/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:13:09 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/22 21:05:01 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void 	ft_lm_set_def_bfs_dist(t_lm *lm, int bfs, int dist)
{
	int i;
	i = 0;
	while (lm->rooms[i])
	{
		if (bfs == 1)
			lm->rooms[i]->bfs = -1;
		if (dist == 1)
			lm->rooms[i]->dist = -1;
		i++;
	}
}

void 	ft_lm_set_def_vis_ofv(t_lm *lm, int vis, int ofv)
{
	int i;
	i = 0;
	while (lm->rooms[i])
	{
		if (vis == 1)
			lm->rooms[i]->vis = -1;
		if (ofv == 1)
			lm->rooms[i]->only_from_vis = -1;
		i++;
	}
}


// int ft_lm_get_opt_rev(t_lm *lm, t_room *from_room)
// {
// 	int i;
// 	t_room *opt_room;

// 	i = 0;
// 	opt_room = from_room;
// 	while (lm->mtx[from_room->i][i])
// 	{
// 		if (lm->mtx[i][from_room->i] == '+' &&
// 			lm->rooms[i]->dist != -1 && lm->rooms[i]->dist < opt_room->dist)
// 			opt_room = lm->rooms[i];
// 		i++;
// 	}
// 	return (opt_room->i == from_room->i ? -1 : opt_room->i);
// }

int ft_lm_get_opt_rev(t_lm *lm, int only_from_vis, t_room *from_room)
{
	int i;
	t_room *opt_room;

	i = 0;
	opt_room = from_room;
	while (lm->mtx[from_room->i][i]) 
	{
		if (lm->mtx[i][from_room->i] == '+' && lm->rooms[i]->dist != -1 && lm->rooms[i]->dist < opt_room->dist &&
			(only_from_vis ? !(from_room->vis == -1  && lm->rooms[i]->only_from_vis == 1) : 1))
			opt_room = lm->rooms[i];
		i++;
	}
	return (opt_room->i == from_room->i ? -1 : opt_room->i);
}


int ft_lm_get_only_vis_rev(t_lm *lm, t_room *from_room)
{
	int i;
	int only_from_vis;

	i = 0;
	only_from_vis = -1;
	while (lm->mtx[from_room->i][i])
	{
		
		if (lm->mtx[i][from_room->i] == '+' && lm->rooms[i]->dist != -1 &&
			lm->rooms[i]->vis != -1 && lm->rooms[i]->only_from_vis == -1 &&
			(only_from_vis == -1 || lm->rooms[i]->dist < lm->rooms[only_from_vis]->dist))
				only_from_vis = i;
		i++;
	}
	
	return (only_from_vis);
}

t_route		*ft_lm_get_route(t_lm *lm, int only_from_vis, t_room *start, t_room *end)
{
	t_route *route;
	t_room	*room_cur;
	int		next_i;

	if ((route = (t_route*)malloc(sizeof(t_route))) == NULL)
		return (NULL);
	route->len = 0;
	route->ants = 0;
	route->rooms = NULL;
	room_cur = end;
	while (room_cur->i != start->i)
	{
		next_i = ft_lm_get_opt_rev(lm, only_from_vis, room_cur);
		if (next_i == -1)
			next_i = ft_lm_get_only_vis_rev(lm, room_cur);
		if (next_i == -1)
			next_i = ft_lm_get_opt_rev(lm, 0, room_cur);
		if (next_i == -1)
			return (NULL);///////////!!!!!!!!!!!!!!!
		if (room_cur->i != start->i && room_cur->i != end->i)
			room_cur->vis = room_cur->vis == -1 ? 1 : room_cur->vis + 1;
		ft_lst_push_front_data(&route->rooms, (void*)(room_cur = lm->rooms[next_i]));
		route->len++;
	}
	ft_lst_push_back_data(&route->rooms, (void*)end);
	return (route);
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


// t_lst 	*ft_lm_get_routes(t_lm *lm, int no_vis, int close_rev)
// {
// 	t_lst	*routes;
// 	t_route	*route_cur;

// 	route_cur = (t_route*)(routes = NULL);
// 	while (42)
// 	{
// 		if (route_cur && close_rev)
// 			ft_lm_set_rooms_s_e(lm, route_cur->rooms, '-');
// 		ft_lm_bfs(lm, no_vis, lm->room_start, lm->room_end);
// 		route_cur = ft_lm_get_route(lm, lm->room_start, lm->room_end);
// 		ft_lst_push_back_data(&routes, (void*)route_cur);
// 		if (route_cur == NULL || (route_cur && route_cur->len == 1) || route_cur->len > 100)
// 			break ;
// 	}
// 	return (routes);
// }


t_lst 	*ft_lm_get_routes(t_lm *lm, int no_vis, int close_rev, int only_from_vis, int nn)
{
	t_lst	*routes;
	t_route	*route_cur;

	route_cur = (t_route*)(routes = NULL);
	while (42)
	{
		if (route_cur && close_rev)
			ft_lm_set_rooms_s_e(lm, route_cur->rooms, '-');
		ft_lm_bfs(lm, no_vis, lm->room_start, lm->room_end, nn);
		route_cur = ft_lm_get_route(lm, only_from_vis, lm->room_start, lm->room_end);
		ft_lst_push_back_data(&routes, (void*)route_cur);
		if (route_cur == NULL || (route_cur && route_cur->len == 1) || route_cur->len > 80)
			break ;
	}
	return (routes);
}

int 	ft_lm_set_routes(t_lm *lm)
{
	t_lst *tmp_routes;

	tmp_routes = NULL;
	lm->routes_a = ft_lm_get_routes(lm, 1, 0, 0, 0);
	ft_lm_set_def_bfs_dist(lm, 1, 1);
	ft_lm_set_def_vis_ofv(lm, 1, 1);
	tmp_routes = ft_lm_get_routes(lm, 0, 1, 1, 1);
	//ft_lst_iter(tmp_routes, ff_print_routes);
	ft_lm_open_routes_s_e(lm, tmp_routes);
	ft_lm_close_cross(lm);
	
	ft_lm_set_def_vis_ofv(lm, 1, 0);
	
	// printf("from 1 to 2 %c\n", lm->mtx[1][2]);
	// printf("from 2 to 1 %c\n", lm->mtx[2][1]);
	lm->routes_b = ft_lm_get_routes(lm, 1, 0, 1, 0);
	print_lm(lm);
	return (1);
}

