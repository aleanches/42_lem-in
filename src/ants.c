/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 20:28:05 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_ant			**ft_lm_ants_new(t_lm **lm)
{
	int		i;
	t_ant	**ants;

	i = 0;
	if ((ants = (t_ant**)malloc(sizeof(t_ant) * ((*lm)->ants_c + 1))) == NULL)
		ft_lm_put_error(lm, 1);
	ants[(*lm)->ants_c] = NULL;
	while (i < (*lm)->ants_c)
	{
		if ((ants[i] = (t_ant*)malloc(sizeof(t_ant))) == NULL)
			ft_lm_put_error(lm, 1);
		ants[i]->ant_n = i + 1;
		ants[i]->room_cur = NULL;
		i++;
	}
	return (ants);
}

int				ft_lm_ants_calc_on_routs(t_lm *lm, t_lst *routes)
{
	int		ants;
	int		sum;
	t_lst	*begin;

	ants = lm->ants_c;
	sum = 0;
	begin = routes;
	while (ants > 0)
	{
		while (begin)
		{
			if (sum > ROUTE(begin)->ants + ROUTE(begin)->len)
			{
				ants--;
				ROUTE(begin)->ants++;
				if (ants == 0)
					break ;
			}
			begin = begin->next;
		}
		begin = routes;
		sum++;
	}
	return (ROUTE(routes)->ants + ROUTE(routes)->len - 1);
}

static void		ft_lm_ants_move_print(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->ant_n);
	ft_putchar('-');
	ft_putstr(ROOM(ant->room_cur)->name);
	ft_putchar(' ');
}

static int		ft_lm_ants_move(t_lm *lm)
{
	int i;
	int ant_move;

	i = 0;
	ant_move = 0;
	while (i < lm->ants_c)
	{
		if (lm->ants[i]->room_cur && lm->ants[i]->room_cur->next)
		{
			lm->ants[i]->room_cur = lm->ants[i]->room_cur->next;
			ft_lm_ants_move_print(lm->ants[i]);
			ant_move++;
		}
		i++;
	}
	return (ant_move);
}

void			ft_lm_ants_run(t_lm *lm, t_lst *routes)
{
	t_lst	*route_cur;
	int		ants_on_routes_c;

	ants_on_routes_c = 0;
	while (42)
	{
		route_cur = routes;
		while (route_cur &&
				ROUTE(route_cur)->ants > 0 && ants_on_routes_c < lm->ants_c)
		{
			lm->ants[ants_on_routes_c]->room_cur = ROUTE(route_cur)->rooms;
			ants_on_routes_c++;
			ROUTE(route_cur)->ants--;
			route_cur = route_cur->next;
		}
		if (ft_lm_ants_move(lm) == 0)
			break ;
		ft_putchar('\n');
	}
}
