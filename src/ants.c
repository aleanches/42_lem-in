/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/24 18:32:14 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int ft_lm_put_ants(t_lm *lm, t_lst *routes)
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
					break;
			}
			begin = begin->next;
		}
		begin = routes;
		sum++;
	}
	return(ROUTE(routes)->ants + ROUTE(routes)->len);
}


int	ft_lm_ant_move(t_lm *lm, int ant)
{
	if (lm->ants[ant]->room_cur && lm->ants[ant]->room_cur->next)
	{
		lm->ants[ant]->room_cur = lm->ants[ant]->room_cur->next;
		printf("L%i-%s ", lm->ants[ant]->ant_n, ROOM(lm->ants[ant]->room_cur)->name);
		return (1);
	}
	return (0);
}

int	ft_lm_ants_move(t_lm *lm)
{
	int i;
	int ant_move;

	i = 0;
	ant_move = 0;
	while (i < lm->ants_c)
	{
		ant_move += ft_lm_ant_move(lm, i);
		i++;
	}
	return (ant_move);
}

void	ft_lm_ant_put(t_lm *lm, int ant, t_lst *route)
{
	lm->ants[ant]->room_cur = route;
}

void 	ft_lm_ants_run(t_lm *lm, t_lst *routes)
{
	t_lst *route_cur;

	while (42)
	{
		route_cur = routes;
		while (route_cur)
		{
			if (lm->ants_on_route_c < lm->ants_c)
			{
				ft_lm_ant_put(lm, lm->ants_on_route_c, ROUTE(route_cur)->rooms);
				lm->ants_on_route_c++;
			}
			route_cur = route_cur->next;
		}
		if (ft_lm_ants_move(lm) == 0)
			break;
		printf("\n");
	}
}

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


