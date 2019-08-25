/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 20:28:18 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		ft_lm_init(t_lm **lm)
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

static int	ft_lm_free(t_lm **lm, int ret_val)
{
	if (*lm == NULL)
		return (ret_val);
	ft_lm_free_ants((*lm)->ants);
	ft_lm_free_rooms((*lm)->rooms);
	ft_array_free(&((*lm)->mtx), 0);
	ft_lm_free_routes(&(*lm)->routes_a, 0);
	ft_lm_free_routes(&(*lm)->routes_b, 0);
	ft_lm_free_input(&(*lm)->input, 0);
	free(*lm);
	(*lm) = NULL;
	return (ret_val);
}

void		ft_lm_put_error(t_lm **lm, int ret_val)
{
	ft_putstr("ERROR\n");
	exit(ft_lm_free(lm, ret_val));
}

static void	ft_lm_input_print(t_lm *lm)
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

	ft_lm_init(&lm);
	ft_lm_parse_input(&lm);
	if (lm->input == NULL)
		ft_lm_put_error(&lm, 1);
	if (ft_lm_routes_set(lm) == 0)
		ft_lm_put_error(&lm, 1);
	ft_lm_input_print(lm);
	if (ft_lm_ants_calc_on_routs(lm, lm->routes_a) <=
		ft_lm_ants_calc_on_routs(lm, lm->routes_b))
		ft_lm_ants_run(lm, lm->routes_a);
	else
		ft_lm_ants_run(lm, lm->routes_b);
	return (ft_lm_free(&lm, 0));
}
