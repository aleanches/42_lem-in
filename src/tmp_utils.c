/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:47:25 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/20 18:32:39 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void 	ft_lm_close_route_all(t_lm *lm, t_lst *rooms)
{
	int i;

	while (rooms->next)
	{
		i = 0;
		if (lm->room_start->i == ROOM(rooms)->i)
		{
			lm->mtx[ROOM(rooms)->i][ROOM(rooms->next)->i] = '-';
		}
		else
		{
			while (lm->mtx[ROOM(rooms)->i][i])
			{
				lm->mtx[ROOM(rooms)->i][i] = '-';
				i++;
			}
		}
		rooms = rooms->next;
	}
}


void	print_route(void *data)
{
	printf("name = %s\n", ((t_room*)data)->name);
}

void print_lm(t_lm *lm)
{
	int i;

	i = 0;
	while (lm->rooms[i])
	{
		printf ("name = %s | i = %i | bfs = %i | dest = %i | vis = %i | only_from_vis = %i\n", lm->rooms[i]->name, lm->rooms[i]->i, lm->rooms[i]->bfs, lm->rooms[i]->dist, lm->rooms[i]->vis, lm->rooms[i]->only_from_vis);
		i++;
	}
	printf("\n");
	printf("rooms_c = %i\n", lm->rooms_c);
	printf("ants_c = %i\n\n", lm->ants_c);

	if (lm->room_start)
		printf ("name = %s | i = %i | bfs = %i | dest = %i | visit = %i\n", lm->room_start->name, lm->room_start->i, lm->room_start->bfs, lm->room_start->dist, lm->room_start->vis);
	else
		printf("NULL\n");

	if (lm->room_end)
		printf ("name = %s | i = %i | bfs = %i | dest = %i | visit = %i\n", lm->room_end->name, lm->room_end->i, lm->room_end->bfs, lm->room_end->dist, lm->room_end->vis);
	else
		printf("NULL\n\n");

	i = 0;
	// while (lm->mtx[i])
	// {
	// 	printf("%s\n", lm->mtx[i]);
	// 	i++;
	// }
}

// t_lst 	*ft_lm_get_routes_sr(t_lm *lm)
// {
// 	t_lst	*routes;
// 	t_route	*route_cur;

// 	routes = NULL;
// 	route_cur = NULL;
// 	while (42)
// 	{
// 		if (route_cur)
// 			ft_lm_set_rooms_s_e(lm, route_cur->rooms, '-');
// 		ft_lm_bfs(lm, 0, lm->room_start, lm->room_end);
// 		route_cur = ft_lm_get_route(lm, lm->room_start, lm->room_end);
// 		ft_lst_push_front_data(&routes, (void*)route_cur);
// 		if (route_cur == NULL)
// 			break ;
// 	}
// 	ft_lm_open_routes_s_e(lm, routes);
// 	ft_lm_close_cross(lm);
// 	ft_lm_set_def(lm, 1, 0, 0);
// 	ft_lm_bfs(lm, 1, lm->room_start, lm->room_end);
// 	route_cur =  ft_lm_get_route(lm, lm->room_start, lm->room_end);

// 	while (route_cur)
// 	{
// 		printf("----------len = %i\n", route_cur ? route_cur->len : 0);
// 		// ft_lst_iter(route_cur->rooms, print_route);
// 		// ft_lm_close_route_all(*lm, route_cur->rooms);
// 		ft_lm_bfs(lm, 1, lm->room_start, lm->room_end);
// 		route_cur =  ft_lm_get_route(lm, lm->room_start, lm->room_end);
// 	}

// 	// print_lm(*lm);

// 		// printf("----------len = %i\n", route_cur ? route_cur->len : 0);
// 		// ft_lst_iter(route_cur->rooms, print_route);
// 	return (routes);
// }
