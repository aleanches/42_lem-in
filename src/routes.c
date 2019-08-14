/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:13:09 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/14 20:12:23 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"


void 	ft_lm_set_def_vis(t_lm *lm)
{
	int i;
	i = 0;
	while (lm->rooms[i])
	{
		lm->rooms[i]->vis = -1;
		i++;
	}
}

void 	ft_lm_set_def_dist(t_lm *lm)
{
	int i;
	i = 0;
	while (lm->rooms[i])
	{
		lm->rooms[i]->dist = -1;
		i++;
	}
}

int ft_lm_get_opt_rev(t_lm *lm, t_room *from_room)
{
	int i;
	t_room *opt_room;

	i = 0;
	opt_room = from_room;
	while (lm->mtx[from_room->i][i])
	{
		if (lm->mtx[i][from_room->i] == '+' && lm->rooms[i]->dist != -1 && lm->rooms[i]->dist < opt_room->dist)
			opt_room = lm->rooms[i];
		i++;
	}
	return (opt_room->i == from_room->i ? -1 : opt_room->i);
}

t_route		*ft_lm_get_route(t_lm **lm, t_room *start, t_room *end)
{
	t_route *route;
	t_room	*room_cur;
	int		next_i;

	route->rooms = NULL;
	route->len = 0;
	room_cur = end;
	while (room_cur->i != start->i)
	{
		next_i = ft_lm_get_opt_rev(*lm, room_cur);
		if (next_i == -1)
			return (NULL);///////////!!!!!!!!!!!!!!!
		if (room_cur->i != start->i && room_cur->i != end->i)
			room_cur->vis = room_cur->vis == -1 ? 1 : room_cur->vis++;
		ft_lst_push_front_data(&route->rooms, (void*)(room_cur = (*lm)->rooms[next_i]));

		route->len++;
	}
	ft_lst_push_back_data(&route->rooms, (void*)end);
	return (route);
}

void 	ft_lm_set_route_s_e(t_lm *lm, t_lst *route, char c)
{
	while (route->next)
	{
		lm->mtx[ROOM(route)->i][ROOM(route->next)->i] = c;
		route = route->next;
	}
}

void 	ft_lm_open_routes_s_e(t_lm *lm, t_lst *routes)
{
	while (routes)
	{
		ft_lm_set_route_s_e(lm, ((t_route*)(routes->data))->rooms, '+');
		routes = routes->next;
	}
}

void 	ft_lm_close_route_all(t_lm *lm, t_lst *route)
{
	int i;

	while (route->next)
	{
		i = 0;
		if (lm->room_start->i == ROOM(route)->i)
		{
			lm->mtx[ROOM(route)->i][ROOM(route->next)->i] = '-';
		}
		else
		{
			while (lm->mtx[ROOM(route)->i][i])
			{
				lm->mtx[ROOM(route)->i][i] = '-';
				i++;
			}
		}
		route = route->next;
	}
}

// void 	ft_lm_close_cross(t_lm *lm)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (lm->rooms[i])
// 	{
// 		j = 0;
// 		while (lm->mtx[i][j])
// 		{
// 			if (lm->mtx[i][j] == '+' && lm->rooms[i]->x > 1 && lm->rooms[j]->x > 1)
// 				lm->mtx[i][j] = '-';
// 			j++;
// 		}
// 		i++;
// 	}
// }


t_lst 	*ft_lm_get_routes_sr(t_lm **lm)
{
	t_lst	*routes;
	t_route	*route_cur;

	int i;

	i = 40;


	// ft_lm_route_s_e(lm, w1->rooms, '+');
	// ft_lm_set_def_rooms_val(lm);
	// ft_lm_bfs(lm, lm->room_start);
	// w3 = ft_lm_get_route(lm, lm->room_start, lm->room_end);
	// printf("len = %i\n", w3->len);
	// ft_lst_iter(w3->rooms, print_route);

	// while (i)
	// {
	// 	ft_lm_bfs((*lm), (*lm)->room_start);
	// 		ft_lm_set_def_rooms_val((*lm));
	// 		i--;
	// }
		
	routes = NULL;
	ft_lm_set_def_vis(*lm);
	ft_lm_set_def_dist(*lm);
	
	ft_lm_bfs((*lm), (*lm)->room_start);
	
	
	ft_lm_set_def_vis(*lm);
	// ft_lm_set_def_dist(*lm);
	ft_lst_push_back_data(&routes, (void*)(route_cur = ft_lm_get_route(lm, (*lm)->room_start, (*lm)->room_end)));
	print_lm(*lm);
	while (route_cur)
	{
		printf("----------len = %i\n", route_cur ? route_cur->len : 0);
		ft_lst_iter(route_cur->rooms, print_route);

		ft_lm_close_route_all((*lm), route_cur->rooms);
		ft_lm_set_def_vis(*lm);
		ft_lm_set_def_dist(*lm);

		ft_lm_bfs((*lm), (*lm)->room_start);
		ft_lm_set_def_vis(*lm);
		print_lm(*lm);
		
		ft_lst_push_back_data(&routes, (void*)(route_cur = ft_lm_get_route(lm, (*lm)->room_start, (*lm)->room_end)));
	}
	return (routes);
}


t_lst 	*ft_lm_get_routes_eeee(t_lm **lm)
{
	t_lst	*routes;
	t_route	*route_cur;

	int i;

	i = 40;


	// ft_lm_route_s_e(lm, w1->rooms, '+');
	// ft_lm_set_def_rooms_val(lm);
	// ft_lm_bfs(lm, lm->room_start);
	// w3 = ft_lm_get_route(lm, lm->room_start, lm->room_end);
	// printf("len = %i\n", w3->len);
	// ft_lst_iter(w3->rooms, print_route);

	// while (i)
	// {
	// 	ft_lm_bfs((*lm), (*lm)->room_start);
	// 		ft_lm_set_def_rooms_val((*lm));
	// 		i--;
	// }
	routes = NULL;
	ft_lm_bfs((*lm), (*lm)->room_start);
	ft_lst_push_back_data(&routes, (void*)(route_cur = ft_lm_get_route(lm, (*lm)->room_start, (*lm)->room_end)));
	while (route_cur)
	{
		printf("----------len = %i\n", route_cur->len);
		ft_lst_iter(route_cur->rooms, print_route);
		// ft_lm_set_route_s_e((*lm), route_cur->rooms, '-');
		ft_lm_close_route_all((*lm), route_cur->rooms);
		ft_lm_bfs((*lm), (*lm)->room_start);
		ft_lst_push_back_data(&routes, (void*)(route_cur = ft_lm_get_route(lm, (*lm)->room_start, (*lm)->room_end)));
	}
	return (routes);
}