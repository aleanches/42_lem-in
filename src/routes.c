/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:13:09 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/25 20:28:46 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		get_opt_rev(t_lm *lm, t_room *from_room)
{
	int		i;
	t_room	*opt_room;

	i = 0;
	opt_room = from_room;
	while (lm->mtx[from_room->i][i])
	{
		if (lm->mtx[i][from_room->i] == '+' &&
			lm->rooms[i]->dist != -1 && lm->rooms[i]->dist < opt_room->dist)
			opt_room = lm->rooms[i];
		i++;
	}
	return (opt_room->i == from_room->i ? -1 : opt_room->i);
}

static t_route	*route_get(t_lm *lm, t_room *start, t_room *end)
{
	t_route *route;
	t_room	*room_cur;
	int		next_i;

	if (get_opt_rev(lm, end) == -1 ||
		(route = (t_route*)malloc(sizeof(t_route))) == NULL)
		return (NULL);
	route->ants = 0;
	route->len = 0;
	route->rooms = NULL;
	room_cur = end;
	while (room_cur->i != start->i)
	{
		next_i = get_opt_rev(lm, room_cur);
		if (room_cur->i != start->i && room_cur->i != end->i)
			room_cur->vis = room_cur->vis == -1 ? 1 : room_cur->vis + 1;
		ft_lst_push_front_data(&route->rooms,
								(void*)(room_cur = lm->rooms[next_i]));
		route->len++;
	}
	ft_lst_push_back_data(&route->rooms, (void*)end);
	return (route);
}

static t_lst	*routes_get(t_lm *lm, int no_vis, int close_rev)
{
	t_lst		*routes;
	t_route		*route_cur;
	int			routes_c;

	routes = NULL;
	route_cur = NULL;
	routes_c = 0;
	while (42)
	{
		if (route_cur && close_rev)
			route_s_e_set(lm, route_cur->rooms, '-');
		bfs(lm, no_vis, lm->room_start, lm->room_end);
		route_cur = route_get(lm, lm->room_start, lm->room_end);
		ft_lst_push_back_data(&routes, (void*)route_cur);
		if (route_cur == NULL || route_cur->len == 1 ||
			(route_cur->len > MAX_ROUTE_LEN || routes_c >= MAX_ROUTES_C))
			break ;
	}
	return (routes);
}

int				routes_set(t_lm *lm)
{
	t_lst *tmp_routes;

	tmp_routes = NULL;
	lm->routes_a = routes_get(lm, 1, 0);
	set_def(lm, 1, 1, 1);
	tmp_routes = routes_get(lm, 0, 1);
	routes_s_e_open(lm, tmp_routes);
	free_routes(&tmp_routes, 0);
	close_cross(lm);
	set_def(lm, 1, 0, 0);
	lm->routes_b = routes_get(lm, 1, 0);
	if (lm->routes_a == NULL && lm->routes_b == NULL)
		return (0);
	return (1);
}
