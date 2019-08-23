/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/23 20:22:51 by vsanta           ###   ########.fr       */
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
int ft_lm_get_last_free_ant(t_lm *lm)
{
	int i;

	i = 0;
	while (lm->ants[i])
	{
		if (lm->ants[i]->room_cur == NULL)
			return (i);
		i++;
	}
	return (-1);
}


void	ft_lm_ant_move(t_lm *lm, t_lst *route)
{
	
}

void 	ft_lm_ants_run(t_lm *lm, t_lst *routes)
{
	t_lst *route_cur;

	route_cur = routes;
	while (42)
	{

		if (ROUTE(route_cur)->ants == 0 || route_cur->next == NULL)
			route_cur = routes;
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


