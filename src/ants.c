/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/24 22:05:12 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

t_ant 	*ft_lm_ant_new(ant_n)
{
	t_ant *ant;

	if 	((ant = (t_ant*)malloc(sizeof(t_ant))) == NULL)
		return (NULL);
	ant->ant_n = ant_n;
	ant->room_cur = NULL;
	return (ant);
}

t_ant 	**ft_lm_ants_new(t_lm **lm)
{
	int i;
	t_ant **ants;

	i = 0;
	if ((ants = (t_ant**)malloc(sizeof(t_ant) * ((*lm)->ants_c + 1))) == NULL)
		ft_lm_put_error(lm, 1);
	ants[(*lm)->ants_c] = NULL;
	while (i < (*lm)->ants_c)
	{
		if ((ants[i] = ft_lm_ant_new(i + 1)) == NULL)
			ft_lm_put_error(lm, 1);
		i++;
	}
	return (ants);
}

int ft_lm_ants_calc_on_routs(t_lm *lm, t_lst *routes)
{
	int ants;
	int sum;
	t_lst *begin;

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
	return(ROUTE(routes)->ants + ROUTE(routes)->len - 1);
}
static void	ft_lm_ants_move_print(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->ant_n);
	ft_putchar('-');
	ft_putstr(ROOM(ant->room_cur)->name);
	ft_putchar(' ');
}

static int	ft_lm_ants_move(t_lm *lm)
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

void 	ft_lm_ants_run(t_lm *lm, t_lst *routes)
{
	t_lst *route_cur;
	int ants_on_route_c;

	ants_on_route_c = 0;
	while (42)
	{
		route_cur = routes;
		while (route_cur && ROUTE(route_cur)->ants > 0 && ants_on_route_c < lm->ants_c)
		{
			lm->ants[ants_on_route_c]->room_cur = ROUTE(route_cur)->rooms;
			ants_on_route_c++;
			ROUTE(route_cur)->ants--;
			route_cur = route_cur->next;
		}
		if (ft_lm_ants_move(lm) == 0)
			break;
		ft_putchar('\n');
	}
}
