/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/24 22:29:43 by Alexandr         ###   ########.fr       */
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
	(*lm)->ants = NULL;
	ft_bzero((void*)(*lm)->rooms, sizeof(t_room*) * (MAX_ROOMS + 1));
	(*lm)->room_start = NULL;
	(*lm)->room_end = NULL;
	(*lm)->mtx = NULL;
	(*lm)->routes_a = NULL;
	(*lm)->routes_b = NULL;
	(*lm)->input = NULL;
}


void 	ff_print_route(void  *data)
{
	printf("%s\n", ((t_room*)data)->name);
}

void 	ff_print_routes(void  *data)
{
	printf("len = %i | ants = %i\n", ((t_route*)data)->len, ((t_route*)data)->ants);
	// ft_lst_iter(((t_route*)data)->rooms, ff_print_route);
}


void 	print_ants(t_lm *lm)
{
	int i = 0;

	while (lm->ants[i])
	{
		printf("%i |", (lm->ants[i])->ant_n);
		i++;
	}
	printf("\n");
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
	ft_lm_set_routes(lm);


	int a;
	int b;

	if ((a = ft_lm_ants_calc_on_routs(lm, lm->routes_a)) <= (b = ft_lm_ants_calc_on_routs(lm, lm->routes_b)))
	{
		// ft_lm_ants_run(lm, lm->routes_a);
		printf("-------------%i\n", a);
		ft_lst_iter(lm->routes_a, ff_print_routes);
	}
		
	else
	{
		// ft_lm_ants_run(lm, lm->routes_b);
		printf("-------------%i\n", b);
		ft_lst_iter(lm->routes_b, ff_print_routes);
	}
		
	

	

	// // ft_lm_get_routes_sr(lm);

	// print_ants(lm);
	
	// printf("-------------%i\n", ft_lm_ants_calc_on_routs(lm, lm->routes_a));
	// // ft_lst_iter(lm->routes_a, ff_print_routes);

	
	// printf("-------------%i\n", ft_lm_ants_calc_on_routs(lm, lm->routes_b));
	// ft_lst_iter(lm->routes_b, ff_print_routes);
	// ft_lm_ants_run(lm, lm->routes_b);


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
