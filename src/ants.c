/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/22 20:12:17 by vsanta           ###   ########.fr       */
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

int ft_lm_set_count_ants(char **line, t_lm **lm)
{
	int count;
	if ((*line)[0] && (*line)[0] == '#')
		return (10);
	count = ft_atoi((*line));
	if (count == 0 || ft_is_valid_int(count, (*line)) == 0)
		ft_lm_put_error(lm, 10);
	(*lm)->ants_c = count;
	return (20);
}
