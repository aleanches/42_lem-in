/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/13 21:12:37 by vsanta           ###   ########.fr       */
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



	ft_lm_init(&lm);
	ft_lm_parse_input(&lm);
	
	ft_lm_get_routes_sr(&lm);

	ft_lm_close(lm);
	ft_lm_get_routes_eeee(&lm);
	
	// print_lm(lm);
	

	return (ft_lm_free(&lm, 0));
}