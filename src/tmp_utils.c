/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:47:25 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/16 16:27:07 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void 	ft_lm_close_route_all(t_lm *lm, t_lst *rooms)
{
	int i;

	while (rooms->next)
	{
		i = 0;
		if (lm->room_start->i == ROOM(rooms)->i)
		{
			lm->mtx[ROOM(rooms)->i][ROOM(rooms->next)->i] = '-';
		}
		else
		{
			while (lm->mtx[ROOM(rooms)->i][i])
			{
				lm->mtx[ROOM(rooms)->i][i] = '-';
				i++;
			}
		}
		rooms = rooms->next;
	}
}


void	print_route(void *data)
{
	printf("name = %s\n", ((t_room*)data)->name);
}

void print_lm(t_lm *lm)
{
	int i;

	i = 0;
	while (lm->rooms[i])
	{
		printf ("name = %s | i = %i | bfs = %i | dest = %i | visit = %i\n", lm->rooms[i]->name, lm->rooms[i]->i, lm->rooms[i]->bfs, lm->rooms[i]->dist, lm->rooms[i]->vis);
		i++;
	}
	printf("\n");
	printf("rooms_c = %i\n", lm->rooms_c);
	printf("ants_c = %i\n\n", lm->ants_c);

	if (lm->room_start)
		printf ("name = %s | i = %i | bfs = %i | dest = %i | visit = %i\n", lm->room_start->name, lm->room_start->i, lm->room_start->bfs, lm->room_start->dist, lm->room_start->vis);
	else
		printf("NULL\n");

	if (lm->room_end)
		printf ("name = %s | i = %i | bfs = %i | dest = %i | visit = %i\n", lm->room_end->name, lm->room_end->i, lm->room_end->bfs, lm->room_end->dist, lm->room_end->vis);
	else
		printf("NULL\n\n");

	i = 0;
	// while (lm->mtx[i])
	// {
	// 	printf("%s\n", lm->mtx[i]);
	// 	i++;
	// }
}
