/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/09/01 13:44:02 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		init(t_lm **lm)
{
	if (((*lm) = (t_lm*)malloc(sizeof(t_lm))) == NULL)
		put_error(lm, 1);
	(*lm)->ants_c = 0;
	(*lm)->rooms_c = 0;
	(*lm)->con_c = 0;
	(*lm)->ants = NULL;
	ft_bzero((void*)(*lm)->rooms, sizeof(t_room*) * (MAX_ROOMS + 1));
	(*lm)->room_start = NULL;
	(*lm)->room_end = NULL;
	(*lm)->mtx = NULL;
	(*lm)->routes_a = NULL;
	(*lm)->routes_b = NULL;
	(*lm)->input = NULL;
}

static int	lm_free(t_lm **lm, int ret_val)
{
	if (*lm == NULL)
		return (ret_val);
	free_ants((*lm)->ants);
	free_rooms((*lm)->rooms);
	ft_array_free(&((*lm)->mtx), 0);
	free_routes(&(*lm)->routes_a, 0);
	free_routes(&(*lm)->routes_b, 0);
	free_input(&(*lm)->input, 0);
	free(*lm);
	(*lm) = NULL;
	return (ret_val);
}

void		put_error(t_lm **lm, int ret_val)
{
	ft_putstr("ERROR\n");
	exit(lm_free(lm, ret_val));
}

static void	input_print(t_lm *lm)
{
	t_lst *begin;

	begin = lm->input;
	while (begin)
	{
		ft_putstr((char*)begin->data);
		ft_putchar('\n');
		begin = begin->next;
	}
	ft_putchar('\n');
}

int			main(void)
{
	t_lm *lm;

	init(&lm);
	parse_input(&lm);
	if (lm->input == NULL || lm->mtx == NULL || lm->rooms_c == 0)
		put_error(&lm, 1);
	if (routes_set(lm) == 0)
		put_error(&lm, 1);
	input_print(lm);
	if (ants_calc_on_routs(lm, lm->routes_a) <=
		ants_calc_on_routs(lm, lm->routes_b))
		ants_run(lm, lm->routes_a);
	else
		ants_run(lm, lm->routes_b);
	return (lm_free(&lm, 0));
}
