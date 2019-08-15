/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/15 18:44:27 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"


	// int				ants_c;
	// int				rooms_c;
	// t_room			*rooms[MAX_ROOMS + 1];
	// t_room			*room_start;
	// t_room			*room_end;
	// t_lst			*routes;
	// char			**mtx;

void 	ft_lm_init(t_lm **lm)
{
	if (((*lm) = (t_lm*)malloc(sizeof(t_lm))) == NULL)
		ft_lm_put_error(lm, 1);
	(*lm)->ants_c = 0;
	(*lm)->rooms_c = 0;
	ft_bzero((void*)(*lm)->rooms, sizeof(t_room*) * MAX_ROOMS);
	(*lm)->room_start = NULL;
	(*lm)->room_end = NULL;
	(*lm)->mtx = NULL;
	(*lm)->routes = NULL;
}

int main()
{
	t_lm *lm;

	t_route *w1;
	t_route *w2;
	t_route *w3;

	w1 = NULL;
	w2 = NULL;
	w3 = NULL;

	int i = 100;



	ft_lm_init(&lm);
	ft_lm_parse_input(&lm);
	


	ft_lm_get_routes_sr(&lm);

	// ft_lm_get_routes_sr(&lm);

	// ft_lm_bfs(lm, 1, lm->room_start, lm->room_end);
	// print_lm(lm);

	// while (i)
	// {
	// 	ft_lm_set_def_dfs(lm);
	// 	ft_lm_bfs(lm, lm->room_start, lm->room_end);
	// 	i--;
	// }
	
	

	// ft_lm_close(lm);
	// ft_lm_get_routes_eeee(&lm);
	// ft_lm_bfs(lm, 1, lm->room_start, lm->room_end);
	// print_lm(lm);
	

	return (ft_lm_free(&lm, 0));
}