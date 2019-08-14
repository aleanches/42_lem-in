/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:47:25 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/14 17:41:25 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void	print_route(void *data)
{
	printf("name = %s\n", ((t_room*)data)->name);
}

void print_lm(t_lm *lm)
{
	int i;

	i = 0;
	while (i <= lm->rooms_c && i < MAX_ROOMS)
	{
		if (lm->rooms[i])
			printf ("name = %s | i = %i | x = %i | dest = %i | visit = %i\n", lm->rooms[i]->name, lm->rooms[i]->i, lm->rooms[i]->i, lm->rooms[i]->dist, lm->rooms[i]->vis);
		i++;
	}
	printf("\n");
	printf("rooms_c = %i\n", lm->rooms_c);
	printf("ants_c = %i\n\n", lm->ants_c);

	if (lm->room_start)
		printf ("room_start = %s | i = %i | dest = %i | visit = %i\n", lm->room_start->name, lm->room_start->i, lm->room_start->dist, lm->room_start->vis);
	else
		printf("NULL\n");

	if (lm->room_end)
		printf ("room_end = %s | i = %i | dest = %i | visit = %i\n", lm->room_end->name, lm->room_end->i, lm->room_end->dist, lm->room_end->vis);
	else
		printf("NULL\n\n");

	i = 0;
	// while (lm->mtx[i])
	// {
	// 	printf("%s\n", lm->mtx[i]);
	// 	i++;
	// }
}
