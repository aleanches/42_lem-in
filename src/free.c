/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:53:15 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 20:28:15 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_lm_free_rooms(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms && rooms[i])
	{
		ft_str_free(&(rooms[i]->name), 0);
		free(rooms[i]);
		rooms[i] = NULL;
		i++;
	}
}

void	ft_lm_free_ants(t_ant **ants)
{
	int i;

	i = 0;
	while (ants && ants[i])
	{
		free(ants[i]);
		ants[i] = NULL;
		i++;
	}
	if (ants)
		free(ants);
}

int		ft_lm_free_route(t_lst **route, int ret_val)
{
	while (route && *route)
		ft_lst_pop_front_data(route);
	return (ret_val);
}

int		ft_lm_free_routes(t_lst **routes, int ret_val)
{
	t_route *begin;

	while (routes && *routes &&
			(t_route*)(begin = ft_lst_pop_front_data(routes)))
	{
		ft_lm_free_route(&(begin->rooms), ret_val);
		free(begin);
	}
	return (ret_val);
}

int		ft_lm_free_input(t_lst **input, int ret_val)
{
	char *begin;

	while (input && *input && (begin = (char*)ft_lst_pop_front_data(input)))
		ft_str_free(&begin, ret_val);
	return (ret_val);
}
